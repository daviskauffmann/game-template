#ifndef SDL_MIXER_HPP
#define SDL_MIXER_HPP

namespace game
{
    class sdl_mixer
    {
    public:
        sdl_mixer();
        ~sdl_mixer();
        sdl_mixer(const sdl_mixer &other) = delete;
        sdl_mixer &operator=(const sdl_mixer &other) = delete;
        sdl_mixer(sdl_mixer &&other) = delete;
        sdl_mixer &operator=(sdl_mixer &&other) = delete;
    };
}

#endif
