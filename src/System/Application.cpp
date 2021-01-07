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
    if (event == nullptr)
        return;

    _running = false;

    event->handle();
}

Application::Application(ContainerBuilder *containerBuilder)
    : _containerBuilder(containerBuilder), _running(true), _onWindowCloseHandle(nullptr)
{
    _logger.logInformation("Bare is warming up");

    // Register default dependency injection modules
    _containerBuilder->registerType<Dispatch>().as<IDispatch>().singleInstance();
    _containerBuilder->registerType<SdlWindow>().as<IWindow>().singleInstance();
    _containerBuilder->registerType<BgfxRenderer>().as<IRenderer>().singleInstance();
}

Application::~Application()
{
    _logger.logInformation("Hold on! We're going down");

    // Detach event handlers
    _dispatch->detach(_onWindowCloseHandle);
}

void Application::initialize()
{
    // Build / generate the IoC container
    _container = _containerBuilder->build();

    // Resolve dependencies (manually)
    _dispatch = _container->resolve<IDispatch>();
    _window = _container->resolve<IWindow>();
    _renderer = _container->resolve<IRenderer>();

    // Attach event handlers
    _onWindowCloseHandle = _dispatch->attach([this](Event *event)
    {
        onWindowClose(WindowCloseEvent::Convert(event));
    });

    // Initialize the window and renderer
    _window->initialize("Bare", 720, AspectRatio(16, 9), 1.2f);
    _renderer->initialize();

    _logger.logInformation("Ready! - Userland awaits you");
}

void Application::run()
{
    initialize();

    while (_running)
    {
        _window->handleEvents();

        _dispatch->handleEvents();
    }
}

} // namespace Bare::System
