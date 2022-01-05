#include "window.h"
#include "log.h"
#include <SDL2/SDL.h>
#include <iostream>

namespace cookie
{
    Window::~Window()
    {
        if (window_ != nullptr)
        {
            SDL_DestroyWindow(window_);
            window_ = nullptr;
        }

        if (renderer_ != nullptr)
        {
            SDL_DestroyRenderer(renderer_);
            renderer_ = nullptr;
        }
    }

    bool Window::Init()
    {
        window_ = SDL_CreateWindow(title_, SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED, width_, height_, 0);
        if (window_ == nullptr)
        {
            log::SdlError("Gagal membuat window");
            return false;
        }

        renderer_ = SDL_CreateRenderer(window_, -1,
                                       SDL_RENDERER_ACCELERATED |
                                           SDL_RENDERER_PRESENTVSYNC);
        if (renderer_ == nullptr)
        {
            log::SdlError("Gagal membuat renderer");
            return false;
        }

        return true;
    }
}