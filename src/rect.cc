#include "rect.h"
#include "window.h"
#include <SDL.h>

namespace cookie
{
    void Rect::DrawRect(Window &window, Uint8 r,
                        Uint8 g, Uint8 b, Uint8 a) const
    {
        SDL_Rect rect = *this;
        SDL_SetRenderDrawColor(window.renderer(), r, g, b, a);
        SDL_RenderFillRect(window.renderer(), &rect);
    }

    void Rect::set_pos(const Vector2 &val)
    {
        x = val.x;
        y = val.y;
    }

    void Rect::set_center(const Vector2 &val)
    {
        set_centerx(val.x);
        set_centery(val.y);
    }
}