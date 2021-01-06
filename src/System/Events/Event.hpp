#ifndef EVENT_HPP
#define EVENT_HPP

namespace Bare::System::Events
{

class Event
{
    // Variables / properties
    bool handled;
    // END: Variables / properties

public:
    Event();
    virtual ~Event() = default;

    void handle();
    [[nodiscard]] bool isHandled() const;
};

} // namespace Bare::System::Events

#endif // EVENT_HPP
