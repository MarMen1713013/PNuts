#pragma once

namespace PNuts {
    namespace Application_ns {
        class IApplication {
        public:
            IApplication() {}
            virtual ~IApplication() {}
            virtual void run() = 0;
        };
    } // Application_ns
} // PNuts
