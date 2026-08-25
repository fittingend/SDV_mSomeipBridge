// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_MLM_PROXY_H
#define MSOMEIP_SOA_MLM_PROXY_H

#include "SoaMlm.h"
#include <android/log.h>
#include <francanstein/Attribute.h>
#include <francanstein/Event.h>
#include <francanstein/Proxy.h>

namespace Eevp::Control::SoaMlm {

#ifndef SOA_MLM_PROXY_LOGI
#define SOA_MLM_PROXY_LOGI(...)                                                \
  ((void)__android_log_print(ANDROID_LOG_INFO, "SoaMlmProxy", __VA_ARGS__))
#endif

class SoaMlmProxyDispatcher;

class SoaMlmProxy final : public francanstein::Proxy,
                          public std::enable_shared_from_this<SoaMlmProxy> {

public:
  using soaMlmStatusAttribute =
      francanstein::ObservableReadonlyAttribute<SoaMlmStatus>;
  soaMlmStatusAttribute &getsoaMlmStatusAttribute() {
    return m_soa_mlm_status_attribute;
  }

  using soaMlmSwVersionAttribute =
      francanstein::ObservableReadonlyAttribute<uint8_t>;
  soaMlmSwVersionAttribute &getsoaMlmSwVersionAttribute() {
    return m_soa_mlm_sw_version_attribute;
  }

private:
  soaMlmStatusAttribute m_soa_mlm_status_attribute;
  soaMlmSwVersionAttribute m_soa_mlm_sw_version_attribute;

public:
  void RequestMlmSetBrightness(uint16_t brightness,
                               francanstein::CallStatus &call_status) {
    call_status =
        async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16387U, false,
                   msomeip::serde::ByteOrder::BigEndian,
                   [&](auto &ser) -> msomeip::ReturnCode {
                     if (auto result = ser.push(std::move(brightness));
                         result != msomeip::ReturnCode::Ok) {
                       return result;
                     }
                     return msomeip::ReturnCode::Ok;
                   });
  }
  void RequestMlmSetBrightnessExt(uint16_t brightness,
                                  francanstein::CallStatus &call_status) {
    call_status =
        async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16419U, false,
                   msomeip::serde::ByteOrder::BigEndian,
                   [&](auto &ser) -> msomeip::ReturnCode {
                     if (auto result = ser.push(std::move(brightness));
                         result != msomeip::ReturnCode::Ok) {
                       return result;
                     }
                     return msomeip::ReturnCode::Ok;
                   });
  }
  void RequestMlmSetMode(SoaMlmMoodMode mood,
                         francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16386U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(mood));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void RequestMlmSetModeExt(SoaMlmMoodMode mood,
                            francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16418U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(mood));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void RequestMlmSetRgbColor(uint8_t color_table_index,
                             francanstein::CallStatus &call_status) {
    call_status =
        async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16385U, false,
                   msomeip::serde::ByteOrder::BigEndian,
                   [&](auto &ser) -> msomeip::ReturnCode {
                     if (auto result = ser.push(std::move(color_table_index));
                         result != msomeip::ReturnCode::Ok) {
                       return result;
                     }
                     return msomeip::ReturnCode::Ok;
                   });
  }
  void RequestMlmSetRgbColorExt(uint8_t color_table_index,
                                francanstein::CallStatus &call_status) {
    call_status =
        async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16417U, false,
                   msomeip::serde::ByteOrder::BigEndian,
                   [&](auto &ser) -> msomeip::ReturnCode {
                     if (auto result = ser.push(std::move(color_table_index));
                         result != msomeip::ReturnCode::Ok) {
                       return result;
                     }
                     return msomeip::ReturnCode::Ok;
                   });
  }
  void StartExtJob_Mlm(francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16401U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void StopExtJob_Mlm(francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16402U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               return msomeip::ReturnCode::Ok;
                             });
  }

public:
  SoaMlmProxy()
      : m_soa_mlm_status_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49153U, {8705U}, false, 1U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_mlm_sw_version_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49154U, {8706U}, false, 2U, false,
            msomeip::serde::ByteOrder::BigEndian) {}

public:
  ~SoaMlmProxy() = default;

private:
  auto attach(std::weak_ptr<msomeip::MSomeIp> msomeip) -> void override {
    m_msomeip = msomeip;
    m_soa_mlm_status_attribute.attach(msomeip);
    m_soa_mlm_sw_version_attribute.attach(msomeip);
  }
  auto dispatcher() -> std::shared_ptr<francanstein::Dispatcher> override {
    if (m_dispatcher == nullptr) {
      m_dispatcher = std::make_shared<SoaMlmProxyDispatcher>(*this);
    }
    return std::static_pointer_cast<francanstein::Dispatcher>(m_dispatcher);
  }
  auto behavior() -> francanstein::Behavior override {
    return francanstein::Behavior::Client;
  }

  std::weak_ptr<msomeip::MSomeIp> m_msomeip = std::weak_ptr<msomeip::MSomeIp>();
  std::shared_ptr<SoaMlmProxyDispatcher> m_dispatcher;
  friend SoaMlmProxyDispatcher;
};

class SoaMlmProxyDispatcher final : public francanstein::Dispatcher {

public:
  explicit SoaMlmProxyDispatcher(SoaMlmProxy &parent) : m_parent(parent) {}

  auto deployment() -> const char * override {
    return SoaMlm::DEPLOYMENT_META_DATA;
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
    SOA_MLM_PROXY_LOGI(
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
    SOA_MLM_PROXY_LOGI(
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
    SOA_MLM_PROXY_LOGI(
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
    case 49153U: {
      SOA_MLM_PROXY_LOGI("notification: method=%u payload_size=%zu",
                         static_cast<unsigned>(method_id),
                         message.get_payload().size());
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaMlmStatus();
      de.pop(response);
      m_parent.m_soa_mlm_status_attribute.getChangedEvent().notifyListeners(
          response);
      break;
    }
    case 49154U: {
      SOA_MLM_PROXY_LOGI("notification: method=%u payload_size=%zu",
                         static_cast<unsigned>(method_id),
                         message.get_payload().size());
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = uint8_t();
      de.pop(response);
      m_parent.m_soa_mlm_sw_version_attribute.getChangedEvent().notifyListeners(
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
  SoaMlmProxy &m_parent;
};

} // namespace Eevp::Control::SoaMlm
#endif
