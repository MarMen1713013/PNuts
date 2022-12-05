#include "pnuts/log.hpp"
#include <memory>
#include <spdlog/common.h>

namespace PNuts {
    void Log::init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        m_core_logger = spdlog::stdout_color_mt("PNuts");
        m_core_logger->set_level(spdlog::level::trace);

        m_client_logger = spdlog::stdout_color_mt("App");
        m_client_logger->set_level(spdlog::level::trace);
    }
    std::shared_ptr<spdlog::logger> Log::m_core_logger;
    std::shared_ptr<spdlog::logger> Log::m_client_logger;
} // PNuts
