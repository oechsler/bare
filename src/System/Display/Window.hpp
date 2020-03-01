#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "IWindow.hpp"
#include "System/Events/Dispatch.hpp"
#include "System/Logging/Logger.hpp"

#include <SDL2/SDL.h>

using Bare::System::Events::Dispatch;
using Bare::System::Logging::Logger;

namespace Bare::System::Display
{

class Window : public IWindow
{
    Dispatch *dispatch;
    Logger<Window> logger;

    SDL_Window *windowHandle;
    int initialWidth, initialHeight;
    int width, height;

public:
    Window(Dispatch *dispatch);
    ~Window();

    void initialize(const string &title, int width, AspectRatio aspect = AspectRatio(16, 9), float scale = 1) override;

    void handleEvents() override;
};

} // namespace Bare::System::Display

#endif // WINDOW_HPP
