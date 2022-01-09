#include "initializer.h"
#include "cookie_error.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

namespace cookie
{
    Initializer::~Initializer()
    {
        SDL_Quit();
        TTF_Quit();
        while (Mix_Init(0))
            Mix_Quit();
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

    // Lakukan sebelum menggunakan format file suara MIX_INIT_*
    void Initializer::InitMixer(int flags)
    {
        if ((Mix_Init(flags) & flags) != flags)
            throw cookie::SdlError("Gagal menginisialisasi SDL_mixer");
    }
}