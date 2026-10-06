// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_SMART_FILM_H
#define MSOMEIP_SOA_SMART_FILM_H
#include <map>
#include <msomeip/MSomeIp.h>
#include <msomeip/serde/Deserialize.h>
#include <msomeip/serde/Serialize.h>
#include <vector>
namespace Eevp::Control::SoaSmartFilm {
using SoaFilmOpacityArray =
    msomeip::serde::array<uint8_t, 0, 0,
                          msomeip::serde::LengthFieldSize::FourBytes>;
enum class SoaDeviceIsNormal : uint8_t { kNORMAL = 0, kABNORMAL = 1 };
enum class SoaFilmPos : uint8_t {
  kWINDSHIELD = 1,
  kROOF_GLASS = 2,
  kDS_FRONTREAR = 3,
  kDS_QUARTER = 4,
  kAS_FRONTREAR = 5,
  kAS_QUARTER = 6,
  kREAR_GLASS = 7,
  kFRONT = 8,
  kLEFT = 9,
  kRIGHT = 10,
  kLEFT_REAR = 11,
  kRIGHT_REAR = 12
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
  if constexpr (std::is_same_v<T, SoaFilmPos>) {
    switch (value) {
    case SoaFilmPos::kWINDSHIELD:
      return "kWINDSHIELD";
    case SoaFilmPos::kROOF_GLASS:
      return "kROOF_GLASS";
    case SoaFilmPos::kDS_FRONTREAR:
      return "kDS_FRONTREAR";
    case SoaFilmPos::kDS_QUARTER:
      return "kDS_QUARTER";
    case SoaFilmPos::kAS_FRONTREAR:
      return "kAS_FRONTREAR";
    case SoaFilmPos::kAS_QUARTER:
      return "kAS_QUARTER";
    case SoaFilmPos::kREAR_GLASS:
      return "kREAR_GLASS";
    case SoaFilmPos::kFRONT:
      return "kFRONT";
    case SoaFilmPos::kLEFT:
      return "kLEFT";
    case SoaFilmPos::kRIGHT:
      return "kRIGHT";
    case SoaFilmPos::kLEFT_REAR:
      return "kLEFT_REAR";
    case SoaFilmPos::kRIGHT_REAR:
      return "kRIGHT_REAR";
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
const msomeip::ServiceId SERVICE_ID = 4953;
const msomeip::InstanceId INSTANCE_ID = 4967;
constexpr const char *DEPLOYMENT_META_DATA = R"(
Service:
  InstanceId: Eevp.Control.Provider_SoaSmartFilm
  SomeIpInstanceID: 4967
Interface:
  SomeIpServiceID: 4953
  attributes:
    soaFilmAuto:
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
    soaFilmDeviceNormal:
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
    soaFilmOpacities:
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
    soaFilmSwVersion:
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
  methods:
    SetAllOpacities:
      SomeIpReliable: null
      SomeIpMethodID: 16386
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetAllOpacitiesExt:
      SomeIpReliable: null
      SomeIpMethodID: 16418
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetAuto:
      SomeIpReliable: null
      SomeIpMethodID: 16387
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetAutoExt:
      SomeIpReliable: null
      SomeIpMethodID: 16419
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetOpacity:
      SomeIpReliable: null
      SomeIpMethodID: 16385
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetOpacityExt:
      SomeIpReliable: null
      SomeIpMethodID: 16417
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    StartExtJob_SmartFilm:
      SomeIpReliable: null
      SomeIpMethodID: 16401
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    StopExtJob_SmartFilm:
      SomeIpReliable: null
      SomeIpMethodID: 16402
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
  broadcasts: null
  arrays:
    SoaFilmOpacityArray:
      SomeIpArrayMinLength: null
      SomeIpArrayMaxLength: null
      SomeIpArrayLengthWidth: 0
  structs: null
  version:
    major: 1
    minor: 0

)";
} // namespace Eevp::Control::SoaSmartFilm
#endif