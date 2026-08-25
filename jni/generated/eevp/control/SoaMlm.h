// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_MLM_H
#define MSOMEIP_SOA_MLM_H
#include <map>
#include <msomeip/MSomeIp.h>
#include <msomeip/serde/Deserialize.h>
#include <msomeip/serde/Serialize.h>
#include <vector>
namespace Eevp::Control::SoaMlm {
enum class SoaMlmMoodMode : uint8_t {
  kCARE_MOOD = 0,
  kCOMPORT_MOOD = 1,
  kDELIGHT_MOOD = 2,
  kMOOD_THERAPHY = 3,
  kVITALITY_MOOD = 4
};
enum class SoaDeviceIsNormal : uint8_t { kNORMAL = 0, kABNORMAL = 1 };
struct SoaMlmStatus : public msomeip::serde::Serializable {
  uint8_t color_table_index;
  uint16_t brightness;
  SoaDeviceIsNormal is_normal;

  auto tie() { return std::tie(color_table_index, brightness, is_normal); }
  auto tie() const {
    return std::tie(color_table_index, brightness, is_normal);
  }
  constexpr static msomeip::serde::LengthFieldSize LENGTH_FIELDS_SIZE =
      msomeip::serde::LengthFieldSize::None;
};
template <typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
std::string to_string(T value) {

  if constexpr (std::is_same_v<T, SoaMlmMoodMode>) {
    switch (value) {
    case SoaMlmMoodMode::kCARE_MOOD:
      return "kCARE_MOOD";
    case SoaMlmMoodMode::kCOMPORT_MOOD:
      return "kCOMPORT_MOOD";
    case SoaMlmMoodMode::kDELIGHT_MOOD:
      return "kDELIGHT_MOOD";
    case SoaMlmMoodMode::kMOOD_THERAPHY:
      return "kMOOD_THERAPHY";
    case SoaMlmMoodMode::kVITALITY_MOOD:
      return "kVITALITY_MOOD";
    }
  }
  if constexpr (std::is_same_v<T, SoaDeviceIsNormal>) {
    switch (value) {
    case SoaDeviceIsNormal::kNORMAL:
      return "kNORMAL";
    case SoaDeviceIsNormal::kABNORMAL:
      return "kABNORMAL";
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
const msomeip::ServiceId SERVICE_ID = 4945;
const msomeip::InstanceId INSTANCE_ID = 4961;
constexpr const char *DEPLOYMENT_META_DATA = R"(
Service:
  InstanceId: Eevp.Control.Provider_SoaMlm
  SomeIpInstanceID: 4961
Interface:
  SomeIpServiceID: 4945
  attributes:
    soaMlmStatus:
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
    soaMlmSwVersion:
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
  methods:
    RequestMlmSetBrightness:
      SomeIpReliable: null
      SomeIpMethodID: 16387
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMlmSetBrightnessExt:
      SomeIpReliable: null
      SomeIpMethodID: 16419
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMlmSetMode:
      SomeIpReliable: null
      SomeIpMethodID: 16386
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMlmSetModeExt:
      SomeIpReliable: null
      SomeIpMethodID: 16418
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMlmSetRgbColor:
      SomeIpReliable: null
      SomeIpMethodID: 16385
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMlmSetRgbColorExt:
      SomeIpReliable: null
      SomeIpMethodID: 16417
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    StartExtJob_Mlm:
      SomeIpReliable: null
      SomeIpMethodID: 16401
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    StopExtJob_Mlm:
      SomeIpReliable: null
      SomeIpMethodID: 16402
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
  broadcasts: null
  arrays: null
  structs:
    SoaMlmStatus:
      SomeIpStructLengthWidth: 0
  version:
    major: 1
    minor: 0

)";
} // namespace Eevp::Control::SoaMlm
#endif