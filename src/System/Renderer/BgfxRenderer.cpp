#include "BgfxRenderer.hpp"

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

using bgfx::renderFrame;
using bgfx::PlatformData;
using bgfx::Init;
using bgfx::init;
using bgfx::setDebug;
using bgfx::shutdown;

namespace Bare::System::Renderer
{

void BgfxRenderer::onWindowRender(WindowRenderEvent *const event)
{
    if (event == nullptr)
        return;

    render();

    event->handle();
}

BgfxRenderer::BgfxRenderer(const shared_ptr<IDispatch> &dispatch, const shared_ptr<IWindow> &window)
    : _dispatch(dispatch), _window(window), _initialized(false), _onWindowRenderHandle(nullptr)
{
}

BgfxRenderer::~BgfxRenderer()
{
    if (!_initialized)
        return;

    _dispatch->detach(_onWindowRenderHandle);

    shutdown();

    _logger.logInformation("Successfully destroyed the bgfx renderer");
}

void BgfxRenderer::initialize()
{
    renderFrame();

    PlatformData platformData;
    auto contextHandle = _window->getContextHandle();

    platformData.ndt = contextHandle->getDisplayTarget();
    platformData.nwh = contextHandle->getWindowHandle();

    delete contextHandle;

    platformData.context = nullptr;
    platformData.backBuffer = nullptr;
    platformData.backBufferDS = nullptr;

    Init initParams;
    
    initParams.platformData = platformData;
    
    init(initParams);
    setDebug(BGFX_DEBUG_TEXT);

    _onWindowRenderHandle = _dispatch->attach([this](Event *event)
    {
       onWindowRender(WindowRenderEvent::Convert(event));
    });

    _logger.logInformation("Successfully initialized bgfx renderer");
    _initialized = true;
}

void BgfxRenderer::render()
{
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x000000ff, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, 1280, 720);

    bgfx::dbgTextClear();
    bgfx::dbgTextPrintf(5, 2, 0x0f, "Hello World");

    bgfx::touch(0);

    bgfx::frame();
}

} // namespace Bare::System::Renderer
