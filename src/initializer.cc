#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "cookie_error.h"
#include "initializer.h"

namespace cookie
{
    Initializer::~Initializer()
    {
        SDL_Quit();
        TTF_Quit();
    }

    void Initializer::InitSdl(Uint32 flags)
    {
        if (SDL_Init(flags) < 0)
            throw SdlError("Gagal menginisialisasi SDL");
    }

    void Initializer::InitTtf()
    {
        if (TTF_Init() == -1)
            throw SdlError("Gagal menginisialisasi SDL_ttf");
    }
}