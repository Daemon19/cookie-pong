#pragma once

namespace cookie
{
    struct Vector2
    {
        float x, y;

        Vector2(float p_x, float p_y) : x(p_x), y(p_y) {}

        void Reset();

        Vector2 operator+(const Vector2 &val) const
        {
            return Vector2(x + val.x, y + val.y);
        }
        Vector2 operator*(float val) const { return Vector2(x * val, y * val); }
        Vector2 operator/(float val) const { return Vector2(x / val, y / val); }

        void operator+=(const Vector2 &val) { *this = *this + val; }
    };
}