#ifndef WINDOW_CLOSE_EVENT_HPP
#define WINDOW_CLOSE_EVENT_HPP

#include "System/Events/Event.hpp"

using Bare::System::Events::Event;

namespace Bare::System::Display
{

class WindowCloseEvent : public Event
{
public:
    static WindowCloseEvent *Convert(Event *const event)
    {
        return Event::Convert<WindowCloseEvent>(event);
    }
};

class IWindowCloseHandler
{
private:
    virtual void onWindowClose(WindowCloseEvent *event) = 0;
};

} // namespace Bare::System::Display

#endif // WINDOW_CLOSE_EVENT_HPP
