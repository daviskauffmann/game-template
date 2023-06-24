#include "sdl.hpp"

#include <stdexcept>

game::sdl::sdl(const std::uint32_t flags)
{
    if (SDL_Init(flags) != 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

game::sdl::~sdl()
{
    SDL_Quit();
}

std::uint64_t game::sdl::get_ticks() const
{
    return SDL_GetTicks64();
}

const std::uint8_t *game::sdl::get_keys() const
{
    return SDL_GetKeyboardState(nullptr);
}

game::sdl_mouse_state game::sdl::get_mouse_state() const
{
    game::sdl_mouse_state state;
    state.mouse = SDL_GetMouseState(&state.mouse_x, &state.mouse_y);
    return state;
}

bool game::sdl::poll_event(SDL_Event &event) const
{
    return SDL_PollEvent(&event);
}
