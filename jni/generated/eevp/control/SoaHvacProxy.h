// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_HVAC_PROXY_H
#define MSOMEIP_SOA_HVAC_PROXY_H

#include "SoaHvac.h"
#include <android/log.h>
#include <francanstein/Attribute.h>
#include <francanstein/Event.h>
#include <francanstein/Proxy.h>

namespace Eevp::Control::SoaHvac {

#ifndef SOA_HVAC_PROXY_LOGI
#define SOA_HVAC_PROXY_LOGI(...)                                               \
  ((void)__android_log_print(ANDROID_LOG_INFO, "SoaHvacProxy", __VA_ARGS__))
#endif

class SoaHvacProxyDispatcher;

class SoaHvacProxy final : public francanstein::Proxy,
                           public std::enable_shared_from_this<SoaHvacProxy> {

public:
  using SoaHvacSwVersionAttribute =
      francanstein::ObservableReadonlyAttribute<uint8_t>;
  SoaHvacSwVersionAttribute &getSoaHvacSwVersionAttribute() {
    return m_soa_hvac_sw_version_attribute;
  }

  using soaHvacDeviceNormalAttribute =
      francanstein::ObservableReadonlyAttribute<SoaDeviceIsNormal>;
  soaHvacDeviceNormalAttribute &getsoaHvacDeviceNormalAttribute() {
    return m_soa_hvac_device_normal_attribute;
  }

  using soaHvacSettingAttribute =
      francanstein::ObservableReadonlyAttribute<SoaHvacStatus>;
  soaHvacSettingAttribute &getsoaHvacSettingAttribute() {
    return m_soa_hvac_setting_attribute;
  }

  using soaHvacStatusAttribute =
      francanstein::ObservableReadonlyAttribute<SoaHvacStatus>;
  soaHvacStatusAttribute &getsoaHvacStatusAttribute() {
    return m_soa_hvac_status_attribute;
  }

  using soaHvacTempsAttribute =
      francanstein::ObservableReadonlyAttribute<SoaHvacTemps>;
  soaHvacTempsAttribute &getsoaHvacTempsAttribute() {
    return m_soa_hvac_temps_attribute;
  }

private:
  SoaHvacSwVersionAttribute m_soa_hvac_sw_version_attribute;
  soaHvacDeviceNormalAttribute m_soa_hvac_device_normal_attribute;
  soaHvacSettingAttribute m_soa_hvac_setting_attribute;
  soaHvacStatusAttribute m_soa_hvac_status_attribute;
  soaHvacTempsAttribute m_soa_hvac_temps_attribute;

public:
  void SetAcOnOff(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16386U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetAcOnOffExt(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16418U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetAirSource(SoaHvacAirSource src,
                    francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16393U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(src));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetAirSourceExt(SoaHvacAirSource src,
                       francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16425U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(src));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetAutoTemp(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16387U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetAutoTempExt(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16419U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetBackwardDefrostOn(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16395U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetBackwardDefrostOnExt(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16427U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetBlowingDirection(SoaHvacBlowDir dir,
                           francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16391U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetBlowingDirectionExt(SoaHvacBlowDir dir,
                              francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16423U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetBlowingForce(uint8_t force, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16390U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(force));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetBlowingForceExt(uint8_t force,
                          francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16422U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(force));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetDriverMode(SoaHvacBlowDir dir,
                     francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16428U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetDriverModeExt(SoaHvacBlowDir dir,
                        francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16429U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetDriverTemp(int8_t temperature,
                     francanstein::CallStatus &call_status) {
    call_status =
        async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16388U, false,
                   msomeip::serde::ByteOrder::BigEndian,
                   [&](auto &ser) -> msomeip::ReturnCode {
                     if (auto result = ser.push(std::move(temperature));
                         result != msomeip::ReturnCode::Ok) {
                       return result;
                     }
                     return msomeip::ReturnCode::Ok;
                   });
  }
  void SetDriverTempExt(int8_t temporature,
                        francanstein::CallStatus &call_status) {
    call_status =
        async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16420U, false,
                   msomeip::serde::ByteOrder::BigEndian,
                   [&](auto &ser) -> msomeip::ReturnCode {
                     if (auto result = ser.push(std::move(temporature));
                         result != msomeip::ReturnCode::Ok) {
                       return result;
                     }
                     return msomeip::ReturnCode::Ok;
                   });
  }
  void SetForwardDefrostOn(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16394U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetForwardDefrostOnExt(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16426U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetHvacPower(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16385U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetHvacPowerExt(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16417U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetPassengerMode(SoaHvacBlowDir dir,
                        francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16430U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetPassengerModeExt(SoaHvacBlowDir dir,
                           francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16431U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(dir));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetPassengerTemp(int8_t temperature,
                        francanstein::CallStatus &call_status) {
    call_status =
        async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16389U, false,
                   msomeip::serde::ByteOrder::BigEndian,
                   [&](auto &ser) -> msomeip::ReturnCode {
                     if (auto result = ser.push(std::move(temperature));
                         result != msomeip::ReturnCode::Ok) {
                       return result;
                     }
                     return msomeip::ReturnCode::Ok;
                   });
  }
  void SetPassengerTempExt(int8_t temporature,
                           francanstein::CallStatus &call_status) {
    call_status =
        async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16421U, false,
                   msomeip::serde::ByteOrder::BigEndian,
                   [&](auto &ser) -> msomeip::ReturnCode {
                     if (auto result = ser.push(std::move(temporature));
                         result != msomeip::ReturnCode::Ok) {
                       return result;
                     }
                     return msomeip::ReturnCode::Ok;
                   });
  }
  void SetSync(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16392U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetSyncExt(bool on, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16424U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(on));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void StartExtJob_Hvac(francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16401U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void StopExtJob_Hvac(francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16402U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               return msomeip::ReturnCode::Ok;
                             });
  }

public:
  SoaHvacProxy()
      : m_soa_hvac_sw_version_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49157U, {8709U}, false, 5U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_hvac_device_normal_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49153U, {8705U}, false, 1U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_hvac_setting_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49154U, {8706U}, false, 2U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_hvac_status_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49155U, {8707U}, false, 3U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_hvac_temps_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49156U, {8708U}, false, 4U, false,
            msomeip::serde::ByteOrder::BigEndian) {}

public:
  ~SoaHvacProxy() = default;

private:
  auto attach(std::weak_ptr<msomeip::MSomeIp> msomeip) -> void override {
    m_msomeip = msomeip;
    m_soa_hvac_sw_version_attribute.attach(msomeip);
    m_soa_hvac_device_normal_attribute.attach(msomeip);
    m_soa_hvac_setting_attribute.attach(msomeip);
    m_soa_hvac_status_attribute.attach(msomeip);
    m_soa_hvac_temps_attribute.attach(msomeip);
  }
  auto dispatcher() -> std::shared_ptr<francanstein::Dispatcher> override {
    if (m_dispatcher == nullptr) {
      m_dispatcher = std::make_shared<SoaHvacProxyDispatcher>(*this);
    }
    return std::static_pointer_cast<francanstein::Dispatcher>(m_dispatcher);
  }
  auto behavior() -> francanstein::Behavior override {
    return francanstein::Behavior::Client;
  }

  std::weak_ptr<msomeip::MSomeIp> m_msomeip = std::weak_ptr<msomeip::MSomeIp>();
  std::shared_ptr<SoaHvacProxyDispatcher> m_dispatcher;
  friend SoaHvacProxyDispatcher;
};

class SoaHvacProxyDispatcher final : public francanstein::Dispatcher {

public:
  explicit SoaHvacProxyDispatcher(SoaHvacProxy &parent) : m_parent(parent) {}

  auto deployment() -> const char * override {
    return SoaHvac::DEPLOYMENT_META_DATA;
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
    SOA_HVAC_PROXY_LOGI(
        "availability callback: svc=%u inst=%u major=%u minor=%u available=%s",
        static_cast<unsigned>(event.service_id),
        static_cast<unsigned>(event.instance_id),
        static_cast<unsigned>(event.major_version),
        static_cast<unsigned>(event.minor_version),
        event.availability ? "true" : "false");
    return msomeip::ReturnCode::Ok;
  }

  auto on_subscription_status(francanstein::SubscriptionStatusMessage event)
      -> msomeip::ReturnCode override {
    SOA_HVAC_PROXY_LOGI(
        "subscription status: svc=%u inst=%u major=%u event_group=%u ack=%s",
        static_cast<unsigned>(event.service_id),
        static_cast<unsigned>(event.instance_id),
        static_cast<unsigned>(event.major_version),
        static_cast<unsigned>(event.event_group_id), event.ack ? "true" : "false");
    return msomeip::ReturnCode::Ok;
  }

  auto on_subscription_registration_update(
      francanstein::SubscriptionRegistrationMessage event)
      -> msomeip::ReturnCode override {
    SOA_HVAC_PROXY_LOGI(
        "subscription registration: svc=%u inst=%u major=%u event_group=%u action=%s",
        static_cast<unsigned>(event.service_id),
        static_cast<unsigned>(event.instance_id),
        static_cast<unsigned>(event.major_version),
        static_cast<unsigned>(event.event_group_id),
        event.start_or_stop ? "start" : "stop");
    return msomeip::ReturnCode::Ok;
  }

public:
  auto on_notification(msomeip::Message message)
      -> msomeip::ReturnCode override {
    switch (auto method_id = message.get_method_id(); static_cast<uint32_t>(
                method_id)) { // NOLINT(*-multiway-paths-covered)
    case 49157U: {
      SOA_HVAC_PROXY_LOGI("notification: method=%u payload_size=%zu",
                          static_cast<unsigned>(method_id),
                          message.get_payload().size());
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = uint8_t();
      de.pop(response);
      m_parent.m_soa_hvac_sw_version_attribute.getChangedEvent()
          .notifyListeners(response);
      break;
    }
    case 49153U: {
      SOA_HVAC_PROXY_LOGI("notification: method=%u payload_size=%zu",
                          static_cast<unsigned>(method_id),
                          message.get_payload().size());
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaDeviceIsNormal();
      de.pop(response);
      m_parent.m_soa_hvac_device_normal_attribute.getChangedEvent()
          .notifyListeners(response);
      break;
    }
    case 49154U: {
      SOA_HVAC_PROXY_LOGI("notification: method=%u payload_size=%zu",
                          static_cast<unsigned>(method_id),
                          message.get_payload().size());
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaHvacStatus();
      de.pop(response);
      m_parent.m_soa_hvac_setting_attribute.getChangedEvent().notifyListeners(
          response);
      break;
    }
    case 49155U: {
      SOA_HVAC_PROXY_LOGI("notification: method=%u payload_size=%zu",
                          static_cast<unsigned>(method_id),
                          message.get_payload().size());
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaHvacStatus();
      de.pop(response);
      m_parent.m_soa_hvac_status_attribute.getChangedEvent().notifyListeners(
          response);
      break;
    }
    case 49156U: {
      SOA_HVAC_PROXY_LOGI("notification: method=%u payload_size=%zu",
                          static_cast<unsigned>(method_id),
                          message.get_payload().size());
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaHvacTemps();
      de.pop(response);
      m_parent.m_soa_hvac_temps_attribute.getChangedEvent().notifyListeners(
          response);
      break;
    }
    default: {
      return msomeip::ReturnCode::UnknownMethod;
    }
    }

    return msomeip::ReturnCode::Ok;
  }

private:
  SoaHvacProxy &m_parent;
};

} // namespace Eevp::Control::SoaHvac
#endif
