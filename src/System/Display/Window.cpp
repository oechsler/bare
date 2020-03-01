#include "Window.hpp"

namespace Bare::System::Display
{

Window::Window(Dispatch dispatch)
    : dispatch(dispatch)
{
}

Window::~Window()
{
    // TODO: Detach event handlers
}

void Window::initialize(string title, int width, AspectRatio aspect, float scale)
{
    initialWidth = width * scale;
    initialHeight = aspect.getHeight(width) * scale;

    this->width = initialWidth;
    this->height = initialHeight;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
    {
        auto error = SDL_GetError();
        logger.logFatal("SDL initialized with error: {}", error);
    }

    // Default window settings for the SDL sub-system
    auto position = SDL_WINDOWPOS_UNDEFINED;
    auto flags = SDL_WINDOW_RESIZABLE |
                 SDL_WINDOW_ALLOW_HIGHDPI |
                 SDL_WINDOW_SHOWN;

    windowHandle = SDL_CreateWindow(title.c_str(), position, position,
                                    this->width, this->height, flags);

    SDL_SetWindowMinimumSize(windowHandle, this->width, this->height);
}

void Window::handleEvents()
{
}

} // namespace Bare::System::Display
