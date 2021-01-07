#ifndef I_DISPATCH_HPP
#define I_DISPATCH_HPP

#include "Event.hpp"
#include "Handler.hpp"

namespace Bare::System::Events
{

typedef const char * HandlerIdentifier;

class IDispatch
{
public:
    virtual ~IDispatch() = default;

    virtual HandlerIdentifier attach(const Handler &handler) = 0;
    virtual void detach(HandlerIdentifier identifier) = 0;

    virtual void raise(Event *event) = 0;
    virtual void handleEvents() = 0;
};

} // namespace Bare::System::Events

#endif // I_DISPATCH_HPP
