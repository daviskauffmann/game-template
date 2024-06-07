#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <SDL2/SDL_mixer.h>

namespace game
{
    class music
    {
    public:
        explicit music(const char *filename);
        ~music();
        music(const music &other) = delete;
        music &operator=(const music &other) = delete;
        music(music &&other) = delete;
        music &operator=(music &&other) = delete;

        void play() const;
        void halt() const;

    private:
        Mix_Music *mix_music;
    };
}

#endif
