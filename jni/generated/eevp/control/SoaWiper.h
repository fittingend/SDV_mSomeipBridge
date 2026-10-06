// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_WIPER_H
#define MSOMEIP_SOA_WIPER_H
#include <map>
#include <msomeip/MSomeIp.h>
#include <msomeip/serde/Deserialize.h>
#include <msomeip/serde/Serialize.h>
#include <vector>
namespace Eevp::Control::SoaWiper {
enum class SoaDeviceIsNormal : uint8_t { kNORMAL = 0, kABNORMAL = 1 };
enum class SoaWiperMode : uint8_t {
  kOFF = 0,
  kINT1 = 1,
  kINT2 = 2,
  kINT3 = 3,
  kON = 4
};
enum class SoaMfswInt : uint8_t {
  kINT1 = 0,
  kINT2 = 1,
  kINT3 = 2,
  kINT4 = 3,
  kINT5 = 4,
  kUNKNOWN = 5
};
enum class SoaMfswMist : uint8_t { kOFF = 0, kON = 1, kUNKNOWN = 2 };
enum class SoaMfswWasher : uint8_t { kOFF = 0, kON = 1, kUNKNOWN = 2 };
enum class SoaMfswWiper : uint8_t {
  kOFF = 0,
  kINT = 1,
  kLOW = 2,
  kHIGH = 3,
  kUNKNOWN = 4
};
struct SoaWiferMfsw : public msomeip::serde::Serializable {
  SoaMfswWiper wiper_sw;
  SoaMfswWasher washer_sw;
  SoaMfswInt int_sw;
  SoaMfswMist mist_sw;

  auto tie() { return std::tie(wiper_sw, washer_sw, int_sw, mist_sw); }
  auto tie() const { return std::tie(wiper_sw, washer_sw, int_sw, mist_sw); }
  constexpr static msomeip::serde::LengthFieldSize LENGTH_FIELDS_SIZE =
      msomeip::serde::LengthFieldSize::None;
};
struct SoaWiperStatus : public msomeip::serde::Serializable {
  bool is_auto_mode;
  SoaWiperMode mode;

  auto tie() { return std::tie(is_auto_mode, mode); }
  auto tie() const { return std::tie(is_auto_mode, mode); }
  constexpr static msomeip::serde::LengthFieldSize LENGTH_FIELDS_SIZE =
      msomeip::serde::LengthFieldSize::None;
};
template <typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
std::string to_string(T value) {

  if constexpr (std::is_same_v<T, SoaDeviceIsNormal>) {
    switch (value) {
    case SoaDeviceIsNormal::kNORMAL:
      return "kNORMAL";
    case SoaDeviceIsNormal::kABNORMAL:
      return "kABNORMAL";
    }
  }
  if constexpr (std::is_same_v<T, SoaWiperMode>) {
    switch (value) {
    case SoaWiperMode::kOFF:
      return "kOFF";
    case SoaWiperMode::kINT1:
      return "kINT1";
    case SoaWiperMode::kINT2:
      return "kINT2";
    case SoaWiperMode::kINT3:
      return "kINT3";
    case SoaWiperMode::kON:
      return "kON";
    }
  }
  if constexpr (std::is_same_v<T, SoaMfswInt>) {
    switch (value) {
    case SoaMfswInt::kINT1:
      return "kINT1";
    case SoaMfswInt::kINT2:
      return "kINT2";
    case SoaMfswInt::kINT3:
      return "kINT3";
    case SoaMfswInt::kINT4:
      return "kINT4";
    case SoaMfswInt::kINT5:
      return "kINT5";
    case SoaMfswInt::kUNKNOWN:
      return "kUNKNOWN";
    }
  }
  if constexpr (std::is_same_v<T, SoaMfswMist>) {
    switch (value) {
    case SoaMfswMist::kOFF:
      return "kOFF";
    case SoaMfswMist::kON:
      return "kON";
    case SoaMfswMist::kUNKNOWN:
      return "kUNKNOWN";
    }
  }
  if constexpr (std::is_same_v<T, SoaMfswWasher>) {
    switch (value) {
    case SoaMfswWasher::kOFF:
      return "kOFF";
    case SoaMfswWasher::kON:
      return "kON";
    case SoaMfswWasher::kUNKNOWN:
      return "kUNKNOWN";
    }
  }
  if constexpr (std::is_same_v<T, SoaMfswWiper>) {
    switch (value) {
    case SoaMfswWiper::kOFF:
      return "kOFF";
    case SoaMfswWiper::kINT:
      return "kINT";
    case SoaMfswWiper::kLOW:
      return "kLOW";
    case SoaMfswWiper::kHIGH:
      return "kHIGH";
    case SoaMfswWiper::kUNKNOWN:
      return "kUNKNOWN";
    }
  }
  return "Unknown Enum Type";
}
template <typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
std::ostream &operator<<(std::ostream &os, T value) {
  os << to_string(value);
  return os;
}
const msomeip::MajorVersion MAJOR_VERSION = 1;
const msomeip::MinorVersion MINOR_VERSION = 0;
const msomeip::ServiceId SERVICE_ID = 4949;
const msomeip::InstanceId INSTANCE_ID = 4965;
constexpr const char *DEPLOYMENT_META_DATA = R"(
Service:
  InstanceId: Eevp.Control.Provider_SoaWiper
  SomeIpInstanceID: 4965
Interface:
  SomeIpServiceID: 4949
  attributes:
    soaWiperDeviceNormal:
      SomeIpGetterID: 1
      SomeIpSetterID: null
      SomeIpNotifierID: 49153
      SomeIpGetterReliable: false
      SomeIpSetterReliable: false
      SomeIpNotifierReliable: false
      SomeIpNotifierEventGroups:
      - 8705
      SomeIpAttributeEndianess: be
      SomeIpAttributeCRCWidth: zero
    soaWiperMfsw:
      SomeIpGetterID: 4
      SomeIpSetterID: null
      SomeIpNotifierID: 49156
      SomeIpGetterReliable: false
      SomeIpSetterReliable: false
      SomeIpNotifierReliable: false
      SomeIpNotifierEventGroups:
      - 8708
      SomeIpAttributeEndianess: be
      SomeIpAttributeCRCWidth: zero
    soaWiperStatus:
      SomeIpGetterID: 2
      SomeIpSetterID: null
      SomeIpNotifierID: 49154
      SomeIpGetterReliable: false
      SomeIpSetterReliable: false
      SomeIpNotifierReliable: false
      SomeIpNotifierEventGroups:
      - 8706
      SomeIpAttributeEndianess: be
      SomeIpAttributeCRCWidth: zero
    soaWiperSwVersion:
      SomeIpGetterID: 3
      SomeIpSetterID: null
      SomeIpNotifierID: 49155
      SomeIpGetterReliable: false
      SomeIpSetterReliable: false
      SomeIpNotifierReliable: false
      SomeIpNotifierEventGroups:
      - 8707
      SomeIpAttributeEndianess: be
      SomeIpAttributeCRCWidth: zero
  methods:
    RequestWiperOperation:
      SomeIpReliable: null
      SomeIpMethodID: 16386
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestWiperOperationExt:
      SomeIpReliable: null
      SomeIpMethodID: 16418
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetWiperAutoSpeed:
      SomeIpReliable: null
      SomeIpMethodID: 16385
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetWiperAutoSpeedExt:
      SomeIpReliable: null
      SomeIpMethodID: 16417
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    StartExtJob_Wiper:
      SomeIpReliable: null
      SomeIpMethodID: 16401
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    StopExtJob_Wiper:
      SomeIpReliable: null
      SomeIpMethodID: 16402
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
  broadcasts: null
  arrays: null
  structs:
    SoaWiferMfsw:
      SomeIpStructLengthWidth: 0
    SoaWiperStatus:
      SomeIpStructLengthWidth: 0
  version:
    major: 1
    minor: 0

)";
} // namespace Eevp::Control::SoaWiper
#endif