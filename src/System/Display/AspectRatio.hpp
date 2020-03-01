#ifndef ASPECT_RATIO_HPP
#define ASPECT_RATIO_HPP

namespace Bare::System::Display
{

struct AspectRatio
{
    int x, y;

    AspectRatio();
    AspectRatio(int x, int y);

    int getHeight(int width);
    int getWidth(int height);
};

} // namespace Bare::System::Display

#endif // ASPECT_RATIO_HPP
