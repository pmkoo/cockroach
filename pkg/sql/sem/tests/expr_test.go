// Copyright 2015 The Cockroach Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the License.

package tests

import (
	"reflect"
	"testing"

	"golang.org/x/net/context"

	"github.com/cockroachdb/cockroach/pkg/sql/parser"
	_ "github.com/cockroachdb/cockroach/pkg/sql/sem/builtins"
	"github.com/cockroachdb/cockroach/pkg/sql/sem/tree"
	"github.com/cockroachdb/cockroach/pkg/sql/sem/types"
	"github.com/cockroachdb/cockroach/pkg/testutils"
)

// TestUnresolvedNameString tests the string representation of tree.UnresolvedName and thus tree.Name.
func TestUnresolvedNameString(t *testing.T) {
	testCases := []struct {
		in, out string
	}{
		{"*", `"*"`},
		// Non-reserved keyword.
		{"DATABASE", `"DATABASE"`},
		{"dAtAbAse", `"dAtAbAse"`},
		// Reserved keyword.
		{"SELECT", `"SELECT"`},
		{"sElEcT", `"sElEcT"`},
		// Ident format: starts with [a-zA-Z_] or extended ascii,
		// and is then followed by [a-zA-Z0-9$_] or extended ascii.
		{"foo$09", "foo$09"},
		{"_Ab10", `"_Ab10"`},
		// Everything else quotes the string and escapes double quotes.
		{".foobar", `".foobar"`},
		{`".foobar"`, `""".foobar"""`},
		{`\".foobar\"`, `"\"".foobar\"""`},
	}

	for _, tc := range testCases {
		q := tree.UnresolvedName{tree.Name(tc.in)}
		if q.String() != tc.out {
			t.Errorf("expected q.String() == %q, got %q", tc.out, q.String())
		}
	}
}

func TestNormalizeNameInExpr(t *testing.T) {
	testCases := []struct {
		in, out string
		err     string
	}{
		{`foo`, `foo`, ``},
		{`*`, `*`, ``},
		{`foo.bar`, `foo.bar`, ``},
		{`foo.*`, `foo.*`, ``},
		{`test.foo.*`, `test.foo.*`, ``},
		{`foo.bar[blah]`, `foo.bar`, ``},
		{`foo[bar]`, `foo`, ``},
		{`test.*[foo]`, `test.*`, ``},

		{`"".foo`, ``, `empty table name`},
		{`"".*`, ``, `empty table name`},
		{`""`, ``, `empty column name`},
		{`foo.*.bar`, ``, `invalid table name: "foo.*"`},
		{`foo.*.bar[baz]`, ``, `invalid table name: "foo.*"`},
		{`test.foo.*.bar[foo]`, ``, `invalid table name: "test.foo.*"`},
	}

	for _, tc := range testCases {
		stmt, err := parser.ParseOne("SELECT " + tc.in)
		if err != nil {
			t.Fatalf("%s: %v", tc.in, err)
		}
		var vBase tree.VarName
		startExpr := stmt.(*tree.Select).Select.(*tree.SelectClause).Exprs[0].Expr
		for {
			switch e := startExpr.(type) {
			case tree.VarName:
				vBase = e
			case *tree.IndirectionExpr:
				startExpr = e.Expr
				continue
			default:
				t.Fatalf("%s does not parse to a tree.VarName or tree.IndirectionExpr", tc.in)
			}
			break
		}
		v, err := vBase.NormalizeVarName()
		if tc.err != "" {
			if !testutils.IsError(err, tc.err) {
				t.Fatalf("%s: expected %s, but found %v", tc.in, tc.err, err)
			}
			continue
		}
		if err != nil {
			t.Fatalf("%s: expected success, but found %v", tc.in, err)
		}
		if out := v.String(); tc.out != out {
			t.Errorf("%s: expected %s, but found %s", tc.in, tc.out, out)
		}
	}
}

// TestExprString verifies that converting an expression to a string and back
// doesn't change the (normalized) expression.
func TestExprString(t *testing.T) {
	defer tree.MockNameTypes(map[string]types.T{
		"a": types.Bool,
		"b": types.Bool,
		"c": types.Bool,
		"d": types.Bool,
		"e": types.Bool,
		"f": types.Int,
		"g": types.Int,
		"h": types.Int,
		"i": types.Int,
		"j": types.Int,
		"k": types.Int,
	})()
	testExprs := []string{
		`a AND b`,
		`a AND b OR c`,
		`(a AND b) OR c`,
		`a AND (b OR c)`,
		`a AND NOT ((b OR c) AND (d AND e))`,
		`~-f`,
		`-2*(f+3)*g`,
		`f&g<<(g+h)&i > 0 AND (g&i)+h>>(i&f) > 0`,
		`f&(g<<g+h)&i > 0 AND g&(i+h>>i)&f > 0`,
		`f = g|h`,
		`f != g|h`,
		`NOT a AND b`,
		`NOT (a AND b)`,
		`(NOT a) AND b`,
		`NOT (a = NOT b = c)`,
		`NOT NOT a = b`,
		`NOT NOT (a = b)`,
		`NOT (NOT a) < b`,
		`NOT (NOT a = b)`,
		`(NOT NOT a) >= b`,
		`(a OR (g BETWEEN (h+i) AND (j+k))) AND b`,
		`(1 >= 2) IS OF (BOOL)`,
		`(1 >= 2) = (2 IS OF (BOOL))`,
		`count(1) FILTER (WHERE true)`,
	}
	for _, exprStr := range testExprs {
		expr, err := parser.ParseExpr(exprStr)
		if err != nil {
			t.Fatalf("%s: %v", exprStr, err)
		}
		typedExpr, err := tree.TypeCheck(expr, nil, types.Any)
		if err != nil {
			t.Fatalf("%s: %v", expr, err)
		}
		// str may differ than exprStr (we may be adding some parens).
		str := typedExpr.String()
		expr2, err := parser.ParseExpr(str)
		if err != nil {
			t.Fatalf("%s: %v", exprStr, err)
		}
		typedExpr2, err := tree.TypeCheck(expr2, nil, types.Any)
		if err != nil {
			t.Fatalf("%s: %v", expr2, err)
		}
		// Verify that when we stringify the expression again, the string is the
		// same. This is important because we don't want cycles of parsing and
		// printing an expression to keep adding parens.
		if str2 := typedExpr2.String(); str != str2 {
			t.Errorf("Print/parse/print cycle changes the string: `%s` vs `%s`", str, str2)
		}
		// Compare the normalized expressions.
		ctx := tree.NewTestingEvalContext()
		defer ctx.Mon.Stop(context.Background())
		normalized, err := ctx.NormalizeExpr(typedExpr)
		if err != nil {
			t.Fatalf("%s: %v", exprStr, err)
		}
		normalized2, err := ctx.NormalizeExpr(typedExpr2)
		if err != nil {
			t.Fatalf("%s: %v", exprStr, err)
		}
		if !reflect.DeepEqual(tree.StripMemoizedFuncs(normalized), tree.StripMemoizedFuncs(normalized2)) {
			t.Errorf("normalized expressions differ\n"+
				"original:     %s\n"+
				"intermediate: %s\n"+
				"before: %#v\n"+
				"after:  %#v", exprStr, str, normalized, normalized2)
		}
	}
}

func TestStripParens(t *testing.T) {
	testExprs := []struct {
		in, out string
	}{
		{`1`, `1`},
		{`(1)`, `1`},
		{`((1))`, `1`},
		{`(1) + (2)`, `(1) + (2)`},
		{`((1) + (2))`, `(1) + (2)`},
	}
	for i, test := range testExprs {
		expr, err := parser.ParseExpr(test.in)
		if err != nil {
			t.Fatalf("%d: %v", i, err)
		}
		stripped := tree.StripParens(expr)
		if str := stripped.String(); str != test.out {
			t.Fatalf("%d: expected tree.StripParens(%s) = %s, but found %s", i, test.in, test.out, str)
		}
	}
}
