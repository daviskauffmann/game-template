#ifndef SDL_HPP
#define SDL_HPP

#include <SDL2/SDL.h>
#include <cstdint>

namespace game
{
    struct sdl_mouse_state
    {
        std::uint32_t mouse;
        int mouse_x;
        int mouse_y;
    };

    class sdl
    {
    public:
        sdl(std::uint32_t flags);
        ~sdl();
        sdl(const sdl &other) = delete;
        sdl &operator=(const sdl &other) = delete;
        sdl(sdl &&other) = delete;
        sdl &operator=(sdl &&other) = delete;

        std::uint64_t get_ticks() const;
        const std::uint8_t *get_keys() const;
        game::sdl_mouse_state get_mouse_state() const;

        bool poll_event(SDL_Event &event) const;
    };
}

#endif
