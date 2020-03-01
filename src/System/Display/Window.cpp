#include "Window.hpp"

#include "WindowCloseEvent.hpp"
#include "System/Exception.hpp"

using Bare::System::Exception;

namespace Bare::System::Display
{

Window::Window(Dispatch *dispatch)
    : dispatch(dispatch)
{
}

Window::~Window()
{
    // TODO: Detach event handlers

    SDL_DestroyWindow(windowHandle);

    SDL_Quit();
}

void Window::initialize(const string &title, int width, AspectRatio aspect, float scale)
{
    initialWidth = width * scale;
    initialHeight = aspect.getHeight(width) * scale;

    this->width = initialWidth;
    this->height = initialHeight;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
    {
        auto error = string(SDL_GetError());
        auto errorMessage = "SDL could not be initialized: " + error;

        logger.logError(errorMessage);
        throw Exception(errorMessage);
    }

    // Default window settings for the SDL sub-system
    auto position = SDL_WINDOWPOS_UNDEFINED;
    auto flags = SDL_WINDOW_RESIZABLE |
                 SDL_WINDOW_ALLOW_HIGHDPI |
                 SDL_WINDOW_SHOWN;

    windowHandle = SDL_CreateWindow(title.c_str(), position, position,
                                    this->width, this->height, flags);
    if (windowHandle == nullptr)
    {
        auto error = string(SDL_GetError());
        auto errorMessage = "Window could not be created: " + error;

        logger.logError(errorMessage);
        throw Exception(errorMessage);
    }

    SDL_SetWindowMinimumSize(windowHandle, this->width, this->height);
}

void Window::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            auto windowCloseEvent = new WindowCloseEvent();
            dispatch->raise(windowCloseEvent);
            break;
        }
    }
}

} // namespace Bare::System::Display
