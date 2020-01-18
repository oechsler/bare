#include "Event.hpp"

namespace Bare::System::Events
{

void Event::handle()
{
    handled = true;
}

bool Event::isHandled() const
{
    return handled;
}

} // namespace Bare::System::Events
