#ifndef DISPATCH_HPP
#define DISPATCH_HPP

#include <functional>
#include <queue>
#include <vector>

#include "Event.hpp"
#include "Handler.hpp"

using std::queue;
using std::vector;

namespace Bare::System::Events
{

class Dispatch
{
    queue<Event *> events;
    vector<Handler> handlers;

public:
    Dispatch();

    void raise(Event *event);

    int attach(const Handler &handler);
    void detach(int identifier);

    void handleEvents();
};

} // namespace Bare::System::Events

#endif // DISPATCH_HPP
