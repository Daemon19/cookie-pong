#pragma once

#include <SDL.h>
#include <SDL_mixer.h>

namespace cookie
{
    struct Initializer
    {
        ~Initializer();

        void InitSdl(Uint32 flags = SDL_INIT_EVERYTHING);
        void InitTtf();
        void InitMixer(int flags = MIX_INIT_FLAC | MIX_INIT_MOD |
                                   MIX_INIT_MP3 | MIX_INIT_OGG);
    };
}