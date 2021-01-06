#include "Application.hpp"

#include "System/Events/Dispatch.hpp"
#include "System/Display/SdlWindow.hpp"
#include "System/Renderer/BgfxRenderer.hpp"

using Bare::System::Renderer::BgfxRenderer;
using Bare::System::Display::SdlWindow;
using Bare::System::Events::Dispatch;
using Bare::System::Display::AspectRatio;
using Bare::System::Events::Handler;

namespace Bare::System
{

void Application::onWindowClose(WindowCloseEvent *const event)
{
    running = false;

    event->handle();
}

Application::Application(ContainerBuilder *containerBuilder)
    : containerBuilder(containerBuilder), running(true), onWindowCloseHandle(0)
{
    logger.logInformation("Bare is warming up");

    // Register default dependency injection modules
    containerBuilder->registerType<Dispatch>().as<IDispatch>().singleInstance();
    containerBuilder->registerType<SdlWindow>().as<IWindow>().singleInstance();
    containerBuilder->registerType<BgfxRenderer>().as<IRenderer>().singleInstance();
}

Application::~Application()
{
    logger.logInformation("Hold on! We're going down");

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
    onWindowCloseHandle = dispatch->attach([this](Event* event) {
        onWindowClose(WindowCloseEvent::Convert(event));
    });

    // Initialize the window
    window->initialize("Bare", 720, AspectRatio(16, 9), 1.2f);

    logger.logInformation("Ready! - Userland awaits you");
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
