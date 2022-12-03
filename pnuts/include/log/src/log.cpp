#include <log/log.hpp>

namespace PNuts {
    namespace Log_ns {
        // necessary for static variables initialization
        std::shared_ptr<spdlog::logger> Log::m_core_logger;
        std::shared_ptr<spdlog::logger> Log::m_client_logger;

        void Log::init() {
            spdlog::set_pattern("%^[%T] %n: %v%$");

            m_core_logger = spdlog::stdout_color_mt("PNuts");

            m_client_logger = spdlog::stdout_color_mt("App");
        }
    } // Log_ns
} // PNuts
