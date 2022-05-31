#pragma once

#include <deque>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <dlfcn.h>

namespace PNuts {
    namespace DLLoader_ns{
    
        /**
         * Class for managing dynamic libraries
         */
        template<typename Interface>
        class DLLoader {
        private:
            void *m_lib_handle;
            std::string m_path; // path to lib
            std::string m_alloc;// allocator extern symbol
            std::string m_deltr;// deleter extern symbol
        protected:
        public:
            DLLoader(   const std::string& path,
                        const std::string& alloc = "allocator",
                        const std::string& deltr = "deleter");
            /**
             * Rule of FIVE
             */
            DLLoader(const DLLoader&) = delete;
            DLLoader(DLLoader&&) = default;
            DLLoader& operator=(const DLLoader&) = delete;
            DLLoader& operator=(DLLoader&&) = default;
            virtual ~DLLoader();
    
            //{ REGION: DL MANAGEMENT
            /**
             * Dlopen
             */
            void DL_Open(int RTLD = RTLD_NOW);
            /**
             * Dlclose
             */
            void DL_Close();
            /**
             * Dlinstance
             */
            std::shared_ptr<Interface> DL_GetInstance();
            //}
        };
    
        template<typename Interface>
        DLLoader<Interface>::DLLoader(  const std::string& path,
                                        const std::string& alloc,
                                        const std::string& deltr):
            m_lib_handle{nullptr}, m_path{path}, m_alloc{alloc}, m_deltr{deltr} {}
        template<typename Interface>
        DLLoader<Interface>::~DLLoader() {
            if( m_lib_handle != NULL ) {
                DL_Close();
            }
        }
    
        template<typename Interface>
        void DLLoader<Interface>::DL_Open(int RTLD) {
            m_lib_handle = dlopen(m_path.c_str(), RTLD); 
            if( m_lib_handle == NULL /*error*/ ) {
                std::cerr << "DL_Open Error: " << dlerror() << std::endl; 
            }
        }
    
        template<typename Interface>
        void DLLoader<Interface>::DL_Close() {
            if( m_lib_handle == NULL ) {
                std::cerr << "DL_Close Error: " << "Can't close unopened library" << std::endl;
                return;
            }
            if( dlclose(m_lib_handle) != 0 /*error*/ ) {
                std::cerr << "DL_Close Error: " << dlerror() << std::endl;
            }
        }
    
        template<typename Interface>
        std::shared_ptr<Interface> DLLoader<Interface>::DL_GetInstance() {
            using allocator_t = Interface* (*)();
            using deleter_t = void (*)(Interface *);
    
            allocator_t alloc_func = (allocator_t) dlsym(m_lib_handle,m_alloc.c_str());
            deleter_t deltr_func = (deleter_t) dlsym(m_lib_handle,m_deltr.c_str());
    
            if(!alloc_func || !deltr_func) {
                DL_Close();
                std::cerr << "DL_GetInstance Error: " << "Check if allocators and destructors are implemented" << std::endl;
            }
            return std::shared_ptr<Interface>(  alloc_func(), /*instantiate new object*/
                                                [deltr_func](Interface *ptr){ /*Specify how to delete it*/
                                                    deltr_func(ptr);
                                                }
                                             );
        }
    
    } // DLLoader_ns
} // PNuts

