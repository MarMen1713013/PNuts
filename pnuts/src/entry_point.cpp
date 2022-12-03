#include <iostream>
#include "pnuts/pnuts.h"

using namespace PNuts::Application_ns;
using namespace PNuts::DLLoader_ns;
using namespace PNuts::Log_ns;

int main( int argc, char* argv[] ) {

    DLLoader<IApplication> lb{"sandbox/libsandbox.so"};
    lb.DL_Open();
    auto app = lb.DL_GetInstance();
    
    spdlog::set_pattern("%^[%T] %n: %v%$");
    auto test_logger = spdlog::stdout_color_mt("TEST");
    test_logger->info("BOH");

    Log::init();
    Log::get_core_logger()->info("BOH DAVERO");
    app->run();
    return 0;
}
