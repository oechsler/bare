#include "Dispatch.hpp"

namespace Bare::System::Events
{

int Dispatch::attach(const Handler &handler)
{
    handlers.push_back(handler);
    return handlers.size() - 1;
}

void Dispatch::detach(int identifier)
{
    handlers.erase(handlers.begin() + identifier);
}

void Dispatch::raise(Event *const event)
{
    events.push(event);
}

void Dispatch::handleEvents()
{
    while (!events.empty())
    {
        auto event = events.front();
        events.pop();

        for (auto attachedHandler : handlers)
        {
            attachedHandler(event);

            if (event->isHandled())
                break;
        }

        delete event;
    }
}

} // namespace Bare::System::Events
