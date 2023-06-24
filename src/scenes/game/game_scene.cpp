#include "game_scene.hpp"
#include "../../display.hpp"
#include "../../font.hpp"
#include <SDL2/SDL.h>

game::game_scene::game_scene(std::shared_ptr<game::display> display) : game::scene(display)
{
    const auto renderer = display->get_renderer();

    font = std::make_unique<game::font>(renderer, "data/Helvetica.ttf", font_size);
}

game::scene *game::game_scene::handle_event(const SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
        {
            return nullptr;
        }
        break;
        }
    }
    break;
    }

    return this;
}

game::scene *game::game_scene::update(
    const float delta_time,
    const std::uint8_t *const keys,
    const std::uint32_t mouse,
    const int mouse_x,
    const int mouse_y)
{
    int y = 0;

    font->render(0, y++ * font_size, 0, {255, 255, 255}, "Delta Time: {}", delta_time);
    for (int scancode = 0; scancode < SDL_NUM_SCANCODES; scancode++)
    {
        if (keys[scancode])
        {
            font->render(0, y++ * font_size, 0, {255, 255, 255}, "Key Pressed: {}", scancode);
        }
    }
    for (int button = SDL_BUTTON_LEFT; button <= SDL_BUTTON_X2; button++)
    {
        if (mouse & SDL_BUTTON(button))
        {
            font->render(0, y++ * font_size, 0, {255, 255, 255}, "Mouse Button Pressed: {}", button);
        }
    }
    font->render(0, y++ * font_size, 0, {255, 255, 255}, "Mouse X: {}", mouse_x);
    font->render(0, y++ * font_size, 0, {255, 255, 255}, "Mouse Y: {}", mouse_y);

    return this;
}
