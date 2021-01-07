#include "AspectRatio.hpp"

namespace Bare::System::Display
{

AspectRatio::AspectRatio()
    : _x(0), _y(0)
{
}

AspectRatio::AspectRatio(int x, int y)
    : _x(x), _y(y)
{
}

int AspectRatio::getHeight(int width) const
{
    return width / _x * _y;
}

int AspectRatio::getWidth(int height) const
{
    return height / _y * _x;
}

} // namespace Bare::System::Display
