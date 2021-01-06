#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include "Hypodermic/Hypodermic.h"

#include "IApplication.hpp"
#include "System/Events/IDispatch.hpp"
#include "System/Display/IWindow.hpp"
#include "System/Logging/Logger.hpp"
#include "System/Display/WindowCloseEvent.hpp"

using Bare::System::Display::IWindow;
using Bare::System::Display::WindowCloseEvent;
using Bare::System::Events::IDispatch;
using Bare::System::Logging::Logger;
using Hypodermic::Container;
using Hypodermic::ContainerBuilder;
using std::shared_ptr;

namespace Bare::System
{

class Application : public IApplication
{
    // Dependency injection
    ContainerBuilder *const containerBuilder;

    shared_ptr<Container> container;
    shared_ptr<IDispatch> dispatch;
    shared_ptr<IWindow> window;
    // END: Dependency injection

    // Local instances
    Logger<Application> logger;
    // END: Local instances

    // Variables / properties
    bool running;
    // END: Variables / properties

    // Event handlers
    int onWindowCloseHandle;
    void onWindowClose(WindowCloseEvent *event);
    // END: Event handlers

    void initialize();

public:
    explicit Application(ContainerBuilder *containerBuilder);
    ~Application() override;

    void run() override;
};

} // namespace Bare::System

#endif // APPLICATION_HPP
