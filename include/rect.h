#pragma once

#include "vector.h"
#include "window.h"
#include <SDL.h>

namespace cookie
{
    struct Rect
    {
        float x, y;
        int w, h;

        Rect() : x(0), y(0), w(0), h(0) {}
        Rect(float p_x, float p_y, int p_w, int p_h)
            : x(p_x), y(p_y), w(p_w), h(p_h) {}

        bool CollideRect(const Rect &other) const
        {
            return (x < other.right() && right() > other.x &&
                    y < other.bottom() && bottom() > other.y);
        }
        void DrawRect(Window &window, Uint8 r,
                      Uint8 g, Uint8 b, Uint8 a = 255) const;
        void DrawRect(Window &window, const SDL_Color &color) const
        {
            DrawRect(window, color.r, color.g, color.b, color.a);
        }

        operator SDL_Rect() const { return SDL_Rect{(int)x, (int)y, w, h}; }

        float right() const { return x + w; }
        void set_right(float val) { x = val - w; }

        float bottom() const { return y + h; }
        void set_bottom(float val) { y = val - h; }

        float centerx() const { return x + w / 2.0f; }
        void set_centerx(float val) { x = val - w / 2.0f; }

        float centery() const { return y + h / 2.0f; }
        void set_centery(float val) { y = val - h / 2.0f; }

        Vector2 pos() const { return Vector2(x, y); }
        void set_pos(const Vector2 &val);

        Vector2 center() const { return Vector2(centerx(), centery()); }
        void set_center(const Vector2 &val);
    };
}