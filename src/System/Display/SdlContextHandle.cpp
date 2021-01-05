#include "SdlContextHandle.hpp"

namespace Bare::System::Display
{

SdlContextHandle::SdlContextHandle(void *displayHandle, void *windowHandle)
    : displayHandle(displayHandle), windowHandle(windowHandle)
{
}

void *SdlContextHandle::getDisplayHandle() const
{
    return displayHandle;
}

void *SdlContextHandle::getWindowHandle() const
{
    return windowHandle;
}


} // namespace Bare::System::Display