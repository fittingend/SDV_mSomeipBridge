// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_VEHICLE_INFO_PROXY_H
#define MSOMEIP_SOA_VEHICLE_INFO_PROXY_H

#include "SoaVehicleInfo.h"
#include <android/log.h>
#include <cstdio>
#include <francanstein/Attribute.h>
#include <francanstein/Event.h>
#include <francanstein/Proxy.h>
#include <string>

namespace Eevp::Control::SoaVehicleInfo {

#ifndef SOA_VEHICLE_INFO_PROXY_LOGI
#define SOA_VEHICLE_INFO_PROXY_LOGI(...)                                       \
  ((void)__android_log_print(ANDROID_LOG_INFO, "SoaVehicleInfoProxy",          \
                             __VA_ARGS__))
#endif

class SoaVehicleInfoProxyDispatcher;

class SoaVehicleInfoProxy final
    : public francanstein::Proxy,
      public std::enable_shared_from_this<SoaVehicleInfoProxy> {

public:
  using soaVehicleInfoAttribute =
      francanstein::ObservableReadonlyAttribute<VehicleInfo>;
  soaVehicleInfoAttribute &getsoaVehicleInfoAttribute() {
    return m_soa_vehicle_info_attribute;
  }

private:
  soaVehicleInfoAttribute m_soa_vehicle_info_attribute;

public:
public:
  SoaVehicleInfoProxy()
      : m_soa_vehicle_info_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49153U, {8705U}, false, 1U, false,
            msomeip::serde::ByteOrder::BigEndian) {}

public:
  ~SoaVehicleInfoProxy() = default;

private:
  auto attach(std::weak_ptr<msomeip::MSomeIp> msomeip) -> void override {
    m_msomeip = msomeip;
    m_soa_vehicle_info_attribute.attach(msomeip);
  }
  auto dispatcher() -> std::shared_ptr<francanstein::Dispatcher> override {
    if (m_dispatcher == nullptr) {
      m_dispatcher = std::make_shared<SoaVehicleInfoProxyDispatcher>(*this);
    }
    return std::static_pointer_cast<francanstein::Dispatcher>(m_dispatcher);
  }
  auto behavior() -> francanstein::Behavior override {
    return francanstein::Behavior::Client;
  }

  std::weak_ptr<msomeip::MSomeIp> m_msomeip = std::weak_ptr<msomeip::MSomeIp>();
  std::shared_ptr<SoaVehicleInfoProxyDispatcher> m_dispatcher;
  friend SoaVehicleInfoProxyDispatcher;
};

class SoaVehicleInfoProxyDispatcher final : public francanstein::Dispatcher {

public:
  explicit SoaVehicleInfoProxyDispatcher(SoaVehicleInfoProxy &parent)
      : m_parent(parent) {}

  auto deployment() -> const char * override {
    return SoaVehicleInfo::DEPLOYMENT_META_DATA;
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
    SOA_VEHICLE_INFO_PROXY_LOGI(
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
    SOA_VEHICLE_INFO_PROXY_LOGI(
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
    SOA_VEHICLE_INFO_PROXY_LOGI(
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
      SOA_VEHICLE_INFO_PROXY_LOGI(
          "notification: method=%u payload_size=%zu",
          static_cast<unsigned>(method_id), message.get_payload().size());

      auto payload = message.get_payload().to_vec();
      std::string hex;
      char buf[4];
      for (const auto byte : payload) {
        std::snprintf(buf, sizeof(buf), "%02X ",
                      static_cast<unsigned>(byte));
        hex += buf;
      }
      SOA_VEHICLE_INFO_PROXY_LOGI("RAW payload: %s", hex.c_str());

      auto response = VehicleInfo();
      // msomeip::serde::Deserialize de(message.get_payload().to_vec(),
      //                                msomeip::serde::ByteOrder::BigEndian);
      // de.pop(response);
      // TODO: AA 에서 송신하는 payload 의 형태가 fidl/fidelp 정의와 달라 우선 수동으로 parsing 함
      if (payload.size() >= 10U) {
        response.speed = static_cast<uint16_t>(
            static_cast<uint16_t>(payload[4]) |
            (static_cast<uint16_t>(payload[5]) << 8));
        response.gear_state = static_cast<SoaGearState>(payload[6]);
        response.acc_in = static_cast<SoaAccState>(payload[7]);
        response.ign_1_in = static_cast<SoaIgnState>(payload[8]);
        response.ign_2_in = static_cast<SoaIgnState>(payload[9]);
      }
      SOA_VEHICLE_INFO_PROXY_LOGI(
          "VehicleInfo decoded: speed=%u gear=%u acc=%u ign1=%u ign2=%u",
          static_cast<unsigned>(response.speed),
          static_cast<unsigned>(response.gear_state),
          static_cast<unsigned>(response.acc_in),
          static_cast<unsigned>(response.ign_1_in),
          static_cast<unsigned>(response.ign_2_in));
      m_parent.m_soa_vehicle_info_attribute.getChangedEvent().notifyListeners(
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
  SoaVehicleInfoProxy &m_parent;
};

} // namespace Eevp::Control::SoaVehicleInfo
#endif
