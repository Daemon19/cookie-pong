#include "font.h"
#include "cookie_error.h"
#include "texture.h"
#include "window.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

namespace cookie
{
    Font::Font(const std::string &file_path, int size) : font_(nullptr)
    {
        font_ = TTF_OpenFont(file_path.c_str(), size);

        if (font_ == nullptr)
            throw SdlError("Gagal membuka font");
    }

    Font::~Font()
    {
        if (font_ != nullptr)
            TTF_CloseFont(font_);
    }

    Texture Font::CreateTexture(Window &window, const std::string &text,
                                const SDL_Color &color)
    {
        SDL_Surface *surf = TTF_RenderText_Blended(font_, text.c_str(), color);

        if (surf == nullptr)
            throw SdlError("Gagal merender text");

        return Texture(window, surf);
    }
}