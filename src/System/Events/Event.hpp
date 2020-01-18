#ifndef EVENT_HPP
#define EVENT_HPP

namespace Bare::System::Events
{

class Event
{
    bool handled;

public:
    virtual ~Event() {}

    void handle();
    bool isHandled() const;
};

} // namespace Bare::System::Events

#endif // EVENT_HPP
