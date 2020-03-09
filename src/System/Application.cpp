#include "Application.hpp"

namespace Bare::System
{

void Application::onWindowClose(WindowCloseEvent *event)
{
    running = false;

    event->handle();
}

Application::Application()
    : window(&dispatch), running(true)
{
    logger.logInformation("The Bare rendering framework");

    // Attach event handlers
    onWindowCloseHandle = dispatch.attach(ClassHandler(&Application::onWindowClose, WindowCloseEvent::Convert));

    window.initialize("Hello World", 720);
}

Application::~Application()
{
    logger.logInformation("Terminating");

    // Detach event handlers
    dispatch.detach(onWindowCloseHandle);
}

void Application::run()
{
    while (running)
    {
        window.handleEvents();

        dispatch.handleEvents();
    }
}

} // namespace Bare::System
