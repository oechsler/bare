#ifndef BARE_SDLCONTEXTHANDLE_HPP
#define BARE_SDLCONTEXTHANDLE_HPP

#include "IContextHandle.hpp"


namespace Bare::System::Display
{

class SdlContextHandle : public IContextHandle
{
    void* _displayTarget;
    void* _windowHandle;

public:
    explicit SdlContextHandle(void *displayHandle, void *windowHandle);
    ~SdlContextHandle() override = default;

    [[nodiscard]] void *getDisplayTarget() const override;

    [[nodiscard]] void *getWindowHandle() const override;
};

} // namespace Bare::System::Display

#endif //BARE_SDLCONTEXTHANDLE_HPP
