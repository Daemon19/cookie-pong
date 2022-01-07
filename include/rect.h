#pragma once

#include "vector.h"
#include <SDL2/SDL.h>

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
        void DrawRect(SDL_Renderer *renderer, Uint8 r,
                      Uint8 g, Uint8 b, Uint8 a = 255);
        void DrawRect(SDL_Renderer *renderer, const SDL_Color &color)
        {
            DrawRect(renderer, color.r, color.g, color.b, color.a);
        }

        operator SDL_Rect() { return SDL_Rect{(int)x, (int)y, w, h}; }

        float right() { return x + w; }
        void set_right(float val) { x = val - w; }

        float bottom() { return y + h; }
        void set_bottom(float val) { y = val - h; }

        float centerx() { return x + w / 2.0f; }
        void set_centerx(float val) { x = val - w / 2.0f; }

        float centery() { return y + h / 2.0f; }
        void set_centery(float val) { y = val - h / 2.0f; }

        Vector2 pos() { return Vector2(x, y); }
        void set_pos(const Vector2 &val)
        {
            x = val.x;
            y = val.y;
        }

        Vector2 center() { return Vector2(centerx(), centery()); }
        void set_center(const Vector2 &val)
        {
            set_centerx(val.x);
            set_centery(val.y);
        }
    };
}