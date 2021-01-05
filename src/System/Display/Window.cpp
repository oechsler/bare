#include "Window.hpp"

#include "WindowCloseEvent.hpp"
#include "System/Exception.hpp"

using Bare::System::Exception;

namespace Bare::System::Display
{

Window::Window(const shared_ptr<IDispatch> &dispatch)
    : dispatch(dispatch), windowHandle(nullptr), initialWidth(0), initialHeight(0), width(0), height(0)
{
}

Window::~Window()
{
    // TODO: Detach event handlers

    SDL_DestroyWindow(windowHandle);

    SDL_Quit();
}

void Window::initialize(const string &title, int size, AspectRatio aspect, float scale)
{
    initialWidth = (int) ((float) size * scale);
    initialHeight = (int) ((float) aspect.getHeight(size) * scale);

    width = initialWidth;
    height = initialHeight;

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

    windowHandle = SDL_CreateWindow(title.c_str(), position, position, width, height, flags);
    if (windowHandle == nullptr)
    {
        auto error = string(SDL_GetError());
        auto errorMessage = "SDL window could not be created: " + error;

        logger.logError(errorMessage);
        throw Exception(errorMessage);
    }

    SDL_SetWindowMinimumSize(windowHandle, width, height);
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

    SDL_Renderer* renderer = SDL_CreateRenderer(windowHandle, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

} // namespace Bare::System::Display
