#pragma once

#include <SDL2/SDL_ttf.h>
#include <string>
#include "window.h"
#include "texture.h"

namespace cookie
{
    class Font
    {
    private:
        TTF_Font *font_ = nullptr;

    public:
        ~Font();

        bool Init(const std::string &file_path, int size);
        bool CreateTexture(Window &window, const std::string &text,
                           const SDL_Color &color, Texture &tex);
    };
}