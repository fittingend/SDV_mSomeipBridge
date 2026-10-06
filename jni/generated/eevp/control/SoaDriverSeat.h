// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_DRIVER_SEAT_H
#define MSOMEIP_SOA_DRIVER_SEAT_H
#include <map>
#include <msomeip/MSomeIp.h>
#include <msomeip/serde/Deserialize.h>
#include <msomeip/serde/Serialize.h>
#include <vector>
namespace Eevp::Control::SoaDriverSeat {
enum class SoaDeviceIsNormal : uint8_t { kNORMAL = 0, kABNORMAL = 1 };
enum class SoaSeatHeightDirection : uint8_t { kSTOP = 0, kUP = 1, kDOWN = 2 };
enum class SoaSeatReclineDirection : uint8_t {
  kSTOP = 0,
  kFORWARD = 1,
  kBACKWARD = 2
};
enum class SoaSeatSlideDirection : uint8_t {
  kSTOP = 0,
  kFORWARD = 1,
  kBACKWARD = 2
};
enum class SoaSeatTiltDirection : uint8_t { kSTOP = 0, kUP = 1, kDOWN = 2 };
struct SoaSeatMotorDirection : public msomeip::serde::Serializable {
  SoaSeatSlideDirection slide;
  SoaSeatReclineDirection recline;
  SoaSeatHeightDirection height;
  SoaSeatTiltDirection tilt;

  auto tie() { return std::tie(slide, recline, height, tilt); }
  auto tie() const { return std::tie(slide, recline, height, tilt); }
  constexpr static msomeip::serde::LengthFieldSize LENGTH_FIELDS_SIZE =
      msomeip::serde::LengthFieldSize::None;
};
struct SoaSeatMotorPosition : public msomeip::serde::Serializable {
  uint8_t slide_position;
  uint8_t recline_position;
  uint8_t height_position;
  uint8_t tilt_position;

  auto tie() {
    return std::tie(slide_position, recline_position, height_position,
                    tilt_position);
  }
  auto tie() const {
    return std::tie(slide_position, recline_position, height_position,
                    tilt_position);
  }
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
  if constexpr (std::is_same_v<T, SoaSeatHeightDirection>) {
    switch (value) {
    case SoaSeatHeightDirection::kSTOP:
      return "kSTOP";
    case SoaSeatHeightDirection::kUP:
      return "kUP";
    case SoaSeatHeightDirection::kDOWN:
      return "kDOWN";
    }
  }
  if constexpr (std::is_same_v<T, SoaSeatReclineDirection>) {
    switch (value) {
    case SoaSeatReclineDirection::kSTOP:
      return "kSTOP";
    case SoaSeatReclineDirection::kFORWARD:
      return "kFORWARD";
    case SoaSeatReclineDirection::kBACKWARD:
      return "kBACKWARD";
    }
  }
  if constexpr (std::is_same_v<T, SoaSeatSlideDirection>) {
    switch (value) {
    case SoaSeatSlideDirection::kSTOP:
      return "kSTOP";
    case SoaSeatSlideDirection::kFORWARD:
      return "kFORWARD";
    case SoaSeatSlideDirection::kBACKWARD:
      return "kBACKWARD";
    }
  }
  if constexpr (std::is_same_v<T, SoaSeatTiltDirection>) {
    switch (value) {
    case SoaSeatTiltDirection::kSTOP:
      return "kSTOP";
    case SoaSeatTiltDirection::kUP:
      return "kUP";
    case SoaSeatTiltDirection::kDOWN:
      return "kDOWN";
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
const msomeip::ServiceId SERVICE_ID = 4946;
const msomeip::InstanceId INSTANCE_ID = 4962;
constexpr const char *DEPLOYMENT_META_DATA = R"(
Service:
  InstanceId: Eevp.Control.Provider_SoaDriverSeat
  SomeIpInstanceID: 4962
Interface:
  SomeIpServiceID: 4946
  attributes:
    soaDrvSeatDeviceNormal:
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
    soaDrvSeatMotorDirection:
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
    soaDrvSeatMotorPosition:
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
    soaDrvSeatSwVersion:
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
    RequestMoveDrvSeatHeight:
      SomeIpReliable: null
      SomeIpMethodID: 16387
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMoveDrvSeatHeightExt:
      SomeIpReliable: null
      SomeIpMethodID: 16419
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMoveDrvSeatRecline:
      SomeIpReliable: null
      SomeIpMethodID: 16386
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMoveDrvSeatReclineExt:
      SomeIpReliable: null
      SomeIpMethodID: 16418
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMoveDrvSeatSlide:
      SomeIpReliable: null
      SomeIpMethodID: 16385
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMoveDrvSeatSlideExt:
      SomeIpReliable: null
      SomeIpMethodID: 16417
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMoveDrvSeatTilt:
      SomeIpReliable: null
      SomeIpMethodID: 16388
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    RequestMoveDrvSeatTiltExt:
      SomeIpReliable: null
      SomeIpMethodID: 16420
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    StartExtJob_DriverSeat:
      SomeIpReliable: null
      SomeIpMethodID: 16401
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    StopExtJob_DriverSeat:
      SomeIpReliable: null
      SomeIpMethodID: 16402
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
  broadcasts: null
  arrays: null
  structs:
    SoaSeatMotorDirection:
      SomeIpStructLengthWidth: 0
    SoaSeatMotorPosition:
      SomeIpStructLengthWidth: 0
  version:
    major: 1
    minor: 0

)";
} // namespace Eevp::Control::SoaDriverSeat
#endif