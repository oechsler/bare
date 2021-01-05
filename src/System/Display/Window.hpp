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
    explicit Window(const shared_ptr<IDispatch> &dispatch);
    ~Window() override;

    void initialize(const string &title, int size, AspectRatio aspect, float scale) override;

    void handleEvents() override;
};

} // namespace Bare::System::Display

#endif // WINDOW_HPP
