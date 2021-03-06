// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: storage/engine/enginepb/registry.proto

#ifndef PROTOBUF_storage_2fengine_2fenginepb_2fregistry_2eproto__INCLUDED
#define PROTOBUF_storage_2fengine_2fenginepb_2fregistry_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_util.h>
// @@protoc_insertion_point(includes)
namespace cockroach {
namespace storage {
namespace engine {
namespace enginepb {
class FileEntry;
class FileEntryDefaultTypeInternal;
extern FileEntryDefaultTypeInternal _FileEntry_default_instance_;
class Registry;
class RegistryDefaultTypeInternal;
extern RegistryDefaultTypeInternal _Registry_default_instance_;
}  // namespace enginepb
}  // namespace engine
}  // namespace storage
}  // namespace cockroach

namespace cockroach {
namespace storage {
namespace engine {
namespace enginepb {

namespace protobuf_storage_2fengine_2fenginepb_2fregistry_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_storage_2fengine_2fenginepb_2fregistry_2eproto

enum RegistryVersion {
  Base = 0,
  RegistryVersion_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  RegistryVersion_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool RegistryVersion_IsValid(int value);
const RegistryVersion RegistryVersion_MIN = Base;
const RegistryVersion RegistryVersion_MAX = Base;
const int RegistryVersion_ARRAYSIZE = RegistryVersion_MAX + 1;

enum EncryptionType {
  Plaintext = 0,
  AES_CTR = 1,
  EncryptionType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EncryptionType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EncryptionType_IsValid(int value);
const EncryptionType EncryptionType_MIN = Plaintext;
const EncryptionType EncryptionType_MAX = AES_CTR;
const int EncryptionType_ARRAYSIZE = EncryptionType_MAX + 1;

// ===================================================================

class Registry : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:cockroach.storage.engine.enginepb.Registry) */ {
 public:
  Registry();
  virtual ~Registry();

  Registry(const Registry& from);

  inline Registry& operator=(const Registry& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Registry(Registry&& from) noexcept
    : Registry() {
    *this = ::std::move(from);
  }

  inline Registry& operator=(Registry&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const Registry& default_instance();

  static inline const Registry* internal_default_instance() {
    return reinterpret_cast<const Registry*>(
               &_Registry_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Registry* other);
  friend void swap(Registry& a, Registry& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Registry* New() const PROTOBUF_FINAL { return New(NULL); }

  Registry* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const Registry& from);
  void MergeFrom(const Registry& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Registry* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .cockroach.storage.engine.enginepb.FileEntry files = 2;
  int files_size() const;
  void clear_files();
  static const int kFilesFieldNumber = 2;
  const ::cockroach::storage::engine::enginepb::FileEntry& files(int index) const;
  ::cockroach::storage::engine::enginepb::FileEntry* mutable_files(int index);
  ::cockroach::storage::engine::enginepb::FileEntry* add_files();
  ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::FileEntry >*
      mutable_files();
  const ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::FileEntry >&
      files() const;

  // .cockroach.storage.engine.enginepb.RegistryVersion version = 1;
  void clear_version();
  static const int kVersionFieldNumber = 1;
  ::cockroach::storage::engine::enginepb::RegistryVersion version() const;
  void set_version(::cockroach::storage::engine::enginepb::RegistryVersion value);

  // @@protoc_insertion_point(class_scope:cockroach.storage.engine.enginepb.Registry)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::FileEntry > files_;
  int version_;
  mutable int _cached_size_;
  friend struct protobuf_storage_2fengine_2fenginepb_2fregistry_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class FileEntry : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:cockroach.storage.engine.enginepb.FileEntry) */ {
 public:
  FileEntry();
  virtual ~FileEntry();

  FileEntry(const FileEntry& from);

  inline FileEntry& operator=(const FileEntry& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  FileEntry(FileEntry&& from) noexcept
    : FileEntry() {
    *this = ::std::move(from);
  }

  inline FileEntry& operator=(FileEntry&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const FileEntry& default_instance();

  static inline const FileEntry* internal_default_instance() {
    return reinterpret_cast<const FileEntry*>(
               &_FileEntry_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(FileEntry* other);
  friend void swap(FileEntry& a, FileEntry& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline FileEntry* New() const PROTOBUF_FINAL { return New(NULL); }

  FileEntry* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const FileEntry& from);
  void MergeFrom(const FileEntry& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(FileEntry* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string Filename = 1;
  void clear_filename();
  static const int kFilenameFieldNumber = 1;
  const ::std::string& filename() const;
  void set_filename(const ::std::string& value);
  #if LANG_CXX11
  void set_filename(::std::string&& value);
  #endif
  void set_filename(const char* value);
  void set_filename(const char* value, size_t size);
  ::std::string* mutable_filename();
  ::std::string* release_filename();
  void set_allocated_filename(::std::string* filename);

  // bytes key_id = 3;
  void clear_key_id();
  static const int kKeyIdFieldNumber = 3;
  const ::std::string& key_id() const;
  void set_key_id(const ::std::string& value);
  #if LANG_CXX11
  void set_key_id(::std::string&& value);
  #endif
  void set_key_id(const char* value);
  void set_key_id(const void* value, size_t size);
  ::std::string* mutable_key_id();
  ::std::string* release_key_id();
  void set_allocated_key_id(::std::string* key_id);

  // bytes nonce = 4;
  void clear_nonce();
  static const int kNonceFieldNumber = 4;
  const ::std::string& nonce() const;
  void set_nonce(const ::std::string& value);
  #if LANG_CXX11
  void set_nonce(::std::string&& value);
  #endif
  void set_nonce(const char* value);
  void set_nonce(const void* value, size_t size);
  ::std::string* mutable_nonce();
  ::std::string* release_nonce();
  void set_allocated_nonce(::std::string* nonce);

  // .cockroach.storage.engine.enginepb.EncryptionType type = 2;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::cockroach::storage::engine::enginepb::EncryptionType type() const;
  void set_type(::cockroach::storage::engine::enginepb::EncryptionType value);

  // uint32 counter = 5;
  void clear_counter();
  static const int kCounterFieldNumber = 5;
  ::google::protobuf::uint32 counter() const;
  void set_counter(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:cockroach.storage.engine.enginepb.FileEntry)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr filename_;
  ::google::protobuf::internal::ArenaStringPtr key_id_;
  ::google::protobuf::internal::ArenaStringPtr nonce_;
  int type_;
  ::google::protobuf::uint32 counter_;
  mutable int _cached_size_;
  friend struct protobuf_storage_2fengine_2fenginepb_2fregistry_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Registry

// .cockroach.storage.engine.enginepb.RegistryVersion version = 1;
inline void Registry::clear_version() {
  version_ = 0;
}
inline ::cockroach::storage::engine::enginepb::RegistryVersion Registry::version() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.Registry.version)
  return static_cast< ::cockroach::storage::engine::enginepb::RegistryVersion >(version_);
}
inline void Registry::set_version(::cockroach::storage::engine::enginepb::RegistryVersion value) {
  
  version_ = value;
  // @@protoc_insertion_point(field_set:cockroach.storage.engine.enginepb.Registry.version)
}

// repeated .cockroach.storage.engine.enginepb.FileEntry files = 2;
inline int Registry::files_size() const {
  return files_.size();
}
inline void Registry::clear_files() {
  files_.Clear();
}
inline const ::cockroach::storage::engine::enginepb::FileEntry& Registry::files(int index) const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.Registry.files)
  return files_.Get(index);
}
inline ::cockroach::storage::engine::enginepb::FileEntry* Registry::mutable_files(int index) {
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.Registry.files)
  return files_.Mutable(index);
}
inline ::cockroach::storage::engine::enginepb::FileEntry* Registry::add_files() {
  // @@protoc_insertion_point(field_add:cockroach.storage.engine.enginepb.Registry.files)
  return files_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::FileEntry >*
Registry::mutable_files() {
  // @@protoc_insertion_point(field_mutable_list:cockroach.storage.engine.enginepb.Registry.files)
  return &files_;
}
inline const ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::FileEntry >&
Registry::files() const {
  // @@protoc_insertion_point(field_list:cockroach.storage.engine.enginepb.Registry.files)
  return files_;
}

// -------------------------------------------------------------------

// FileEntry

// string Filename = 1;
inline void FileEntry::clear_filename() {
  filename_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& FileEntry::filename() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.FileEntry.Filename)
  return filename_.GetNoArena();
}
inline void FileEntry::set_filename(const ::std::string& value) {
  
  filename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cockroach.storage.engine.enginepb.FileEntry.Filename)
}
#if LANG_CXX11
inline void FileEntry::set_filename(::std::string&& value) {
  
  filename_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:cockroach.storage.engine.enginepb.FileEntry.Filename)
}
#endif
inline void FileEntry::set_filename(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  filename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cockroach.storage.engine.enginepb.FileEntry.Filename)
}
inline void FileEntry::set_filename(const char* value, size_t size) {
  
  filename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cockroach.storage.engine.enginepb.FileEntry.Filename)
}
inline ::std::string* FileEntry::mutable_filename() {
  
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.FileEntry.Filename)
  return filename_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FileEntry::release_filename() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.FileEntry.Filename)
  
  return filename_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FileEntry::set_allocated_filename(::std::string* filename) {
  if (filename != NULL) {
    
  } else {
    
  }
  filename_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), filename);
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.FileEntry.Filename)
}

// .cockroach.storage.engine.enginepb.EncryptionType type = 2;
inline void FileEntry::clear_type() {
  type_ = 0;
}
inline ::cockroach::storage::engine::enginepb::EncryptionType FileEntry::type() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.FileEntry.type)
  return static_cast< ::cockroach::storage::engine::enginepb::EncryptionType >(type_);
}
inline void FileEntry::set_type(::cockroach::storage::engine::enginepb::EncryptionType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:cockroach.storage.engine.enginepb.FileEntry.type)
}

// bytes key_id = 3;
inline void FileEntry::clear_key_id() {
  key_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& FileEntry::key_id() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.FileEntry.key_id)
  return key_id_.GetNoArena();
}
inline void FileEntry::set_key_id(const ::std::string& value) {
  
  key_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cockroach.storage.engine.enginepb.FileEntry.key_id)
}
#if LANG_CXX11
inline void FileEntry::set_key_id(::std::string&& value) {
  
  key_id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:cockroach.storage.engine.enginepb.FileEntry.key_id)
}
#endif
inline void FileEntry::set_key_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  key_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cockroach.storage.engine.enginepb.FileEntry.key_id)
}
inline void FileEntry::set_key_id(const void* value, size_t size) {
  
  key_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cockroach.storage.engine.enginepb.FileEntry.key_id)
}
inline ::std::string* FileEntry::mutable_key_id() {
  
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.FileEntry.key_id)
  return key_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FileEntry::release_key_id() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.FileEntry.key_id)
  
  return key_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FileEntry::set_allocated_key_id(::std::string* key_id) {
  if (key_id != NULL) {
    
  } else {
    
  }
  key_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), key_id);
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.FileEntry.key_id)
}

// bytes nonce = 4;
inline void FileEntry::clear_nonce() {
  nonce_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& FileEntry::nonce() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.FileEntry.nonce)
  return nonce_.GetNoArena();
}
inline void FileEntry::set_nonce(const ::std::string& value) {
  
  nonce_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cockroach.storage.engine.enginepb.FileEntry.nonce)
}
#if LANG_CXX11
inline void FileEntry::set_nonce(::std::string&& value) {
  
  nonce_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:cockroach.storage.engine.enginepb.FileEntry.nonce)
}
#endif
inline void FileEntry::set_nonce(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  nonce_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cockroach.storage.engine.enginepb.FileEntry.nonce)
}
inline void FileEntry::set_nonce(const void* value, size_t size) {
  
  nonce_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cockroach.storage.engine.enginepb.FileEntry.nonce)
}
inline ::std::string* FileEntry::mutable_nonce() {
  
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.FileEntry.nonce)
  return nonce_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* FileEntry::release_nonce() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.FileEntry.nonce)
  
  return nonce_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void FileEntry::set_allocated_nonce(::std::string* nonce) {
  if (nonce != NULL) {
    
  } else {
    
  }
  nonce_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), nonce);
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.FileEntry.nonce)
}

// uint32 counter = 5;
inline void FileEntry::clear_counter() {
  counter_ = 0u;
}
inline ::google::protobuf::uint32 FileEntry::counter() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.FileEntry.counter)
  return counter_;
}
inline void FileEntry::set_counter(::google::protobuf::uint32 value) {
  
  counter_ = value;
  // @@protoc_insertion_point(field_set:cockroach.storage.engine.enginepb.FileEntry.counter)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace enginepb
}  // namespace engine
}  // namespace storage
}  // namespace cockroach

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::cockroach::storage::engine::enginepb::RegistryVersion> : ::google::protobuf::internal::true_type {};
template <> struct is_proto_enum< ::cockroach::storage::engine::enginepb::EncryptionType> : ::google::protobuf::internal::true_type {};

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_storage_2fengine_2fenginepb_2fregistry_2eproto__INCLUDED
