#pragma once

#include <SDL2/SDL.h>
#include "window.h"

namespace cookie
{
    class Texture
    {
    private:
        SDL_Texture *tex_ = nullptr;
        int w_, h_;

    public:
        ~Texture();

        bool Init(SDL_Texture *tex);
        bool Init(Window &window, SDL_Surface *surf);

        SDL_Texture *get() { return tex_; }
        int w() { return w_; }
        int h() { return h_; }
    };
}