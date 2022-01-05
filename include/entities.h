#pragma once

#include "rect.h"
#include <SDL2/SDL.h>

class Entity
{
protected:
    cookie::Rect rect_;
    SDL_Color color_;
    float vel_;

public:
    Entity(float x, float y, int w, int h, const SDL_Color &color, float vel)
        : rect_(x, y, w, h), color_(color), vel_(vel) {}

    void Draw(SDL_Renderer *renderer) { rect_.DrawRect(renderer, color_); }

    virtual void Update() = 0;
    virtual void CheckBorder(int max_x, int max_y) = 0;
};

class Player : public Entity
{
private:
    bool move_up_, move_down_;

public:
    Player(float x, float y, int w, int h)
        : Entity(x, y, w, h, SDL_Color{189, 140, 97, 255}, 6),
          move_up_(false),
          move_down_(false) {}

    void Update() override;
    // TODO: variable dibutuhkan untuk override, tapi tidak untuk isi fungsi
    void CheckBorder(int /* max_x */, int max_y) override;

    void set_move_up(bool val) { move_up_ = val; }
    void set_move_down(bool val) { move_down_ = val; }
};