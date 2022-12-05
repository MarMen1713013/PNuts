#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace PNuts {
    class Log {
    public:
        static void init();
        inline static std::shared_ptr<spdlog::logger>& get_core_logger() {return m_core_logger;}
        inline static std::shared_ptr<spdlog::logger>& get_client_logger() {return m_client_logger;}
    private:
        static std::shared_ptr<spdlog::logger> m_core_logger;
        static std::shared_ptr<spdlog::logger> m_client_logger;
    };
} // PNuts

//Core log macros
#define PNUTS_CORE_FATAL(...) ::PNuts::Log::get_core_logger()->fatal(__VA_ARGS__)
#define PNUTS_CORE_ERROR(...) ::PNuts::Log::get_core_logger()->error(__VA_ARGS__)
#define PNUTS_CORE_WARN(...) ::PNuts::Log::get_core_logger()->warn(__VA_ARGS__)
#define PNUTS_CORE_INFO(...) ::PNuts::Log::get_core_logger()->info(__VA_ARGS__)
#define PNUTS_CORE_TRACE(...) ::PNuts::Log::get_core_logger()->trace(__VA_ARGS__)

//Client log macros
#define PNUTS_FATAL(...) ::PNuts::Log::get_client_logger()->fatal(__VA_ARGS__)
#define PNUTS_ERROR(...) ::PNuts::Log::get_client_logger()->error(__VA_ARGS__)
#define PNUTS_WARN(...) ::PNuts::Log::get_client_logger()->warn(__VA_ARGS__)
#define PNUTS_INFO(...) ::PNuts::Log::get_client_logger()->info(__VA_ARGS__)
#define PNUTS_TRACE(...) ::PNuts::Log::get_client_logger()->trace(__VA_ARGS__)
