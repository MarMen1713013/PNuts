#include <pnuts_engine/IApplication.hpp>
#include <pnuts_engine/log.hpp>

class Application : public PNuts::IApplication{
public:
    Application() {
        PNuts::Log::init();
        PNUTS_INFO("Starting sandbox application...");
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
