#ifndef I_WINDOW_HPP
#define I_WINDOW_HPP

#include <string>

#include "AspectRatio.hpp"

using std::string;

namespace Bare::System::Display
{

class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual void initialize(const string &title, int width, AspectRatio aspect, float scale) = 0;

    virtual void handleEvents() = 0;
};

} // namespace Bare::System::Display

#endif // I_WINDOW_HPP
