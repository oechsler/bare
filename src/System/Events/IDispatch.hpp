#ifndef I_DISPATCH_HPP
#define I_DISPATCH_HPP

#include "Event.hpp"
#include "Handler.hpp"

namespace Bare::System::Events
{

class IDispatch
{
public:
    virtual ~IDispatch() = default;

    virtual int attach(const Handler &handler) = 0;
    virtual void detach(int identifier) = 0;

    virtual void raise(Event *const event) = 0;
    virtual void handleEvents() = 0;
};

} // namespace Bare::System::Events

#endif // I_DISPATCH_HPP
