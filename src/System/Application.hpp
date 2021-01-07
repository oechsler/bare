#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include "Hypodermic/Hypodermic.h"

#include "IApplication.hpp"
#include "System/Events/IDispatch.hpp"
#include "System/Display/IWindow.hpp"
#include "System/Renderer/IRenderer.hpp"
#include "System/Logging/Logger.hpp"
#include "System/Display/WindowCloseEvent.hpp"

using Bare::System::Display::IWindow;
using Bare::System::Events::HandlerIdentifier;
using Bare::System::Display::IWindowCloseHandler;
using Bare::System::Display::WindowCloseEvent;
using Bare::System::Events::IDispatch;
using Bare::System::Logging::Logger;
using Bare::System::Renderer::IRenderer;
using Hypodermic::Container;
using Hypodermic::ContainerBuilder;
using std::shared_ptr;

namespace Bare::System
{

class Application : public IApplication, private IWindowCloseHandler
{
    // Dependency injection
    ContainerBuilder *const _containerBuilder;

    shared_ptr<Container> _container;
    shared_ptr<IDispatch> _dispatch;
    shared_ptr<IWindow> _window;
    shared_ptr<IRenderer> _renderer;
    // END: Dependency injection

    // Local instances
    Logger<Application> _logger;
    // END: Local instances

    // Variables / properties
    bool _running;
    // END: Variables / properties

    // Event handlers
    HandlerIdentifier _onWindowCloseHandle;
    void onWindowClose(WindowCloseEvent *event) override;
    // END: Event handlers

    void initialize();

public:
    explicit Application(ContainerBuilder *containerBuilder);
    ~Application() override;

    void run() override;
};

} // namespace Bare::System

#endif // APPLICATION_HPP
