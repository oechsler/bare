#ifndef I_WINDOW_HPP
#define I_WINDOW_HPP

#include <string>

#include "AspectRatio.hpp"
#include "IContextHandle.hpp"

using std::string;

namespace Bare::System::Display
{

class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual void initialize(const string &title, int width, const AspectRatio &aspect, float scale) = 0;

    virtual void handleEvents() = 0;

    // Getters and Setters
    [[nodiscard]] virtual const IContextHandle* getContextHandle() const = 0;

    [[nodiscard]] virtual const AspectRatio& getAspectRatio() const = 0;

    [[nodiscard]] virtual int getWidth() const = 0;

    [[nodiscard]] virtual int getHeight() const = 0;
    // END: Getters and Setters
};

} // namespace Bare::System::Display

#endif // I_WINDOW_HPP
