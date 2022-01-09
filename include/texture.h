#pragma once

#include "window.h"
#include <SDL.h>

namespace cookie
{
    class Texture
    {
    private:
        SDL_Texture *tex_;
        int w_, h_;
        Uint32 format_;
        int access_;

    public:
        Texture() : tex_(nullptr), w_(0), h_(0), format_(0), access_(0) {}
        Texture(SDL_Texture *tex);
        Texture(Window &window, SDL_Surface *surf);
        ~Texture();

        SDL_Texture *sdl_tex() { return tex_; }
        int w() const { return w_; }
        int h() const { return h_; }
        Uint32 format() const { return format_; }
        int access() const { return access_; }
    };
}