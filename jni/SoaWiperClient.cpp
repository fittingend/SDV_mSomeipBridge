// Command-only port of jni_interface SoaWiper; no callback/token state.
#include <chrono>
#include <filesystem>
#include <memory>
#include <thread>
#include <exception>
#include <jni.h>
#include <android/log.h>
#include "eevp/control/SoaWiperProxy.h"
#include <francanstein/Bundle.h>

namespace {
using namespace Eevp::Control::SoaWiper;
struct Client {
    std::shared_ptr<SoaWiperProxy> proxy = std::make_shared<SoaWiperProxy>();
    std::unique_ptr<francanstein::Bundle> bundle;
    Client() {
        std::filesystem::path config = "/vendor/etc/msomeip/msomeip.toml";
        bundle = std::make_unique<francanstein::Bundle>(config);
        bundle->add(proxy);
        bundle->hola();
    }
};
constexpr const char* TAG = "SoaWiperCinemaJNI";
}

extern "C" {
JNIEXPORT jlong JNICALL Java_com_katech_ivi_connected_app_jni_SoaWiperJNI_start(
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
JNIEXPORT void JNICALL Java_com_katech_ivi_connected_app_jni_SoaWiperJNI_destroy(
        JNIEnv*, jobject, jlong ptr) {
    delete reinterpret_cast<Client*>(ptr);
}
JNIEXPORT void JNICALL Java_com_katech_ivi_connected_app_jni_SoaWiperJNI_RequestWiperOperation(
        JNIEnv*, jobject, jlong ptr, jbyte mode) {
    auto* client = reinterpret_cast<Client*>(ptr);
    if (!client) return;
    francanstein::CallStatus status;
    client->proxy->RequestWiperOperation(static_cast<SoaWiperMode>(static_cast<uint8_t>(mode)), status);
    if (status != francanstein::CallStatus::SUCCESS) {
        __android_log_print(ANDROID_LOG_ERROR, TAG, "RequestWiperOperation failed");
    }
}
}
