#ifndef BARE_ICONTEXTHANDLE_HPP
#define BARE_ICONTEXTHANDLE_HPP

namespace Bare::System::Display
{

class IContextHandle
{
public:
    virtual ~IContextHandle() = default;

    [[nodiscard]] virtual void *getDisplayTarget() const = 0;

    [[nodiscard]] virtual void *getWindowHandle() const = 0;
};

} // namespace Bare::System::Display

#endif //BARE_ICONTEXTHANDLE_HPP
