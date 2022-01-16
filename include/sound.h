#include <SDL2/SDL_mixer.h>
#include <string>

namespace cookie
{
    class Sound
    {
    public:
        static const int kMaxVolume = MIX_MAX_VOLUME;

    private:
        Mix_Chunk *sound_ = nullptr;

    public:
        Sound(const std::string &file_path);
        ~Sound();

        void Play(int channel = -1, int loops = 0);

        int volume() { return sound_->volume; }
        // Mengembalikan volume sebelum diset
        int set_volume(float volume) { return Mix_VolumeChunk(sound_, kMaxVolume * volume); }
    };
}