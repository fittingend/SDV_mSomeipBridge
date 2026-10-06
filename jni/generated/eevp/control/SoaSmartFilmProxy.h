// Notice : This is an automatically generated file. Never edit or modify it.

#ifndef MSOMEIP_SOA_SMART_FILM_PROXY_H
#define MSOMEIP_SOA_SMART_FILM_PROXY_H

#include "SoaSmartFilm.h"
#include <francanstein/Attribute.h>
#include <francanstein/Event.h>
#include <francanstein/Proxy.h>

namespace Eevp::Control::SoaSmartFilm {

class SoaSmartFilmProxyDispatcher;

class SoaSmartFilmProxy final
    : public francanstein::Proxy,
      public std::enable_shared_from_this<SoaSmartFilmProxy> {

public:
  using soaFilmAutoAttribute = francanstein::ObservableReadonlyAttribute<bool>;
  soaFilmAutoAttribute &getsoaFilmAutoAttribute() {
    return m_soa_film_auto_attribute;
  }

  using soaFilmDeviceNormalAttribute =
      francanstein::ObservableReadonlyAttribute<SoaDeviceIsNormal>;
  soaFilmDeviceNormalAttribute &getsoaFilmDeviceNormalAttribute() {
    return m_soa_film_device_normal_attribute;
  }

  using soaFilmOpacitiesAttribute =
      francanstein::ObservableReadonlyAttribute<SoaFilmOpacityArray>;
  soaFilmOpacitiesAttribute &getsoaFilmOpacitiesAttribute() {
    return m_soa_film_opacities_attribute;
  }

  using soaFilmSwVersionAttribute =
      francanstein::ObservableReadonlyAttribute<uint8_t>;
  soaFilmSwVersionAttribute &getsoaFilmSwVersionAttribute() {
    return m_soa_film_sw_version_attribute;
  }

private:
  soaFilmAutoAttribute m_soa_film_auto_attribute;
  soaFilmDeviceNormalAttribute m_soa_film_device_normal_attribute;
  soaFilmOpacitiesAttribute m_soa_film_opacities_attribute;
  soaFilmSwVersionAttribute m_soa_film_sw_version_attribute;

public:
  void SetAllOpacities(uint8_t opacity, francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16386U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(opacity));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetAllOpacitiesExt(uint8_t opacity,
                          francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16418U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(opacity));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetAuto(bool on, francanstein::CallStatus &call_status) {
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
  void SetAutoExt(bool on, francanstein::CallStatus &call_status) {
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
  void SetOpacity(SoaFilmPos pos, uint8_t opacity,
                  francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16385U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(pos));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               if (auto result = ser.push(std::move(opacity));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void SetOpacityExt(SoaFilmPos pos, uint8_t opacity,
                     francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16417U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               if (auto result = ser.push(std::move(pos));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               if (auto result = ser.push(std::move(opacity));
                                   result != msomeip::ReturnCode::Ok) {
                                 return result;
                               }
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void StartExtJob_SmartFilm(francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16401U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               return msomeip::ReturnCode::Ok;
                             });
  }
  void StopExtJob_SmartFilm(francanstein::CallStatus &call_status) {
    call_status = async_call(m_msomeip, SERVICE_ID, MAJOR_VERSION, 16402U,
                             false, msomeip::serde::ByteOrder::BigEndian,
                             [&](auto &ser) -> msomeip::ReturnCode {
                               return msomeip::ReturnCode::Ok;
                             });
  }

public:
  SoaSmartFilmProxy()
      : m_soa_film_auto_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49155U, {8707U}, false, 3U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_film_device_normal_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49153U, {8705U}, false, 1U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_film_opacities_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49154U, {8706U}, false, 2U, false,
            msomeip::serde::ByteOrder::BigEndian),
        m_soa_film_sw_version_attribute(
            std::weak_ptr<msomeip::MSomeIp>(),
            msomeip::ServiceIdentifier{SERVICE_ID, INSTANCE_ID, MAJOR_VERSION},
            49156U, {8708U}, false, 4U, false,
            msomeip::serde::ByteOrder::BigEndian) {}

public:
  ~SoaSmartFilmProxy() = default;

private:
  auto attach(std::weak_ptr<msomeip::MSomeIp> msomeip) -> void override {
    m_msomeip = msomeip;
    m_soa_film_auto_attribute.attach(msomeip);
    m_soa_film_device_normal_attribute.attach(msomeip);
    m_soa_film_opacities_attribute.attach(msomeip);
    m_soa_film_sw_version_attribute.attach(msomeip);
  }
  auto dispatcher() -> std::shared_ptr<francanstein::Dispatcher> override {
    if (m_dispatcher == nullptr) {
      m_dispatcher = std::make_shared<SoaSmartFilmProxyDispatcher>(*this);
    }
    return std::static_pointer_cast<francanstein::Dispatcher>(m_dispatcher);
  }
  auto behavior() -> francanstein::Behavior override {
    return francanstein::Behavior::Client;
  }

  std::weak_ptr<msomeip::MSomeIp> m_msomeip = std::weak_ptr<msomeip::MSomeIp>();
  std::shared_ptr<SoaSmartFilmProxyDispatcher> m_dispatcher;
  friend SoaSmartFilmProxyDispatcher;
};

class SoaSmartFilmProxyDispatcher final : public francanstein::Dispatcher {

public:
  explicit SoaSmartFilmProxyDispatcher(SoaSmartFilmProxy &parent)
      : m_parent(parent) {}

  auto deployment() -> const char * override {
    return SoaSmartFilm::DEPLOYMENT_META_DATA;
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
    case 49155U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = bool();
      de.pop(response);
      m_parent.m_soa_film_auto_attribute.getChangedEvent().notifyListeners(
          response);
      break;
    }
    case 49153U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaDeviceIsNormal();
      de.pop(response);
      m_parent.m_soa_film_device_normal_attribute.getChangedEvent()
          .notifyListeners(response);
      break;
    }
    case 49154U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = SoaFilmOpacityArray();
      de.pop(response);
      m_parent.m_soa_film_opacities_attribute.getChangedEvent().notifyListeners(
          response);
      break;
    }
    case 49156U: {
      msomeip::serde::Deserialize de(message.get_payload().to_vec(),
                                     msomeip::serde::ByteOrder::BigEndian);
      auto response = uint8_t();
      de.pop(response);
      m_parent.m_soa_film_sw_version_attribute.getChangedEvent()
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
  SoaSmartFilmProxy &m_parent;
};

} // namespace Eevp::Control::SoaSmartFilm
#endif
