#include "AspectRatio.hpp"

namespace Bare::System::Display
{

AspectRatio::AspectRatio()
    : x(0), y(0)
{
}

AspectRatio::AspectRatio(int x, int y)
    : x(x), y(y)
{
}

int AspectRatio::getHeight(int width)
{
    return width / x * y;
}

int AspectRatio::getWidth(int height)
{
    return height / y * x;
}

} // namespace Bare::System::Display
