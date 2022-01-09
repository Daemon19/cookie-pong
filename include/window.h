#pragma once

#include <SDL.h>
#include <string>

namespace cookie
{
    class Window
    {
    private:
        SDL_Window *window_;
        SDL_Renderer *renderer_;
        int w_, h_;

    public:
        Window(const Window &) = delete;

        Window(const std::string &title, int width, int height,
               Uint32 window_flags = 0,
               Uint32 renderer_flags = SDL_RENDERER_ACCELERATED |
                                       SDL_RENDERER_PRESENTVSYNC);
        ~Window();

        SDL_Window *window() { return window_; }
        SDL_Renderer *renderer() { return renderer_; }

        void SetDrawColor(const SDL_Color &color)
        {
            SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
        }

        void Clear() { SDL_RenderClear(renderer_); }
        void Fill(const SDL_Color &color);
        void Draw() { SDL_RenderPresent(renderer_); }

        int w() const { return w_; }
        int h() const { return h_; }
    };
}