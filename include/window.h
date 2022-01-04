#pragma once

#include <SDL2/SDL.h>

namespace cookie
{
    class Window
    {
    private:
        const char *title_;
        int width_, height_;
        SDL_Window *window_ = nullptr;
        SDL_Renderer *renderer_ = nullptr;

    public:
        Window(const char *title, int width, int height)
            : title_(title), width_(width), height_(height) {}
        ~Window();

        // Return true jika berhasil
        bool Init();

        inline SDL_Window *window() { return window_; }
        inline SDL_Renderer *renderer() { return renderer_; }
    };
}