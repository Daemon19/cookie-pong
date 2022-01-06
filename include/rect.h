#pragma once

#include "vector.h"
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
        Vector2 pos() { return Vector2(x, y); }

        void set_right(float val) { x = val - w; }
        void set_bottom(float val) { y = val - h; }
        void set_pos(float p_x, float p_y)
        {
            x = p_x;
            y = p_y;
        }
        void set_pos(Vector2 pos) { set_pos(pos.x, pos.y); }

        bool CollideRect(Rect &other);
        void DrawRect(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
        void DrawRect(SDL_Renderer *renderer, const SDL_Color &color);

        SDL_Rect SdlRect() { return SDL_Rect{.x = (int)x, .y = (int)y, .w = w, .h = h}; }
    };
}