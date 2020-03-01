#include "System/Events/Dispatch.hpp"
#include "System/Logging/Logger.hpp"
#include "System/Display/Window.hpp"

#include <fmt/format.h>

#include <iostream>

using namespace Bare::System::Events;
using namespace Bare::System::Logging;
using namespace Bare::System::Display;

// class CustomEvent : public Event
// {
//     const char *data;

// public:
//     CustomEvent(const char *data)
//     {
//         this->data = data;
//     }

//     const char *getData() const
//     {
//         return data;
//     }

//     static CustomEvent *Convert(Event *event)
//     {
//         if (auto customEvent = dynamic_cast<CustomEvent *>(event))
//             return customEvent;
//         return nullptr;
//     }
// };

// void customHandler(CustomEvent *event)
// {
//     if (event == nullptr)
//         return;

//     Logger logger = Logger<CustomEvent>();
//     logger.logInformation(event->getData());

//     event->handle();
// }

int main(int argc, char **argv)
{
    Dispatch dispatch;
    // int handle = d.attach(customHandler, CustomEvent::Convert);

    // Event *event = new CustomEvent("Hello World");
    // d.raise(event);

    Window window(dispatch);
    window.initialize("Hello World", 480);

    while (true)
    {
        window.handleEvents();
        dispatch.handleEvents();
    }

    // dispatch.detach(handle);

    return 0;
}
