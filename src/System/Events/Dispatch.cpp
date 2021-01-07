#include "Dispatch.hpp"

#include <sstream>
#include <string>

using std::addressof;
using std::stringstream;
using std::string;
using std::pair;

namespace Bare::System::Events
{

HandlerIdentifier Dispatch::attach(const Handler &handler)
{
    stringstream identifierStringBuilder;
    identifierStringBuilder << addressof(handler);

    auto identifierString = identifierStringBuilder.str();
    auto identifier = identifierString.c_str();

    auto handlerPair = pair<HandlerIdentifier, Handler>(identifier, handler);
    handlers.insert(handlerPair);

    return identifier;
}

void Dispatch::detach(HandlerIdentifier identifier)
{
    auto index = handlers.find(identifier);
    handlers.erase(index);
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

        for (const auto &attachedHandlerPair : handlers)
        {
            auto attachedHandlerIdentifier = attachedHandlerPair.first;
            auto attachedHandler = attachedHandlerPair.second;

            // INFO: This works because a Handler is
            // just a plain old C function pointer
            // that can then be called by the Dispatch!
            attachedHandler(event);

            // INFO: This early break mechanism can be
            // used events that should not be further
            // propagated downwards to other Handlers!
            // EXAMPLE: Layered click events
            if (event->isHandled())
                break;
        }

        delete event;
    }
}

} // namespace Bare::System::Events
