#include "rect.h"
#include <SDL2/SDL.h>

namespace cookie
{
    void Rect::DrawRect(SDL_Renderer *renderer, Uint8 r,
                        Uint8 g, Uint8 b, Uint8 a)
    {
        SDL_Rect rect = sdl_rect();

        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        SDL_RenderFillRect(renderer, &rect);
    }
}