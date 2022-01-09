#include <SDL_mixer.h>

namespace cookie
{
    class Audio
    {
    public:
        Audio(const Audio &) = delete;

        // Panggil sebelum memuat suara/musik
        Audio(int chunk_size,
              int frequency = MIX_DEFAULT_FREQUENCY,
              Uint16 format = MIX_DEFAULT_FORMAT,
              int channels = MIX_DEFAULT_CHANNELS);

        ~Audio() { Mix_CloseAudio(); };
    };
}