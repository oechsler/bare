#ifndef DISPATCH_HPP
#define DISPATCH_HPP

#include <queue>
#include <vector>

#include "IDispatch.hpp"

using std::queue;
using std::vector;

namespace Bare::System::Events
{

class Dispatch : public IDispatch
{
    // Variables / properties
    queue<Event *const> events;
    vector<Handler> handlers;
    // END: Variables / properties

public:
    int attach(const Handler &handler) override;
    void detach(int identifier) override;

    void raise(Event *const event) override;
    void handleEvents() override;
};

} // namespace Bare::System::Events

#endif // DISPATCH_HPP
