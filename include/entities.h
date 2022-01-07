#pragma once

#include "cookie.h"
#include <SDL2/SDL.h>
#include <random>

class Entity
{
protected:
    cookie::Rect rect_;
    SDL_Color color_;

public:
    Entity(float x, float y, int w, int h, const SDL_Color &color)
        : rect_(x, y, w, h), color_(color) {}

    void Draw(SDL_Renderer *renderer) { rect_.DrawRect(renderer, color_); }

    virtual void Update() = 0;
    virtual void CheckVerticalBorder(int max_y) = 0;

    cookie::Rect rect() { return rect_; }
};

class Player;

class Ball : public Entity
{
private:
    bool move_up_, move_left_;
    const cookie::Vector2 start_pos_;
    const float kStartVel_ = 3;
    const float kMainVel_ = 8;
    float vel_;

public:
    Ball(float x, float y, int w, int h)
        : Entity(x, y, w, h, SDL_Color{239, 226, 178, 255}),
          start_pos_(x, y) { Reset(); }

    void Update() override {}
    void CheckVerticalBorder(int max_y) override;
    void CheckHorizontalBorder(int max_x,
                               Player &player_left,
                               Player &player_right);
    void MoveAndCheckCollision(Player players[], int player_count);

private:
    bool randomBool() { return rand() % 2 == 1; }
    void Reset();
};

class Player : public Entity
{
public:
    const float kVel = 6;

private:
    bool move_up_, move_down_;
    int score_;

public:
    Player(float x, float y, int w, int h)
        : Entity(x, y, w, h, SDL_Color{189, 140, 97, 255}),
          move_up_(false),
          move_down_(false),
          score_(0) {}

    void Update() override;
    void CheckVerticalBorder(int max_y) override;

    friend void Ball::CheckHorizontalBorder(int max_x,
                                            Player &player_left,
                                            Player &player_right);

    int score() { return score_; }
    void set_move_up(bool val) { move_up_ = val; }
    void set_move_down(bool val) { move_down_ = val; }
};
