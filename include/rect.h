#pragma once

#include <SDL2/SDL.h>
#include "vector.h"

namespace cookie
{
    class Rect
    {
    public:
        float x, y;
        int w, h;

    public:
        Rect() : x(0), y(0), w(0), h(0) {}
        Rect(float p_x, float p_y, int p_w, int p_h)
            : x(p_x), y(p_y), w(p_w), h(p_h) {}

        bool CollideRect(Rect other)
        {
            return (x < other.right() && right() > other.x &&
                    y < other.bottom() && bottom() > other.y);
        }
        void DrawRect(SDL_Renderer *renderer, const SDL_Color &color)
        {
            DrawRect(renderer, color.r, color.g, color.b, color.a);
        }
        void DrawRect(SDL_Renderer *renderer, Uint8 r,
                      Uint8 g, Uint8 b, Uint8 a = 255);

        operator SDL_Rect() { return sdl_rect(); }

        float right() { return x + w; }
        float bottom() { return y + h; }
        Vector2 pos() { return Vector2(x, y); }

        void set_right(float val) { x = val - w; }
        void set_bottom(float val) { y = val - h; }
        void set_pos(Vector2 val)
        {
            x = val.x;
            y = val.y;
        }

    private:
        SDL_Rect sdl_rect() { return SDL_Rect{(int)x, (int)y, w, h}; }
    };
}