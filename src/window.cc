#include "window.h"
#include "cookie_error.h"
#include <string>

namespace cookie
{
    Window::Window(const std::string &title, int width, int height,
                   Uint32 window_flags, Uint32 renderer_flags)
        : window_(nullptr), renderer_(nullptr), w_(width), h_(height)
    {
        window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED, width, height, window_flags);

        if (window_ == nullptr)
            throw SdlError("Gagal membuat window");

        renderer_ = SDL_CreateRenderer(window_, -1, renderer_flags);

        if (renderer_ == nullptr)
            throw SdlError("Gagal membuat renderer");
    }

    Window::~Window()
    {
        if (window_ != nullptr)
            SDL_DestroyWindow(window_);

        if (renderer_ != nullptr)
            SDL_DestroyRenderer(renderer_);
    }

    void Window::Fill(const SDL_Color &color)
    {
        SetDrawColor(color);
        Clear();
    }
}