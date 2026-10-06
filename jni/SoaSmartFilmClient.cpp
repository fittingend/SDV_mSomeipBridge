// Command-only port of jni_interface SoaSmartFilm; no callback/token state.
#include <chrono>
#include <filesystem>
#include <memory>
#include <thread>
#include <exception>
#include <jni.h>
#include <android/log.h>
#include "eevp/control/SoaSmartFilmProxy.h"
#include <francanstein/Bundle.h>

namespace {
using namespace Eevp::Control::SoaSmartFilm;
struct Client {
    std::shared_ptr<SoaSmartFilmProxy> proxy = std::make_shared<SoaSmartFilmProxy>();
    std::unique_ptr<francanstein::Bundle> bundle;
    Client() {
        std::filesystem::path config = "/vendor/etc/msomeip/msomeip.toml";
        bundle = std::make_unique<francanstein::Bundle>(config);
        bundle->add(proxy);
        bundle->hola();
    }
};
constexpr const char* TAG = "SoaSmartFilmCinemaJNI";
}

extern "C" {
JNIEXPORT jlong JNICALL Java_com_katech_ivi_connected_app_jni_SoaSmartFilmJNI_start(
        JNIEnv* env, jobject) {
    try {
        auto client = std::make_unique<Client>();
        // Same precondition as the existing Bridge: SOA must be running first.
        for (int poll = 0; poll < 21 && !client->proxy->is_available(); ++poll) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        if (!client->proxy->is_available()) {
            __android_log_print(ANDROID_LOG_ERROR, TAG, "SOA unavailable at startup");
            return 0;
        }
        return reinterpret_cast<jlong>(client.release());
    } catch (const std::exception& e) {
        jclass error = env->FindClass("java/lang/IllegalStateException");
        if (error) env->ThrowNew(error, e.what());
        return 0;
    }
}
JNIEXPORT void JNICALL Java_com_katech_ivi_connected_app_jni_SoaSmartFilmJNI_destroy(
        JNIEnv*, jobject, jlong ptr) {
    delete reinterpret_cast<Client*>(ptr);
}
JNIEXPORT void JNICALL Java_com_katech_ivi_connected_app_jni_SoaSmartFilmJNI_SetAllOpacities(
        JNIEnv*, jobject, jlong ptr, jbyte opacity) {
    auto* client = reinterpret_cast<Client*>(ptr);
    if (!client) return;
    francanstein::CallStatus status;
    client->proxy->SetAllOpacities(static_cast<uint8_t>(static_cast<uint8_t>(opacity)), status);
    if (status != francanstein::CallStatus::SUCCESS) {
        __android_log_print(ANDROID_LOG_ERROR, TAG, "SetAllOpacities failed");
    }
}
}
