#include "SdlContextHandle.hpp"

namespace Bare::System::Display
{

SdlContextHandle::SdlContextHandle(void *displayHandle, void *windowHandle)
    : _displayTarget(displayHandle), _windowHandle(windowHandle)
{
}

void *SdlContextHandle::getDisplayTarget() const
{
    return _displayTarget;
}

void *SdlContextHandle::getWindowHandle() const
{
    return _windowHandle;
}


} // namespace Bare::System::Display