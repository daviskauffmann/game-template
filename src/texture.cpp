#include "texture.hpp"

#include <SDL2/SDL_image.h>
#include <stdexcept>

game::texture::texture(SDL_Renderer *const renderer, const char *const file)
    : renderer(renderer)
{
    sdl_texture = IMG_LoadTexture(renderer, file);
    if (!sdl_texture)
    {
        throw std::runtime_error(IMG_GetError());
    }
}

game::texture::~texture()
{
    SDL_DestroyTexture(sdl_texture);
}

void game::texture::render(
    const SDL_Rect *const srcrect,
    const SDL_Rect *const dstrect) const
{
    SDL_RenderCopy(renderer, sdl_texture, srcrect, dstrect);
}

void game::texture::render_ex(
    const SDL_Rect *const srcrect,
    const SDL_Rect *const dstrect,
    const double angle,
    const SDL_Point *const center,
    const SDL_RendererFlip flip) const
{
    SDL_RenderCopyEx(renderer, sdl_texture, srcrect, dstrect, angle, center, flip);
}
