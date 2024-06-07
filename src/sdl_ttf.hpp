#ifndef GAME_SDL_TTF_HPP
#define GAME_SDL_TTF_HPP

namespace game
{
    class sdl_ttf
    {
    public:
        sdl_ttf();
        ~sdl_ttf();
        sdl_ttf(const sdl_ttf &other) = delete;
        sdl_ttf(sdl_ttf &&other) = delete;
        sdl_ttf &operator=(const sdl_ttf &other) = delete;
        sdl_ttf &operator=(sdl_ttf &&other) = delete;
    };
}

#endif
