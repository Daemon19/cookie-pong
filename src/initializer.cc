#include "initializer.h"
#include "log.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace cookie
{
    Initializer::~Initializer()
    {
        SDL_Quit();
        TTF_Quit();
    }

    bool Initializer::InitSdl(Uint32 flags)
    {

        if (SDL_Init(flags) < 0)
        {
            log::SdlError("Gagal menginisialisasi SDL");
            return false;
        }
        return true;
    }

    bool Initializer::InitTtf()
    {
        if (TTF_Init() == -1)
        {
            log::SdlError("Gagal menginisialisasi SDL_ttf");
            return false;
        }
        return true;
    }
}