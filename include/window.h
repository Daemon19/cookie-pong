#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace cookie
{
    class Window
    {
    public:
        const std::string kTitle;
        const int kWidth, kHeight;

    private:
        SDL_Window *window_ = nullptr;
        SDL_Renderer *renderer_ = nullptr;

    public:
        Window(const Window &) = delete;

        Window(const std::string &title, int p_width, int p_height)
            : kTitle(title), kWidth(p_width), kHeight(p_height) {}
        ~Window();

        // Return true jika berhasil
        bool Init();

        SDL_Window *window() { return window_; }
        SDL_Renderer *renderer() { return renderer_; }
    };
}