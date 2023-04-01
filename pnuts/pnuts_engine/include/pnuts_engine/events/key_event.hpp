#pragma once

#include <pnuts_engine/events/event.hpp>

namespace PNuts {

    class KeyEvent : public Event { 
    public:
        int get_key_code() const { return m_key_code; }
        EVENT_CLASS_CATEGORY( event_category_keyboard | event_category_input ); // is it useful to use a macro?
    protected:
        KeyEvent( int key_code ):
            m_key_code( key_code ) {}
        int m_key_code;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent( int key_code, int repeted_count ):
            KeyEvent( key_code ), m_repeted_count(repeted_count) {}
        int get_repeted_count() const { return m_repeted_count; }
        std::string to_string() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_key_code << " (x" << m_repeted_count << ")";
            return ss.str();
        }
        EVENT_CLASS_TYPE( key_pressed ); //expand this into the macro
    private:
        int m_repeted_count;
    };

    class KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent( int key_code ):
            KeyEvent( key_code ) {}
        std::string to_string() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_key_code;
            return ss.str();
        }
        EVENT_CLASS_TYPE( key_pressed ); //expand this into the macro
    };
} // PNuts
