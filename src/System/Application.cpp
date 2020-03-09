#include "Application.hpp"

#include "System/Events/Dispatch.hpp"
#include "System/Display/Window.hpp"

using Bare::System::Display::Window;
using Bare::System::Events::Dispatch;

namespace Bare::System
{

void Application::onWindowClose(WindowCloseEvent *const event)
{
    running = false;

    event->handle();
}

Application::Application(ContainerBuilder *containerBuilder)
    : containerBuilder(containerBuilder), running(true)
{
    logger.logInformation("Welcome to the Bare rendering framework");

    // Register default dependency injection modules
    containerBuilder->registerType<Dispatch>().as<IDispatch>().singleInstance();
    containerBuilder->registerType<Window>().as<IWindow>().singleInstance();
}

Application::~Application()
{
    logger.logInformation("Bare is terminating ...");

    // Detach event handlers
    dispatch->detach(onWindowCloseHandle);
}

void Application::initialize()
{
    // Build / generate the IoC container
    container = containerBuilder->build();

    // Resolve dependencies (manually)
    dispatch = container->resolve<IDispatch>();
    window = container->resolve<IWindow>();

    // Attach event handlers
    onWindowCloseHandle = dispatch->attach(ClassHandler(&Application::onWindowClose, WindowCloseEvent::Convert));

    // Initialize the window
    window->initialize("Bare", 720);
}

void Application::run()
{
    initialize();

    while (running)
    {
        window->handleEvents();

        dispatch->handleEvents();
    }
}

} // namespace Bare::System
