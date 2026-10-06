// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_DRIVER_SEAT_PROXY_H
#define MSOMEIP_SOA_DRIVER_SEAT_PROXY_H

#include "SoaDriverSeat.h"
#include <francanstein/Attribute.h>
#include <francanstein/Event.h>
#include <francanstein/Proxy.h>

namespace Eevp::Control::SoaDriverSeat {

class SoaDriverSeatProxyDispatcher;

class SoaDriverSeatProxy final
    : public francanstein::Proxy,
      public std::enable_shared_from_this<SoaDriverSeatProxy> {

public:
  using soaDrvSeatDeviceNormalAttribute =
      francanstein::ObservableReadonlyAttribute<SoaDeviceIsNormal>;
  soaDrvSeatDeviceNormalAttribute &getsoaDrvSeatDeviceNormalAttribute() {
    return m_soa_drv_seat_device_normal_attribute;
  }

  using soaDrvSeatMotorDirectionAttribute =
      francanstein::ObservableReadonlyAttribute<SoaSeatMotorDirection>;
  soaDrvSeatMotorDirectionAttribute &getsoaDrvSeatMotorDirectionAttribute() {
    return m_soa_drv_seat_motor_direction_attribute;
  }

  using soaDrvSeatMotorPositionAttribute =
      francanstein::ObservableReadonlyAttribute<SoaSeatMotorPosition>;
  soaDrvSeatMotorPositionAttribute &getsoaDrvSeatMotorPositionAttribute() {
    return m_soa_drv_seat_motor_position_attribute;
  }

  using soaDrvSeatSwVersionAttribute =
      francanstein::ObservableReadonlyAttribute<uint8_t>;
  soaDrvSeatSwVersionAttribute &getsoaDrvSeatSwVersionAttribute() {
    return m_soa_drv_seat_sw_version_attribute;
  }

private:
  soaDrvSeatDeviceNormalAttribute m_soa_drv_seat_device_normal_attribute;
  soaDrvSeatMotorDirectionAttribute m_soa_drv_seat_motor_direction_attribute;
  soaDrvSeatMotorPositionAttribute m_soa_drv_seat_motor_position_attribute;
  soaDrvSeatSwVersionAttribute m_soa_drv_seat_sw_version_attribute;

public:
  void RequestMoveDrvSeatHeight(SoaSeatHeightDirection dir,
                                francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16387U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void RequestMoveDrvSeatHeightExt(SoaSeatHeightDirection dir,
                                   francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16419U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void RequestMoveDrvSeatRecline(SoaSeatReclineDirection dir,
                                 francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16386U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void RequestMoveDrvSeatReclineExt(SoaSeatReclineDirection dir,
                                    francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16418U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void RequestMoveDrvSeatSlide(SoaSeatSlideDirection dir,
                               francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16385U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void RequestMoveDrvSeatSlideExt(SoaSeatSlideDirection dir,
                                  francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16417U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void RequestMoveDrvSeatTilt(SoaSeatTiltDirection dir,
                              francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16388U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void RequestMoveDrvSeatTiltExt(SoaSeatTiltDirection dir,
                                 francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16420U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void StartExtJob_DriverSeat(francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16401U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void StopExtJob_DriverSeat(francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16402U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               return msomeip::ReturnCode::Ok;
                             });
  }

public:
  SoaDriverSeatProxy()
      : m_soa_drv_seat_device_normal_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49153U, {8705U}, false, 1U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_drv_seat_motor_direction_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49154U, {8706U}, false, 2U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_drv_seat_motor_position_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49155U, {8707U}, false, 3U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_drv_seat_sw_version_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49156U, {8708U}, false, 4U, false,
            msomeip::serde::ByteOrder::BigEndian) {}

public:
  ~SoaDriverSeatProxy() = default;

private:
  auto attach(std::weak_ptr<msomeip::MSomeIp> msomeip) -> void override {
    m_msomeip = msomeip;
    m_soa_drv_seat_device_normal_attribute.attach(msomeip);
    m_soa_drv_seat_motor_direction_attribute.attach(msomeip);
    m_soa_drv_seat_motor_position_attribute.attach(msomeip);
    m_soa_drv_seat_sw_version_attribute.attach(msomeip);
  }
  auto dispatcher() -> std::shared_ptr<francanstein::Dispatcher> override {
    if (m_dispatcher == nullptr) {
      m_dispatcher = std::make_shared<SoaDriverSeatProxyDispatcher>(*this);
    }
    return std::static_pointer_cast<francanstein::Dispatcher>(m_dispatcher);
  }
  auto behavior() -> francanstein::Behavior override {
    return francanstein::Behavior::Client;
  }

  std::weak_ptr<msomeip::MSomeIp> m_msomeip = std::weak_ptr<msomeip::MSomeIp>();
  std::shared_ptr<SoaDriverSeatProxyDispatcher> m_dispatcher;
  friend SoaDriverSeatProxyDispatcher;
};

class SoaDriverSeatProxyDispatcher final : public francanstein::Dispatcher {

public:
  explicit SoaDriverSeatProxyDispatcher(SoaDriverSeatProxy &parent)
      : m_parent(parent) {}

  auto deployment() -> const char * override {
    return SoaDriverSeat::DEPLOYMENT_META_DATA;
  }

  auto on_request(msomeip::Message message,
                  std::function<void(msomeip::Message &&)> responder)
      -> msomeip::ReturnCode override {
    return msomeip::ReturnCode::WrongMessageType;
  }

  auto on_request_no_return(msomeip::Message message)
      -> msomeip::ReturnCode override {
    return msomeip::ReturnCode::WrongMessageType;
  }

  auto on_availability(francanstein::AvailabilityMessage event)
      -> msomeip::ReturnCode override {
    return msomeip::ReturnCode::Ok;
  }

  auto on_subscription_status(francanstein::SubscriptionStatusMessage event)
      -> msomeip::ReturnCode override {
    return msomeip::ReturnCode::Ok;
  }

  auto on_subscription_registration_update(
      francanstein::SubscriptionRegistrationMessage event)
      -> msomeip::ReturnCode override {
    return msomeip::ReturnCode::Ok;
  }

public:
  auto on_notification(msomeip::Message message)
      -> msomeip::ReturnCode override {
    switch (auto method_id = message.get_method_id(); static_cast<uint32_t>(
                method_id)) { // NOLINT(*-multiway-paths-covered)
    case 49153U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaDeviceIsNormal();
      de.pop(response);
      m_parent.m_soa_drv_seat_device_normal_attribute.getChangedEvent()
          .notifyListeners(response);
      break;
    }
    case 49154U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaSeatMotorDirection();
      de.pop(response);
      m_parent.m_soa_drv_seat_motor_direction_attribute.getChangedEvent()
          .notifyListeners(response);
      break;
    }
    case 49155U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaSeatMotorPosition();
      de.pop(response);
      m_parent.m_soa_drv_seat_motor_position_attribute.getChangedEvent()
          .notifyListeners(response);
      break;
    }
    case 49156U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = uint8_t();
      de.pop(response);
      m_parent.m_soa_drv_seat_sw_version_attribute.getChangedEvent()
          .notifyListeners(response);
      break;
    }
    default: {
      return msomeip::ReturnCode::UnknownMethod;
    }
    }

    return msomeip::ReturnCode::Ok;
  }

private:
  SoaDriverSeatProxy &m_parent;
};

} // namespace Eevp::Control::SoaDriverSeat
#endif
