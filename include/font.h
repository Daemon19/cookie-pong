#pragma once

#include "texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace cookie
{
    class Font
    {
    private:
        TTF_Font *font_;

    public:
        Font(const std::string &file_path, int size);
        ~Font();

        Texture CreateTexture(Window &window, const std::string &text,
                              const SDL_Color &color);
    };
}