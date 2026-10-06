// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_WIPER_PROXY_H
#define MSOMEIP_SOA_WIPER_PROXY_H

#include "SoaWiper.h"
#include <francanstein/Attribute.h>
#include <francanstein/Event.h>
#include <francanstein/Proxy.h>

namespace Eevp::Control::SoaWiper {

class SoaWiperProxyDispatcher;

class SoaWiperProxy final : public francanstein::Proxy,
                            public std::enable_shared_from_this<SoaWiperProxy> {

public:
  using soaWiperDeviceNormalAttribute =
      francanstein::ObservableReadonlyAttribute<SoaDeviceIsNormal>;
  soaWiperDeviceNormalAttribute &getsoaWiperDeviceNormalAttribute() {
    return m_soa_wiper_device_normal_attribute;
  }

  using soaWiperMfswAttribute =
      francanstein::ObservableReadonlyAttribute<SoaWiferMfsw>;
  soaWiperMfswAttribute &getsoaWiperMfswAttribute() {
    return m_soa_wiper_mfsw_attribute;
  }

  using soaWiperStatusAttribute =
      francanstein::ObservableReadonlyAttribute<SoaWiperStatus>;
  soaWiperStatusAttribute &getsoaWiperStatusAttribute() {
    return m_soa_wiper_status_attribute;
  }

  using soaWiperSwVersionAttribute =
      francanstein::ObservableReadonlyAttribute<uint8_t>;
  soaWiperSwVersionAttribute &getsoaWiperSwVersionAttribute() {
    return m_soa_wiper_sw_version_attribute;
  }

private:
  soaWiperDeviceNormalAttribute m_soa_wiper_device_normal_attribute;
  soaWiperMfswAttribute m_soa_wiper_mfsw_attribute;
  soaWiperStatusAttribute m_soa_wiper_status_attribute;
  soaWiperSwVersionAttribute m_soa_wiper_sw_version_attribute;

public:
  void RequestWiperOperation(SoaWiperMode mode,
                             francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16386U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(mode));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void RequestWiperOperationExt(SoaWiperMode mode,
                                francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16418U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(mode));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetWiperAutoSpeed(bool is_auto_speed,
                         francanstein::CallStatus &call_status) {
    call_status =
        async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16385U, false,
                   msomeip::serde::ByteOrder::BigEndian,
                   [&](auto &ser) -> msomeip::ReturnCode {
                     if (auto result = ser.push(std::move(is_auto_speed));
                         result != msomeip::ReturnCode::Ok) {
                       return result;
                     }
                     return msomeip::ReturnCode::Ok;
                   });
  }
  void SetWiperAutoSpeedExt(bool is_auto_speed,
                            francanstein::CallStatus &call_status) {
    call_status =
        async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16417U, false,
                   msomeip::serde::ByteOrder::BigEndian,
                   [&](auto &ser) -> msomeip::ReturnCode {
                     if (auto result = ser.push(std::move(is_auto_speed));
                         result != msomeip::ReturnCode::Ok) {
                       return result;
                     }
                     return msomeip::ReturnCode::Ok;
                   });
  }
  void StartExtJob_Wiper(francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16401U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void StopExtJob_Wiper(francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16402U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               return msomeip::ReturnCode::Ok;
                             });
  }

public:
  SoaWiperProxy()
      : m_soa_wiper_device_normal_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49153U, {8705U}, false, 1U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_wiper_mfsw_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49156U, {8708U}, false, 4U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_wiper_status_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49154U, {8706U}, false, 2U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_wiper_sw_version_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49155U, {8707U}, false, 3U, false,
            msomeip::serde::ByteOrder::BigEndian) {}

public:
  ~SoaWiperProxy() = default;

private:
  auto attach(std::weak_ptr<msomeip::MSomeIp> msomeip) -> void override {
    m_msomeip = msomeip;
    m_soa_wiper_device_normal_attribute.attach(msomeip);
    m_soa_wiper_mfsw_attribute.attach(msomeip);
    m_soa_wiper_status_attribute.attach(msomeip);
    m_soa_wiper_sw_version_attribute.attach(msomeip);
  }
  auto dispatcher() -> std::shared_ptr<francanstein::Dispatcher> override {
    if (m_dispatcher == nullptr) {
      m_dispatcher = std::make_shared<SoaWiperProxyDispatcher>(*this);
    }
    return std::static_pointer_cast<francanstein::Dispatcher>(m_dispatcher);
  }
  auto behavior() -> francanstein::Behavior override {
    return francanstein::Behavior::Client;
  }

  std::weak_ptr<msomeip::MSomeIp> m_msomeip = std::weak_ptr<msomeip::MSomeIp>();
  std::shared_ptr<SoaWiperProxyDispatcher> m_dispatcher;
  friend SoaWiperProxyDispatcher;
};

class SoaWiperProxyDispatcher final : public francanstein::Dispatcher {

public:
  explicit SoaWiperProxyDispatcher(SoaWiperProxy &parent) : m_parent(parent) {}

  auto deployment() -> const char * override {
    return SoaWiper::DEPLOYMENT_META_DATA;
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
      m_parent.m_soa_wiper_device_normal_attribute.getChangedEvent()
          .notifyListeners(response);
      break;
    }
    case 49156U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaWiferMfsw();
      de.pop(response);
      m_parent.m_soa_wiper_mfsw_attribute.getChangedEvent().notifyListeners(
          response);
      break;
    }
    case 49154U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaWiperStatus();
      de.pop(response);
      m_parent.m_soa_wiper_status_attribute.getChangedEvent().notifyListeners(
          response);
      break;
    }
    case 49155U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = uint8_t();
      de.pop(response);
      m_parent.m_soa_wiper_sw_version_attribute.getChangedEvent()
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
  SoaWiperProxy &m_parent;
};

} // namespace Eevp::Control::SoaWiper
#endif
