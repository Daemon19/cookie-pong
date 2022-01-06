#include "font.h"
#include "log.h"
#include "texture.h"
#include "window.h"
#include <SDL2/SDL.h>
#include <string>

namespace cookie
{
    Font::~Font()
    {
        if (font_ != nullptr)
            TTF_CloseFont(font_);
    }

    bool Font::Init(const std::string &file_path, int size)
    {
        if ((font_ = TTF_OpenFont(file_path.c_str(), size)) == NULL)
        {
            log::SdlError("Gagal membuka font");
            return false;
        }
        return true;
    }

    bool Font::CreateTexture(Window &window, const std::string &text, const SDL_Color &color, Texture &tex)
    {
        SDL_Surface *surf = TTF_RenderText_Blended(font_, text.c_str(), color);

        if (surf == NULL)
        {
            log::SdlError("Gagal merender text");
            return false;
        }

        return tex.Init(window, surf);
    }
}