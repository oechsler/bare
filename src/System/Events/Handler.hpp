#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <functional>

#include "Event.hpp"

using std::function;

namespace Bare::System::Events
{

typedef function<void(Event *)> Handler;

} // namespace Bare::System::Events

#endif // HANDLER_HPP
