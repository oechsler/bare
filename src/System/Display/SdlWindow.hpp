#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>
#include <SDL2/SDL.h>

#include "IWindow.hpp"
#include "System/Events/IDispatch.hpp"
#include "System/Renderer/IRenderer.hpp"
#include "System/Logging/Logger.hpp"

using Bare::System::Events::IDispatch;
using Bare::System::Renderer::IRenderer;
using Bare::System::Logging::Logger;
using std::shared_ptr;

namespace Bare::System::Display
{

class SdlWindow : public IWindow
{
    // Dependency injection
    shared_ptr<IDispatch> dispatch;

    shared_ptr<IRenderer> renderer;
    // END: Dependency injection

    // Local instances
    Logger<SdlWindow> logger;
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
    explicit SdlWindow(const shared_ptr<IDispatch> &dispatch, const shared_ptr<IRenderer> &renderer);
    ~SdlWindow() override;

    void initialize(const string &title, int size, AspectRatio aspect, float scale) override;

    void handleEvents() override;
};

} // namespace Bare::System::Display

#endif // WINDOW_HPP
