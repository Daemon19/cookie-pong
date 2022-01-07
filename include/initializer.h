#pragma once

#include <SDL2/SDL.h>

namespace cookie
{
    struct Initializer
    {
        ~Initializer();

        void InitSdl(Uint32 flags = SDL_INIT_EVERYTHING);
        void InitTtf();
    };
}