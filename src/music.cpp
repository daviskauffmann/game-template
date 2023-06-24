#include "music.hpp"

#include <stdexcept>

game::music::music(const char *const filename)
{
    mix_music = Mix_LoadMUS(filename);
    if (!mix_music)
    {
        throw std::runtime_error(Mix_GetError());
    }

    Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
}

game::music::~music()
{
    Mix_FreeMusic(mix_music);
}

void game::music::play() const
{
    Mix_PlayMusic(mix_music, -1);
}

void game::music::halt() const
{
    Mix_HaltMusic();
}
