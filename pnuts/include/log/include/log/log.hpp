#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>

namespace PNuts {
    namespace Log_ns {
        class Log {
        public:
            static void init();
            inline static std::shared_ptr<spdlog::logger>& get_core_logger() {return m_core_logger;}
            inline static std::shared_ptr<spdlog::logger>& get_client_logger() {return m_client_logger;}
        private:
            static std::shared_ptr<spdlog::logger> m_core_logger;
            static std::shared_ptr<spdlog::logger> m_client_logger;
        };
    } // Log_ns
} // PNuts
