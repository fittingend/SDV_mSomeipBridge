// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_HVAC_H
#define MSOMEIP_SOA_HVAC_H
#include <map>
#include <msomeip/MSomeIp.h>
#include <msomeip/serde/Deserialize.h>
#include <msomeip/serde/Serialize.h>
#include <vector>
namespace Eevp::Control::SoaHvac {
enum class SoaDeviceIsNormal : uint8_t { kNORMAL = 0, kABNORMAL = 1 };
enum class SoaHvacAirSource : uint8_t { kOUTER = 1, kINNER = 2 };
enum class SoaHvacBlowDir : uint8_t {
  kCHEST = 0,
  kBOTH = 1,
  kFOOT = 2,
  kFOOT_WITH_WS = 3
};
struct SoaHvacStatus : public msomeip::serde::Serializable {
  bool power_on;
  bool ac_on_off;
  bool auto_mode;
  bool sync_mode;
  int8_t driver_temp;
  int8_t passenger_temp;
  uint8_t blowing_force;
  SoaHvacBlowDir blowing_dir;
  SoaHvacAirSource air_src;
  bool forward_frost_on;
  bool backward_frost_on;
  SoaHvacBlowDir driver_mode;
  SoaHvacBlowDir passenger_mode;

  auto tie() {
    return std::tie(power_on, ac_on_off, auto_mode, sync_mode, driver_temp,
                    passenger_temp, blowing_force, blowing_dir, air_src,
                    forward_frost_on, backward_frost_on, driver_mode,
                    passenger_mode);
  }
  auto tie() const {
    return std::tie(power_on, ac_on_off, auto_mode, sync_mode, driver_temp,
                    passenger_temp, blowing_force, blowing_dir, air_src,
                    forward_frost_on, backward_frost_on, driver_mode,
                    passenger_mode);
  }
  constexpr static msomeip::serde::LengthFieldSize LENGTH_FIELDS_SIZE =
      msomeip::serde::LengthFieldSize::None;
};
struct SoaHvacTemps : public msomeip::serde::Serializable {
  int8_t inside;
  int8_t outside;
  int8_t duct;
  int8_t evaporator;
  int8_t driver_vent_duct;
  int8_t driver_floor_duct;
  int8_t passenger_vent_duct;
  int8_t passenger_floor_duct;

  auto tie() {
    return std::tie(inside, outside, duct, evaporator, driver_vent_duct,
                    driver_floor_duct, passenger_vent_duct,
                    passenger_floor_duct);
  }
  auto tie() const {
    return std::tie(inside, outside, duct, evaporator, driver_vent_duct,
                    driver_floor_duct, passenger_vent_duct,
                    passenger_floor_duct);
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
  if constexpr (std::is_same_v<T, SoaHvacAirSource>) {
    switch (value) {
    case SoaHvacAirSource::kOUTER:
      return "kOUTER";
    case SoaHvacAirSource::kINNER:
      return "kINNER";
    }
  }
  if constexpr (std::is_same_v<T, SoaHvacBlowDir>) {
    switch (value) {
    case SoaHvacBlowDir::kCHEST:
      return "kCHEST";
    case SoaHvacBlowDir::kBOTH:
      return "kBOTH";
    case SoaHvacBlowDir::kFOOT:
      return "kFOOT";
    case SoaHvacBlowDir::kFOOT_WITH_WS:
      return "kFOOT_WITH_WS";
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
const msomeip::ServiceId SERVICE_ID = 4952;
const msomeip::InstanceId INSTANCE_ID = 4966;
constexpr const char *DEPLOYMENT_META_DATA = R"(
Service:
  InstanceId: Eevp.Control.Provider_SoaHvac
  SomeIpInstanceID: 4966
Interface:
  SomeIpServiceID: 4952
  attributes:
    SoaHvacSwVersion:
      SomeIpGetterID: 5
      SomeIpSetterID: null
      SomeIpNotifierID: 49157
      SomeIpGetterReliable: false
      SomeIpSetterReliable: false
      SomeIpNotifierReliable: false
      SomeIpNotifierEventGroups:
      - 8709
      SomeIpAttributeEndianess: be
      SomeIpAttributeCRCWidth: zero
    soaHvacDeviceNormal:
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
    soaHvacSetting:
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
    soaHvacStatus:
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
    soaHvacTemps:
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
    SetAcOnOff:
      SomeIpReliable: null
      SomeIpMethodID: 16386
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetAcOnOffExt:
      SomeIpReliable: null
      SomeIpMethodID: 16418
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetAirSource:
      SomeIpReliable: null
      SomeIpMethodID: 16393
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetAirSourceExt:
      SomeIpReliable: null
      SomeIpMethodID: 16425
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetAutoTemp:
      SomeIpReliable: null
      SomeIpMethodID: 16387
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetAutoTempExt:
      SomeIpReliable: null
      SomeIpMethodID: 16419
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetBackwardDefrostOn:
      SomeIpReliable: null
      SomeIpMethodID: 16395
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetBackwardDefrostOnExt:
      SomeIpReliable: null
      SomeIpMethodID: 16427
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetBlowingDirection:
      SomeIpReliable: null
      SomeIpMethodID: 16391
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetBlowingDirectionExt:
      SomeIpReliable: null
      SomeIpMethodID: 16423
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetBlowingForce:
      SomeIpReliable: null
      SomeIpMethodID: 16390
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetBlowingForceExt:
      SomeIpReliable: null
      SomeIpMethodID: 16422
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetDriverMode:
      SomeIpReliable: null
      SomeIpMethodID: 16428
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetDriverModeExt:
      SomeIpReliable: null
      SomeIpMethodID: 16429
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetDriverTemp:
      SomeIpReliable: null
      SomeIpMethodID: 16388
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetDriverTempExt:
      SomeIpReliable: null
      SomeIpMethodID: 16420
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetForwardDefrostOn:
      SomeIpReliable: null
      SomeIpMethodID: 16394
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetForwardDefrostOnExt:
      SomeIpReliable: null
      SomeIpMethodID: 16426
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetHvacPower:
      SomeIpReliable: null
      SomeIpMethodID: 16385
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetHvacPowerExt:
      SomeIpReliable: null
      SomeIpMethodID: 16417
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetPassengerMode:
      SomeIpReliable: null
      SomeIpMethodID: 16430
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetPassengerModeExt:
      SomeIpReliable: null
      SomeIpMethodID: 16431
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetPassengerTemp:
      SomeIpReliable: null
      SomeIpMethodID: 16389
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetPassengerTempExt:
      SomeIpReliable: null
      SomeIpMethodID: 16421
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetSync:
      SomeIpReliable: null
      SomeIpMethodID: 16392
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    SetSyncExt:
      SomeIpReliable: null
      SomeIpMethodID: 16424
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    StartExtJob_Hvac:
      SomeIpReliable: null
      SomeIpMethodID: 16401
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
    StopExtJob_Hvac:
      SomeIpReliable: null
      SomeIpMethodID: 16402
      SomeIpMethodEndianess: be
      SomeIpMethodCRCWidth: zero
  broadcasts: null
  arrays: null
  structs:
    SoaHvacStatus:
      SomeIpStructLengthWidth: 0
    SoaHvacTemps:
      SomeIpStructLengthWidth: 0
  version:
    major: 1
    minor: 0

)";
} // namespace Eevp::Control::SoaHvac
#endif