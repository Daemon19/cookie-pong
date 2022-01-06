#include "texture.h"
#include "window.h"
#include <SDL2/SDL.h>
#include "log.h"

namespace cookie
{
    Texture::~Texture()
    {
        if (tex_ != nullptr)
            SDL_DestroyTexture(tex_);
    }

    bool Texture::Init(SDL_Texture *tex)
    {
        if ((tex_ = tex) == NULL)
        {
            log::Error("Texture tidak boleh NULL");
            return false;
        }

        Uint32 format;
        int access;
        SDL_QueryTexture(tex, &format, &access, &w_, &h_);

        return true;
    }

    bool Texture::Init(Window &window, SDL_Surface *surf)
    {
        if (surf == NULL)
        {
            log::Error("Surface tidak boleh NULL");
            return false;
        }

        if ((tex_ = SDL_CreateTextureFromSurface(window.renderer(), surf)) == NULL)
        {
            log::SdlError("Gagal membuat Texture");
            return false;
        }

        w_ = surf->w;
        h_ = surf->h;

        SDL_FreeSurface(surf);
        return true;
    }
}