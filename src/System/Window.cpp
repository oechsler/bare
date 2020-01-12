#include "Window.hpp"

namespace Bare::System
{

Window::Window(string title, int width, int aspectX, int aspectY, float scale)
    : initialWidth(width * scale), initalHeight((width / aspectX * aspectY) * scale),
      width(initialWidth), height(initalHeight),
      focused(true), running(true)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
    {
        auto error = SDL_GetError();
        // TODO: Use a logging system here
        throw string("SDL could not be initialized with error: ") + string(error);
    }

    // Initial setting of the created window
    auto position = SDL_WINDOWPOS_UNDEFINED;
    auto flags = SDL_WINDOW_RESIZABLE |
                 SDL_WINDOW_ALLOW_HIGHDPI |
                 SDL_WINDOW_SHOWN;

    window = SDL_CreateWindow(title.c_str(), position, position,
                              this->width, this->height, flags);

    // Set the minmal bounds of the window / initial size
    SDL_SetWindowMinimumSize(window, this->width, this->height);

    auto windowId = SDL_GetWindowID(window);
    GPU_SetInitWindow(windowId);
    GPU_Init(this->width, this->height, GPU_DEFAULT_INIT_FLAGS);

    target = GPU_GetWindowTarget(windowId);

    // Calculate inital render scale
    //int renderWidth, renderHeight;
    //SDL_GetRendererOutputSize(renderer, &renderWidth, &renderHeight);
    //dpiScale, this->scale = (renderWidth / (float) initialWidth + renderHeight / (float) initalHeight) / 2;
}

Window::~Window()
{
    GPU_Quit();

    SDL_DestroyWindow(window);

    // Gracefully quit all SDL sub-systems
    SDL_Quit();
}

void Window::run()
{
    SDL_Event event;
    while (running)
    {
        handleEvents(&event);

        GPU_ClearColor(target, {40, 40, 40, 255});

        GPU_Rotate(45, 0, 0, 1);
        GPU_RectangleFilled2(target, {-50, -50, 100, 100}, {255, 0, 0, 255});
        GPU_Rotate(-45, 0, 0, 1);

        GPU_Rotate(0.5, 0, 0, 1);
        GPU_RectangleFilled2(target, {-50, -50, 100, 100}, {0, 255, 0, 255});

        GPU_Flip(target);

        // TODO: Introduce some real FPS cap here
        SDL_Delay(10);
    }
}

void Window::handleEvents(SDL_Event *event)
{
    while (SDL_PollEvent(event))
    {
        switch (event->type)
        {
        case SDL_QUIT:
            // Exit out of the main loop
            // and terminate the application
            running = false;
            break;
        case SDL_WINDOWEVENT:
            // Handle window specific events here
            handleWindowEvents(&(event->window));
            break;
        default:
            break;
        }
    }
}

void Window::handleWindowEvents(const SDL_WindowEvent *sender)
{
    switch (sender->event)
    {
    case SDL_WINDOWEVENT_RESIZED:
        // Set the current window size properties
        width = sender->data1;
        height = sender->data2;

        // Calculate the current render scale
        int renderWidth, renderHeight;

        // Sets the viewport to the current resolution of the window
        // TODO: Change this to the appropriate scalar in x/y direction
        GPU_SetVirtualResolution(target, width, height);

        //dpiScale = (renderWidth / (float)width + renderHeight / (float)height) / 2;
        //scale = dpiScale * (width < height ? width / (float)initialWidth : height / (float)initalHeight);
        break;
    default:
        break;
    }
}

} // namespace Bare::System
