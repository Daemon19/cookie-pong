#pragma once

#include <SDL2/SDL.h>

namespace cookie
{
    class Initializer
    {
    public:
        ~Initializer();

        bool InitSdl(Uint32 flags = SDL_INIT_EVERYTHING);
        bool InitTtf();
    };
}