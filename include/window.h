#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace cookie
{
    class Window
    {
    private:
        SDL_Window *window_;
        SDL_Renderer *renderer_;

    public:
        Window(){};
        Window(const Window &) = delete;

        Window(const std::string &title, int width, int height,
               Uint32 window_flags = 0,
               Uint32 renderer_flags = SDL_RENDERER_ACCELERATED |
                                       SDL_RENDERER_PRESENTVSYNC);
        ~Window();

        SDL_Window *window() { return window_; }
        SDL_Renderer *renderer() { return renderer_; }
    };
}