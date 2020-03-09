#ifndef WINDOW_CLOSE_EVENT_HPP
#define WINDOW_CLOSE_EVENT_HPP

#include "System/Events/Event.hpp"

using Bare::System::Events::Event;

namespace Bare::System::Display
{

class WindowCloseEvent : public Event
{
public:
    static WindowCloseEvent *const Convert(Event *const event)
    {
        if (auto windowCloseEvent = dynamic_cast<WindowCloseEvent *const>(event))
            return windowCloseEvent;
        return nullptr;
    }
};

} // namespace Bare::System::Display

#endif // WINDOW_CLOSE_EVENT_HPP
