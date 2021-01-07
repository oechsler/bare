#ifndef BARE_BGFXRENDERER_HPP
#define BARE_BGFXRENDERER_HPP

#include <memory>

#include "IRenderer.hpp"
#include "System/Events/IDispatch.hpp"
#include "System/Display/IWindow.hpp"
#include "System/Display/WindowRenderEvent.hpp"
#include "System/Logging/Logger.hpp"

using Bare::System::Events::HandlerIdentifier;
using Bare::System::Events::IDispatch;
using Bare::System::Display::IWindow;
using Bare::System::Display::WindowRenderEvent;
using Bare::System::Display::IWindowRenderHandler;
using Bare::System::Logging::Logger;
using std::shared_ptr;

namespace Bare::System::Renderer
{

class BgfxRenderer : public IRenderer, private IWindowRenderHandler
{
    // Dependency injection
    shared_ptr<IDispatch> _dispatch;
    shared_ptr<IWindow> _window;
    // END: Dependency injection

    // Local instances
    Logger<BgfxRenderer> _logger;
    // END: Local instances

    // Variables / properties
    bool _initialized;
    // END: Variables / properties

    // Event handlers
    HandlerIdentifier _onWindowRenderHandle;
    void onWindowRender(WindowRenderEvent *event) override;
    // END: Event handlers

public:
    explicit BgfxRenderer(const shared_ptr<IDispatch> &dispatch, const shared_ptr<IWindow> &window);
    ~BgfxRenderer() override;

    void initialize() override;

    void render() override;
};

} // namespace Bare::System::Renderer

#endif //BARE_BGFXRENDERER_HPP
