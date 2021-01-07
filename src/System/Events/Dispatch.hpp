#ifndef DISPATCH_HPP
#define DISPATCH_HPP

#include <queue>
#include <unordered_map>

#include "IDispatch.hpp"

using std::queue;
using std::unordered_map;

namespace Bare::System::Events
{

class Dispatch : public IDispatch
{
    // Variables / properties
    queue<Event *const> events;
    unordered_map<HandlerIdentifier, Handler> handlers;
    // END: Variables / properties

public:
    HandlerIdentifier attach(const Handler &handler) override;
    void detach(HandlerIdentifier identifier) override;

    void raise(Event *event) override;
    void handleEvents() override;
};

} // namespace Bare::System::Events

#endif // DISPATCH_HPP
