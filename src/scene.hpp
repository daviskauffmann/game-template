#ifndef SHMUP_SCENE_HPP
#define SHMUP_SCENE_HPP

#include <SDL2/SDL.h>
#include <cstdint>
#include <memory>

namespace game
{
    class display;

    class scene
    {
    public:
        scene(std::shared_ptr<game::display> display)
            : display(display) {}
        virtual ~scene() = default;
        scene(const scene &other) = delete;
        scene &operator=(const scene &other) = delete;
        scene(scene &&other) = delete;
        scene &operator=(scene &&other) = delete;

        virtual game::scene *handle_event(const SDL_Event &event) = 0;
        virtual game::scene *update(
            float delta_time,
            const std::uint8_t *keys,
            std::uint32_t mouse,
            int mouse_x,
            int mouse_y) = 0;

    protected:
        std::shared_ptr<game::display> display;

        template <typename T, typename... Args>
        game::scene *change_scene(Args... args)
        {
            auto scene = new T(std::forward<Args>(args)...);

            delete this;

            return scene;
        }

        game::scene *exit_game()
        {
            delete this;

            return nullptr;
        }
    };

}

#endif
