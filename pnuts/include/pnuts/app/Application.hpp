#pragma once

namespace PNuts {
    class IApplication {
    public:
        IApplication();
        virtual ~IApplication();
        virtual void run();
    };
} // PNuts
