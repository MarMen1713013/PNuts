#pragma once

#include <string>
#include <sstream>
#include <functional>

namespace PNuts {
    
    enum class event_type {
        NONE = 0,
        window_close, window_resize, window_focus, window_lost_focus, window_moved, // window events 
        app_tick, app_update, app_render,                                           // app events
        key_pressed, key_released, key_typed,                                       // key events
        mouse_button_pressed, mouse_button_released, mouse_moved, mouse_scrolled    // mouse events
    };

    enum event_category {
        NONE                        = 0x00,
        event_category_application  = 0x01,
        event_category_input        = 0x02,
        event_category_keyboard     = 0x04,
        event_category_mouse        = 0x08,
        event_category_mouse_button = 0x10
    };

#define EVENT_CLASS_TYPE(type)  static event_type get_static_type() { return event_type::type; }\
                                virtual event_type get_event_type() const override { return get_static_type(); }\
                                virtual const char* get_name() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int get_category_flags() const override { return category; }

    /**
     * BASE CLASS FOR EVENTS
     */
    class Event {
        friend class EventDispatcher;
    public:
        virtual event_type get_event_type() const = 0;
        virtual const char* get_name() const = 0;
        virtual int get_category_flags() const = 0;
        virtual std::string to_string() const { return get_name(); }

        inline bool is_in_category(event_category category) {
            return get_category_flags() & category;
        }
    protected:
        bool m_handeled = false;
    };

    /**
     * EVENT DISPATCHER
     */
    class EventDispatcher {
        template< typename T >
            using EventFn = std::function<bool(T&)>; // Handle for the event
    public:
        EventDispatcher(Event& event):
            m_event( event ) {}
        template< typename T >
            bool dispatch( EventFn<T> handle ) {
                if( m_event.get_event_type() == T::get_static_type() ) { // TODO: add check for types
                    m_event.m_handeled = handle( *(T*)&m_event ); //down-casting the event
                    return true;
                }
                return false;
            }
    private:
        Event& m_event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& event) {
        return os << event.to_string(); 
    }
} // PNuts
