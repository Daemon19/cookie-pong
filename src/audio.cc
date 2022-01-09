#include "audio.h"
#include "cookie_error.h"
#include <SDL_mixer.h>

namespace cookie
{
    Audio::Audio(int chunk_size, int frequency, Uint16 format, int channels)
    {
        if (Mix_OpenAudio(frequency, format, channels, chunk_size) == -1)
            throw SdlError("Gagal membuka audio");
    }

}