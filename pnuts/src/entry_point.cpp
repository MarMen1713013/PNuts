#include <functional>
#include <iostream>
#include "pnuts/pnuts.h"
using namespace PNuts::Application_ns;
using namespace PNuts::DLLoader_ns;
int main( int argc, char* argv[] ) {
    DLLoader<IApplication> lb{"sandbox/libsandbox.so"};
    lb.DL_Open();
    auto app = lb.DL_GetInstance();
    std::cout << "Opening application..." << std::endl;
    app->run();
    return 0;
}
