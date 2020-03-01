#ifndef DISPATCH_HPP
#define DISPATCH_HPP

#include <functional>
#include <queue>
#include <vector>

#include "Event.hpp"
#include "Handler.hpp"

using std::function;
using std::queue;
using std::vector;
using namespace std::placeholders;

namespace Bare::System::Events
{

class Dispatch
{
    queue<Event *> events;
    vector<Handler> handlers;

    int attach(const Handler &handler);

public:
    Dispatch();

    void raise(Event *event);

    template <typename Delegate, typename Converter>
    int attach(const Delegate &delegate, const Converter &converter)
    {
        auto handler = std::bind(&delegate, std::bind(&converter, _1));
        return attach(handler);
    }
    void detach(int identifier);

    void handleEvents();
};

} // namespace Bare::System::Events

#endif // DISPATCH_HPP
