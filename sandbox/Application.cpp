#include "pnuts/IApplication.hpp"
#include "pnuts/log.hpp"

class Application : public PNuts::IApplication{
public:
    Application() {
    }
    virtual ~Application() {
    }
    void run() override {
        while(true) {}
    }
};
extern "C" {
    PNuts::IApplication* allocator() {
        return new Application();
    }
    void deleter(PNuts::IApplication* ptr) {
        delete ptr;
    }
}
