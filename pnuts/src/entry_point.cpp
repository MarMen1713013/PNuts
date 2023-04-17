#include <iostream>
#include <pnuts_engine/pnuts_engine.h>

using namespace PNuts;

int main( int argc, char* argv[] ) {

    Log::init();
    PNUTS_CORE_INFO("Starting engine...");

    DLLoader<IApplication> lb{"sandbox/libsandbox.so"};
    lb.DL_Open();
    auto app = lb.DL_GetInstance();
    app->run();
    lb.DL_Close();
    return 0;
}
