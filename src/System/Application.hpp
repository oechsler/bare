#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "IApplication.hpp"
#include "System/Events/Dispatch.hpp"
#include "System/Logging/Logger.hpp"
#include "System/Display/Window.hpp"
#include "System/Display/WindowCloseEvent.hpp"

using Bare::System::Display::Window;
using Bare::System::Display::WindowCloseEvent;
using Bare::System::Events::Dispatch;
using Bare::System::Logging::Logger;

namespace Bare::System
{

class Application : public IApplication
{
    Dispatch dispatch;
    Logger<Application> logger;

    Window window;

    bool running;

    int onWindowCloseHandle;
    void onWindowClose(WindowCloseEvent *event);

public:
    Application();
    ~Application();

    void run() override;
};

} // namespace Bare::System

#endif // APPLICATION_HPP
