#include <iostream>
#include "pnuts/pnuts.h"

using namespace PNuts;

int main( int argc, char* argv[] ) {

    Log::init();
    PNUTS_CORE_WARN("Starting engine...");
    PNUTS_INFO("Hello!");

    DLLoader<IApplication> lb{"sandbox/libsandbox.so"};
    lb.DL_Open();
    auto app = lb.DL_GetInstance();
    app->run();

    return 0;
}
