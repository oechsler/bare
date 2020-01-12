#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <SDL2/SDL.h>
#include <SDL_gpu.h>

using std::string;

namespace Bare::System
{

class Window
{
    SDL_Window *window;

    int initialWidth, initalHeight;
    int width, height;
    float dpiScale, scale;
    bool focused;

    GPU_Target *target;
    bool running;

    void handleEvents(SDL_Event *event);
    void handleWindowEvents(const SDL_WindowEvent *sender);

public:
    Window(string title, int width, int aspectX = 16, int aspectY = 9, float scale = 1);
    ~Window();

    void run();
};

} // namespace Bare::System

#endif // WINDOW_HPP
