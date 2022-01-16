#include <SDL2/SDL_mixer.h>
#include <string>

namespace cookie
{
    class Music
    {
    public:
        static const int kMaxVolume = MIX_MAX_VOLUME;

    private:
        Mix_Music *music_ = nullptr;

    public:
        Music(const std::string &file_path);
        ~Music();

        void Play(int loops = -1);
        void FadeIn(int ms, int loops = -1);

        static int set_volume(float volume) { return Mix_VolumeMusic(kMaxVolume * volume); }
        static int volume() { return Mix_VolumeMusic(-1); }
    };
}