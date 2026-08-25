// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_VEHICLE_INFO_H
#define MSOMEIP_SOA_VEHICLE_INFO_H
#include <map>
#include <msomeip/MSomeIp.h>
#include <msomeip/serde/Deserialize.h>
#include <msomeip/serde/Serialize.h>
#include <vector>
namespace Eevp::Control::SoaVehicleInfo {
enum class SoaAccState : uint8_t { kOFF = 0, kON = 1, kERROR = 2 };
enum class SoaGearState : uint8_t {
  kGEAR_UNKNOWN = 0,
  kGEAR_P = 1,
  kGEAR_D = 2,
  kGEAR_N = 3,
  kGEAR_R = 4,
  kGEAR_L = 5,
  kGEAR_2 = 6,
  kGEAR_3 = 7,
  kGEAR_DS = 8,
  kGEAR_MS = 9,
  kGEAR_PS = 10,
  kGEAR_SUBCOM_COMM = 11,
  kGEAR_FAULT = 12
};
enum class SoaIgnState : uint8_t { kOFF = 0, kON = 1, kERROR = 2 };
struct VehicleInfo : public msomeip::serde::Serializable {
  uint16_t speed;
  SoaGearState gear_state;
  SoaAccState acc_in;
  SoaIgnState ign_1_in;
  SoaIgnState ign_2_in;

  auto tie() { return std::tie(speed, gear_state, acc_in, ign_1_in, ign_2_in); }
  auto tie() const {
    return std::tie(speed, gear_state, acc_in, ign_1_in, ign_2_in);
  }
  constexpr static msomeip::serde::LengthFieldSize LENGTH_FIELDS_SIZE =
      msomeip::serde::LengthFieldSize::None;
};
template <typename T, typename = std::enable_if_t<std::is_enum_v<T>>>
std::string to_string(T value) {

  if constexpr (std::is_same_v<T, SoaAccState>) {
    switch (value) {
    case SoaAccState::kOFF:
      return "kOFF";
    case SoaAccState::kON:
      return "kON";
    case SoaAccState::kERROR:
      return "kERROR";
    }
  }
  if constexpr (std::is_same_v<T, SoaGearState>) {
    switch (value) {
    case SoaGearState::kGEAR_UNKNOWN:
      return "kGEAR_UNKNOWN";
    case SoaGearState::kGEAR_P:
      return "kGEAR_P";
    case SoaGearState::kGEAR_D:
      return "kGEAR_D";
    case SoaGearState::kGEAR_N:
      return "kGEAR_N";
    case SoaGearState::kGEAR_R:
      return "kGEAR_R";
    case SoaGearState::kGEAR_L:
      return "kGEAR_L";
    case SoaGearState::kGEAR_2:
      return "kGEAR_2";
    case SoaGearState::kGEAR_3:
      return "kGEAR_3";
    case SoaGearState::kGEAR_DS:
      return "kGEAR_DS";
    case SoaGearState::kGEAR_MS:
      return "kGEAR_MS";
    case SoaGearState::kGEAR_PS:
      return "kGEAR_PS";
    case SoaGearState::kGEAR_SUBCOM_COMM:
      return "kGEAR_SUBCOM_COMM";
    case SoaGearState::kGEAR_FAULT:
      return "kGEAR_FAULT";
    }
  }
  if constexpr (std::is_same_v<T, SoaIgnState>) {
    switch (value) {
    case SoaIgnState::kOFF:
      return "kOFF";
    case SoaIgnState::kON:
      return "kON";
    case SoaIgnState::kERROR:
      return "kERROR";
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
const msomeip::ServiceId SERVICE_ID = 4955;
const msomeip::InstanceId INSTANCE_ID = 4969;
constexpr const char *DEPLOYMENT_META_DATA = R"(
Service:
  InstanceId: Eevp.Control.Provider_SoaVehicleInfo
  SomeIpInstanceID: 4969
Interface:
  SomeIpServiceID: 4955
  attributes:
    soaVehicleInfo:
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
  methods: null
  broadcasts: null
  arrays: null
  structs:
    VehicleInfo:
      SomeIpStructLengthWidth: 0
  version:
    major: 1
    minor: 0

)";
} // namespace Eevp::Control::SoaVehicleInfo
#endif
