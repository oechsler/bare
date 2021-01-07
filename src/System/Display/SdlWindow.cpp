#include "SdlWindow.hpp"

#include <SDL2/SDL_syswm.h>

#include "WindowCloseEvent.hpp"
#include "SdlContextHandle.hpp"
#include "System/Exception.hpp"

using Bare::System::Exception;

namespace Bare::System::Display
{

SdlWindow::SdlWindow(const shared_ptr<IDispatch> &dispatch)
    : _dispatch(dispatch), _windowHandle(nullptr), _aspect(1, 1), _initialWidth(0), _initialHeight(0),
      _width(0), _height(0)
{
}

SdlWindow::~SdlWindow()
{
    // TODO: Detach event handlers

    SDL_DestroyWindow(_windowHandle);

    SDL_Quit();
}

void SdlWindow::initialize(const string &title, int size, const AspectRatio &aspect, float scale)
{
    _aspect = aspect;
    _initialWidth = (int) ((float) size * scale);
    _initialHeight = (int) ((float) aspect.getHeight(size) * scale);

    _width = _initialWidth;
    _height = _initialHeight;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
    {
        auto error = string(SDL_GetError());
        auto errorMessage = "SDL could not be initialized: " + error;

        _logger.logError(errorMessage);
        throw Exception(errorMessage);
    }

    // Default window settings for the SDL sub-system
    auto position = SDL_WINDOWPOS_UNDEFINED;
    auto flags = SDL_WINDOW_RESIZABLE |
                 SDL_WINDOW_ALLOW_HIGHDPI |
                 SDL_WINDOW_SHOWN;

    _windowHandle = SDL_CreateWindow(title.c_str(), position, position, _width, _height, flags);
    if (_windowHandle == nullptr)
    {
        auto error = string(SDL_GetError());
        auto errorMessage = "SDL window could not be created: " + error;

        _logger.logFatal(errorMessage);
    }

    SDL_SetWindowMinimumSize(_windowHandle, _width, _height);
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
            _dispatch->raise(windowCloseEvent);
            break;
        }
    }
}

const IContextHandle* SdlWindow::getContextHandle() const
{
    SDL_SysWMinfo wmInfo;
    SDL_VERSION(&wmInfo.version)

    if (!SDL_GetWindowWMInfo(_windowHandle, &wmInfo))
    {
        auto error = string(SDL_GetError());
        auto errorMessage = "SDL window manager info could not be created: " + error;

        _logger.logFatal(errorMessage);
    }

    switch (wmInfo.subsystem)
    {
    case SDL_SYSWM_COCOA:
        return new SdlContextHandle(nullptr, wmInfo.info.cocoa.window);
    default:
        auto errorMessage = "SDL does not support this platform";

        _logger.logError(errorMessage);
    }

    return nullptr;
}

const AspectRatio & SdlWindow::getAspectRatio() const
{
    return _aspect;
}

int SdlWindow::getWidth() const
{
    return _width;
}

int SdlWindow::getHeight() const
{
    return _height;
}

} // namespace Bare::System::Display
