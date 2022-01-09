#include "texture.h"
#include "cookie_error.h"
#include "window.h"
#include <SDL.h>

namespace cookie
{
    Texture::Texture(SDL_Texture *tex) : tex_(nullptr)
    {
        if ((tex_ = tex) == nullptr)
            throw CookieError("Gagal membuat Texture : SDL_Texture tidak boleh NULL");

        if (SDL_QueryTexture(tex_, &format_, &access_, &w_, &h_) < 0)
            throw SdlError("Gagal menanyakan (query) texture");
    }

    Texture::Texture(Window &window, SDL_Surface *surf) : tex_(nullptr)
    {
        if (surf == NULL)
            throw CookieError("Gagal membuat Texture : SDL_Surface tidak boleh NULL");

        if ((tex_ = SDL_CreateTextureFromSurface(window.renderer(), surf)) == nullptr)
            throw SdlError("Gagal membuat Texture dari surface");

        if (SDL_QueryTexture(tex_, &format_, &access_, &w_, &h_) < 0)
            throw SdlError("Gagal menanyakan (query) texture");

        SDL_FreeSurface(surf);
    }

    Texture::~Texture()
    {
        if (tex_ != nullptr)
            SDL_DestroyTexture(tex_);
    }
}