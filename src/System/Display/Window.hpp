#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>
#include <SDL2/SDL.h>

#include "IWindow.hpp"
#include "System/Events/IDispatch.hpp"
#include "System/Logging/Logger.hpp"

using Bare::System::Events::IDispatch;
using Bare::System::Logging::Logger;
using std::shared_ptr;

namespace Bare::System::Display
{

class Window : public IWindow
{
    // Dependency injection
    shared_ptr<IDispatch> dispatch;
    // END: Dependency injection

    // Local instances
    Logger<Window> logger;
    // END: Local instances

    // Variables / properties
    SDL_Window *windowHandle;
    int initialWidth, initialHeight;
    int width, height;
    // END: Variables / properties

    // Event handlers
    // TODO: Add event handler references here
    // END: Event handlers

public:
    Window(const shared_ptr<IDispatch> &dispatch);
    ~Window();

    void initialize(const string &title, int width, AspectRatio aspect = AspectRatio(16, 9), float scale = 1) override;

    void handleEvents() override;
};

} // namespace Bare::System::Display

#endif // WINDOW_HPP
