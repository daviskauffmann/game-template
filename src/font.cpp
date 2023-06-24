#include "font.hpp"

#include <stdexcept>

game::font::font(SDL_Renderer *const renderer, const char *const file, const int size)
    : renderer(renderer)
{
    ttf_font = TTF_OpenFont(file, size);
    if (!ttf_font)
    {
        throw std::runtime_error(TTF_GetError());
    }
}

game::font::~font()
{
    TTF_CloseFont(ttf_font);
}
