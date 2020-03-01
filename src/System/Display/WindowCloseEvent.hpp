#ifndef WINDOW_CLOSE_EVENT_HPP
#define WINDOW_CLOSE_EVENT_HPP

#include "System/Events/Event.hpp"

using Bare::System::Events::Event;

namespace Bare::System::Display
{

class WindowCloseEvent : public Event
{
public:
    static WindowCloseEvent *Convert(Event *event)
    {
        if (auto windowCloseEvent = dynamic_cast<WindowCloseEvent *>(event))
            return windowCloseEvent;
        return nullptr;
    }
};

} // namespace Bare::System::Display

#endif
