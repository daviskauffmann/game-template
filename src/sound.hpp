#ifndef SHMUP_SOUND_HPP
#define SHMUP_SOUND_HPP

#include <SDL2/SDL_mixer.h>

namespace game
{
    class sound
    {
    public:
        explicit sound(const char *filename);
        ~sound();
        sound(const sound &other) = delete;
        sound &operator=(const sound &other) = delete;
        sound(sound &&other) = delete;
        sound &operator=(sound &&other) = delete;

        void play() const;

    private:
        Mix_Chunk *mix_chunk;
    };
}

#endif
