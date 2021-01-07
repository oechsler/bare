#ifndef BARE_IRENDERER_HPP
#define BARE_IRENDERER_HPP

#include "System/Display/IContextHandle.hpp"

using Bare::System::Display::IContextHandle;

namespace Bare::System::Renderer
{

class IRenderer
{
public:
    virtual ~IRenderer() = default;

    virtual void initialize() = 0;

    virtual void render() = 0;
};

} // namespace Bare::System::Renderer

#endif //BARE_IRENDERER_HPP
