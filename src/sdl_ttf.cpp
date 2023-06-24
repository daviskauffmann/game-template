#include "sdl_ttf.hpp"

#include <SDL2/SDL_ttf.h>
#include <stdexcept>

game::sdl_ttf::sdl_ttf()
{
    if (TTF_Init() != 0)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

game::sdl_ttf::~sdl_ttf()
{
    TTF_Quit();
}
