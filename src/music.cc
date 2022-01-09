#include "music.h"
#include "cookie_error.h"
#include <SDL_mixer.h>
#include <string>

namespace cookie
{
    Music::Music(const std::string &file_path)
    {
        if ((music_ = Mix_LoadMUS(file_path.c_str())) == NULL)
            throw SdlError("Gagal memuat musik");
    }

    Music::~Music()
    {
        Mix_FreeMusic(music_);
        music_ = nullptr;
    }

    void Music::Play(int loops)
    {
        if (Mix_PlayMusic(music_, loops) == -1)
            throw SdlError("Gagal memainkan musik");
    }

    void Music::FadeIn(int ms, int loops)
    {
        if (Mix_FadeInMusic(music_, loops, ms) == -1)
            throw cookie::SdlError("Gagal fade in musik");
    }
}