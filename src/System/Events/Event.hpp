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

    // Getters and Setters
    [[nodiscard]] bool isHandled() const;
    // END: Getters and Setters

    template<typename T>
    static T *Convert(Event *event);
};

template <typename T>
T *Event::Convert(Event *const event)
{
    if (auto specificEvent = dynamic_cast<T *const>(event))
        return specificEvent;
    return nullptr;
}

} // namespace Bare::System::Events

#endif // EVENT_HPP
