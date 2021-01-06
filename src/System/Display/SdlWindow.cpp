#include "SdlWindow.hpp"

#include <SDL2/SDL_syswm.h>

#include "WindowCloseEvent.hpp"
#include "SdlContextHandle.hpp"
#include "System/Exception.hpp"

using Bare::System::Exception;

namespace Bare::System::Display
{

SdlWindow::SdlWindow(const shared_ptr<IDispatch> &dispatch, const shared_ptr<IRenderer> &renderer)
    : dispatch(dispatch), renderer(renderer), windowHandle(nullptr), initialWidth(0), initialHeight(0),
    width(0), height(0)
{
}

SdlWindow::~SdlWindow()
{
    // TODO: Detach event handlers

    SDL_DestroyWindow(windowHandle);

    SDL_Quit();
}

void SdlWindow::initialize(const string &title, int size, AspectRatio aspect, float scale)
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

        logger.logFatal(errorMessage);
    }

    SDL_SetWindowMinimumSize(windowHandle, width, height);

    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version);
    if (!SDL_GetWindowWMInfo(windowHandle, &wmInfo))
    {
        auto error = string(SDL_GetError());
        auto errorMessage = "SDL window manager info could not be created: " + error;

        logger.logFatal(errorMessage);
    }

    const SdlContextHandle* contextHandle;
    switch (wmInfo.subsystem) {
        case SDL_SYSWM_COCOA:
            contextHandle = new SdlContextHandle(nullptr, wmInfo.info.cocoa.window);

            break;
        default:
            auto errorMessage = "SDL does not support this platform";

            logger.logError(errorMessage);
            throw Exception(errorMessage);
    }

    renderer->initialize(*contextHandle);

    delete contextHandle;
}

void SdlWindow::handleEvents()
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

    renderer->render();
}

} // namespace Bare::System::Display
