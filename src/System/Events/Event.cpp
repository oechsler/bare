#include "Event.hpp"

namespace Bare::System::Events
{

Event::Event()
    : handled(false)
{

}

void Event::handle()
{
    handled = true;
}

bool Event::isHandled() const
{
    return handled;
}

} // namespace Bare::System::Events
