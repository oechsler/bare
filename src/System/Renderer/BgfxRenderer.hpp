#ifndef BARE_BGFXRENDERER_HPP
#define BARE_BGFXRENDERER_HPP

#include <memory>

#include "IRenderer.hpp"
#include "System/Logging/Logger.hpp"

using Bare::System::Logging::Logger;
using std::shared_ptr;

namespace Bare::System::Renderer
{

class BgfxRenderer : public IRenderer
{
    // Dependency injection
    // END: Dependency injection

    // Local instances
    Logger<BgfxRenderer> logger;
    // END: Local instances

public:
    ~BgfxRenderer() override;

    void initialize(const IContextHandle &contextHandle) override;

    void render() override;
};

} // namespace Bare::System::Renderer

#endif //BARE_BGFXRENDERER_HPP
