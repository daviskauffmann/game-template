#include "display.hpp"

#include <stdexcept>

game::display::display(const int width, const int height)
    : width(width),
      height(height)
{
    if (SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer) != 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
}

game::display::~display()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

std::size_t game::display::get_width() const
{
    return width;
}

std::size_t game::display::get_height() const
{
    return height;
}

SDL_Renderer *game::display::get_renderer() const
{
    return renderer;
}

void game::display::set_title(const char *title) const
{
    SDL_SetWindowTitle(window, title);
}

void game::display::set_vsync(bool enabled) const
{
    SDL_RenderSetVSync(renderer, enabled);
}

void game::display::toggle_fullscreen() const
{
    const auto flags = SDL_GetWindowFlags(window);
    if (flags & SDL_WINDOW_FULLSCREEN_DESKTOP)
    {
        SDL_SetWindowFullscreen(window, 0);
    }
    else
    {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
}

void game::display::handle_event(const SDL_Event &event) const
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_RETURN:
        {
            if (event.key.keysym.mod & KMOD_ALT)
            {
                toggle_fullscreen();
            }
        }
        break;
        }
    }
    break;
    }
}

void game::display::clear() const
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void game::display::present() const
{
    SDL_RenderPresent(renderer);
}
