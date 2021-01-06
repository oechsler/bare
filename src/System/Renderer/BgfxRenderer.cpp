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

BgfxRenderer::~BgfxRenderer()
{
    shutdown();

    logger.logInformation("Successfully destroyed the bgfx renderer");
}

void BgfxRenderer::initialize(const IContextHandle &contextHandle)
{
    renderFrame();

    PlatformData platformData;

    platformData.ndt = contextHandle.getDisplayHandle();
    platformData.nwh = contextHandle.getWindowHandle();

    platformData.context = nullptr;
    platformData.backBuffer = nullptr;
    platformData.backBufferDS = nullptr;

    Init initParams;
    
    initParams.platformData = platformData;
    
    init(initParams);
    setDebug(BGFX_DEBUG_TEXT);

    logger.logInformation("Successfully initialized bgfx renderer");
}

void BgfxRenderer::render()
{
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x333333ff, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, 1280, 720);

    bgfx::dbgTextClear();
    bgfx::dbgTextPrintf(5, 2, 0x0f, "Hello World");

    bgfx::touch(0);

    bgfx::frame();
}

} // namespace Bare::System::Renderer
