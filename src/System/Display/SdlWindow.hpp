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
    shared_ptr<IDispatch> _dispatch;
    // END: Dependency injection

    // Local instances
    Logger<SdlWindow> _logger;
    // END: Local instances

    // Variables / properties
    SDL_Window *_windowHandle;
    AspectRatio _aspect;
    int _initialWidth, _initialHeight;
    int _width, _height;
    // END: Variables / properties

    // Event handlers
    // TODO: Add event handler references here
    // END: Event handlers

public:
    explicit SdlWindow(const shared_ptr<IDispatch> &dispatch);
    ~SdlWindow() override;

    void initialize(const string &title, int size, const AspectRatio &aspect, float scale) override;

    void handleEvents() override;

    // Getters and Setters
    [[nodiscard]] const IContextHandle* getContextHandle() const override;

    [[nodiscard]] const AspectRatio& getAspectRatio() const override;

    [[nodiscard]] int getWidth() const override;

    [[nodiscard]] int getHeight() const override;
    // END: Getters and Setters
};

} // namespace Bare::System::Display

#endif // WINDOW_HPP
