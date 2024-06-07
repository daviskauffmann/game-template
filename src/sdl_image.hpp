#ifndef GAME_SDL_IMAGE_HPP
#define GAME_SDL_IMAGE_HPP

namespace game
{
    class sdl_image
    {
    public:
        sdl_image();
        ~sdl_image();
        sdl_image(const sdl_image &other) = delete;
        sdl_image &operator=(const sdl_image &other) = delete;
        sdl_image(sdl_image &&other) = delete;
        sdl_image &operator=(sdl_image &&other) = delete;
    };
}

#endif
