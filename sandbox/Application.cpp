#include "pnuts_engine/events/application_event.hpp"
#include "pnuts_engine/events/event.hpp"
#include "pnuts_engine/events/mouse_event.hpp"
#include <pnuts_engine/IApplication.hpp>
#include <pnuts_engine/log.hpp>
#include <pnuts_engine/pnuts_engine.h>

class Application : public PNuts::IApplication{
public:
    Application() {
        PNuts::Log::init();
        PNUTS_INFO("Starting sandbox application...");
    }
    virtual ~Application() {
    }
    void run() override {
        PNuts::MouseMovedEvent e(12.0,12.0);
        if(e.is_in_category(PNuts::event_category_application)) {
            PNUTS_TRACE(e.to_string());
        } else {
            PNUTS_ERROR("Wrong event class!");
            PNUTS_ERROR(e.to_string());
        }
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
