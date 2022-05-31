#include "application/IApplication.hpp"

class Application : public PNuts::Application_ns::IApplication{
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
    PNuts::Application_ns::IApplication* allocator() {
        return new Application();
    }
    void deleter(PNuts::Application_ns::IApplication* ptr) {
        delete ptr;
    }
}
