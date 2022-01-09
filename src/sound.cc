#include "sound.h"
#include "cookie_error.h"
#include <SDL_mixer.h>
#include <string>

namespace cookie
{
    Sound::Sound(const std::string &file_path)
    {
        if ((sound_ = Mix_LoadWAV(file_path.c_str())) == nullptr)
            throw cookie::SdlError("Gagal memuat suara");
    }

    Sound::~Sound()
    {
        Mix_FreeChunk(sound_);
        sound_ = nullptr;
    }

    void Sound::Play(int channel, int loops)
    {
        if (Mix_PlayChannel(channel, sound_, loops) == -1)
            throw cookie::SdlError("Gagal memainkan suara");
    }
}