#include "System/Events/Dispatch.hpp"

#include <iostream>

using namespace Bare::System::Events;

class CustomEvent : public Event
{
    const char *data;

public:
    CustomEvent(const char *data)
    {
        this->data = data;
    }

    const char *getData() const
    {
        return data;
    }

    static CustomEvent *Convert(Event *event)
    {
        if (auto customEvent = dynamic_cast<CustomEvent *>(event))
            return customEvent;
        return nullptr;
    }
};

void customHandler(CustomEvent *event)
{
    if (event == nullptr)
        return;

    std::cout << "[CustomEvent]: " << event->getData() << std::endl;
}

int main(int argc, char **argv)
{
    Event *event = new CustomEvent("Hello World");

    Dispatch d;
    int handle = d.attach(customHandler, CustomEvent::Convert);

    d.send(event);
    d.handleEvents();

    d.detach(handle);

    return 0;
}
