#pragma once

#include <SDL2/SDL.h>

namespace cookie
{
    struct Rect
    {
        float x, y;
        int w, h;

        Rect(float p_x, float p_y, int p_w, int p_h)
            : x(p_x), y(p_y), w(p_w), h(p_h) {}

        float right() { return x + w; }
        float bottom() { return y + h; }
        void set_right(float val) { x = val - w; }
        void set_bottom(float val) { y = val - h; }

        bool CollideRect(Rect &other);
        void DrawRect(SDL_Renderer *renderer, Uint32 r, Uint32 g, Uint32 b, Uint32 a = 255);
        void DrawRect(SDL_Renderer *renderer, const SDL_Color &color);

        SDL_Rect SdlRect()
        {
            return SDL_Rect{.x = (int)x, .y = (int)y, .w = w, .h = h};
        }
    };
}