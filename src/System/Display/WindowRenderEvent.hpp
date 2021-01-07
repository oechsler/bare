#ifndef BARE_WINDOWRENDEREVENT_HPP
#define BARE_WINDOWRENDEREVENT_HPP

#include "System/Events/Event.hpp"

using Bare::System::Events::Event;

namespace Bare::System::Display
{

class WindowRenderEvent : public Event
{
public:
    static WindowRenderEvent *Convert(Event *const event)
    {
        return Event::Convert<WindowRenderEvent>(event);
    }
};

class IWindowRenderHandler
{
private:
    virtual void onWindowRender(WindowRenderEvent *event) = 0;
};

}

#endif //BARE_WINDOWRENDEREVENT_HPP
