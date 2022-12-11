#pragma once

#include "pnuts/events/event.hpp"

namespace PNuts {

    class WindowResize : public Event {
    public:
        WindowResize( unsigned int width, unsigned int height ):
            m_width( width ), m_height( height ) {}
        unsigned int get_width() const { return m_width; }
        unsigned int get_height() const { return m_height; }
        std::string to_string() const override {
            std::stringstream ss;
            ss << "WindowResize: ( " << m_width << ", " << m_height << " )";
            return ss.str();
        }
        EVENT_CLASS_TYPE( window_resize );
        EVENT_CLASS_CATEGORY( event_category_application );
    private:
        unsigned int m_width;
        unsigned int m_height;
    };

    class WindowClose : public Event {
    public:
        WindowClose() = default;
        EVENT_CLASS_TYPE( window_close );
        EVENT_CLASS_CATEGORY( event_category_application );
    };

    class WindowFocus : public Event {
    public:
        WindowFocus() = default;
        EVENT_CLASS_TYPE( window_focus );
        EVENT_CLASS_CATEGORY( event_category_application );
    };

    class WindowLostFocus : public Event {
    public:
        WindowLostFocus() = default;
        EVENT_CLASS_TYPE( window_lost_focus );
        EVENT_CLASS_CATEGORY( event_category_application );
    };

    class WindowMoved : public Event {
    public:
        WindowMoved( unsigned int offset_x, unsigned int offset_y ):
            m_offset_x( offset_x ), m_offset_y( offset_y ) {}
        unsigned int get_offset_x() const { return m_offset_x; }
        unsigned int get_offset_y() const { return m_offset_y; }
        std::string to_string() const override {
            std::stringstream ss;
            ss << "WindowMoved: ( " << m_offset_x << ", " << m_offset_y << " )";
            return ss.str();
        }
        EVENT_CLASS_TYPE( window_moved );
        EVENT_CLASS_CATEGORY( event_category_application );
    private:
        unsigned int m_offset_x;
        unsigned int m_offset_y;
    };

    class AppTick : public Event {
    public:
        AppTick() = default;
        EVENT_CLASS_TYPE( app_tick );
        EVENT_CLASS_CATEGORY( event_category_application );
    };

    class AppUpdate : public Event {
    public:
        AppUpdate() = default;
        EVENT_CLASS_TYPE( app_update );
        EVENT_CLASS_CATEGORY( event_category_application );
    };

    class AppRender : public Event {
    public:
        AppRender() = default;
        EVENT_CLASS_TYPE( app_render );
        EVENT_CLASS_CATEGORY( event_category_application );
    };
} // PNutheight
