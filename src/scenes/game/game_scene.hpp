#ifndef SCENES_GAME_SCENE_HPP
#define SCENES_GAME_SCENE_HPP

#include "../../scene.hpp"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

namespace game
{
    class font;

    class game_scene : public game::scene
    {
    public:
        game_scene(std::shared_ptr<game::display> display);

        game::scene *handle_event(const SDL_Event &event) override;
        game::scene *update(
            float delta_time,
            const std::uint8_t *keys,
            std::uint32_t mouse,
            int mouse_x,
            int mouse_y) override;

    private:
        static const int font_size = 18;

        std::unique_ptr<game::font> font;
    };
}

#endif
