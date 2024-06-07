#ifndef FONT_HPP
#define FONT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <cstddef>
#include <format>
#include <string>

namespace game
{
    class font
    {
    public:
        font(SDL_Renderer *renderer, const char *file, int size);
        ~font();
        font(const font &other) = delete;
        font &operator=(const font &other) = delete;
        font(font &&other) = delete;
        font &operator=(font &&other) = delete;

        template <typename... Args>
        void render(
            const std::size_t x,
            const std::size_t y,
            const std::size_t w,
            const SDL_Color &fg,
            const std::format_string<Args...> fmt,
            Args &&...args) const
        {
            const auto text = std::vformat(fmt.get(), std::make_format_args(args...));

            const auto surface = TTF_RenderText_Blended_Wrapped(ttf_font, text.c_str(), fg, static_cast<uint32_t>(w));
            const auto texture = SDL_CreateTextureFromSurface(renderer, surface);

            const SDL_Rect dstrect = {
                static_cast<int>(x),
                static_cast<int>(y),
                surface->w,
                surface->h};

            SDL_RenderCopy(renderer, texture, nullptr, &dstrect);

            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }

    private:
        SDL_Renderer *renderer;
        TTF_Font *ttf_font;
    };
}

#endif
