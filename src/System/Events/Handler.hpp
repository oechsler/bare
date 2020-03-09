#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <functional>

#include "Event.hpp"

using std::function;

#define __CONVERTER(converter) std::bind(converter, std::placeholders::_1)
#define FuncHandler(delegate, converter) std::bind(delegate, __CONVERTER(converter))
#define ClassHandler(delegate, converter) std::bind(delegate, this, __CONVERTER(converter))

namespace Bare::System::Events
{

typedef function<void(Event *)> Handler;

} // namespace Bare::System::Events

#endif // HANDLER_HPP
