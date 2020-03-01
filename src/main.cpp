#include "System/Logging/Logger.hpp"
#include "System/Events/Dispatch.hpp"
#include "System/Display/Window.hpp"
#include "System/Display/WindowCloseEvent.hpp"

#include <fmt/format.h>
#include <iostream>

using namespace Bare::System::Events;
using namespace Bare::System::Logging;
using namespace Bare::System::Display;

bool running = true;

void onWindowClose(WindowCloseEvent *event)
{
    if (event == nullptr)
        return;

    running = false;
    event->handle();
}

int main(int argc, char **argv)
{
    Dispatch dispatch;

    int handle = dispatch.attach(onWindowClose, WindowCloseEvent::Convert);

    Window window(&dispatch);
    window.initialize("Hello World", 480);

    while (running)
    {
        window.handleEvents();
        dispatch.handleEvents();
    }

    dispatch.detach(handle);

    return 0;
}
