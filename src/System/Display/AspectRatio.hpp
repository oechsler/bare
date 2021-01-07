#ifndef ASPECT_RATIO_HPP
#define ASPECT_RATIO_HPP

namespace Bare::System::Display
{

struct AspectRatio
{
    int _x, _y;

    AspectRatio();
    AspectRatio(int x, int y);

    [[nodiscard]] int getHeight(int width) const;
    [[nodiscard]] int getWidth(int height) const;
};

} // namespace Bare::System::Display

#endif // ASPECT_RATIO_HPP
