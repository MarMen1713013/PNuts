#pragma once

#include <pnuts_engine/events/event.hpp>
#include <pnuts_engine/mouse_codes.h>

namespace PNuts {

    class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent( float x, float y ):
            m_mouse_x( x ), m_mouse_y( y ) {}
        float get_x() const { return m_mouse_x; }
        float get_y() const { return m_mouse_y; }
        EVENT_CLASS_TYPE( mouse_moved );
        EVENT_CLASS_CATEGORY( event_category_mouse | event_category_input );
        std::string to_string() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: ( " << m_mouse_x << ", " << m_mouse_y << " )";
            return ss.str();
        }
    private:
        float m_mouse_x;
        float m_mouse_y;
    };

    class MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent( float offset_x, float offset_y ):
            m_offset_x( offset_x ), m_offset_y( offset_y ) {}
        float get_offset_x() const { return m_offset_x; }
        float get_offset_y() const { return m_offset_y; }
        EVENT_CLASS_TYPE( mouse_scrolled );
        EVENT_CLASS_CATEGORY( event_category_mouse | event_category_input );
        std::string to_string() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: ( " << m_offset_x << ", " << m_offset_y << " )";
            return ss.str();
        }
    private:
        float m_offset_x;
        float m_offset_y;
    };

    class MouseButtonEvent : public Event {
    public:
        MouseCode get_mouse_button() const { return m_button; }
        EVENT_CLASS_CATEGORY( event_category_mouse | event_category_input );
    protected:
        MouseButtonEvent( const MouseCode button ):
            m_button( button ) {}
        MouseCode m_button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        MouseButtonPressedEvent( MouseCode button ):
            MouseButtonEvent(button) {}
        std::string to_string() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_button;
            return ss.str();
        }
        EVENT_CLASS_TYPE( mouse_button_pressed );
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent {
    public:
        MouseButtonReleasedEvent( MouseCode button ):
            MouseButtonEvent( button ) {}
        std::string to_string() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_button;
            return ss.str();
        }
        EVENT_CLASS_TYPE( mouse_button_released );
    };

} // PNuts
