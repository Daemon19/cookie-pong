#include "entities.h"

void Player::Update()
{
    float movement = 0;

    if (move_up_)
        movement -= kVel;
    if (move_down_)
        movement += kVel;

    rect_.y += movement;
}

void Player::CheckBorder(int /* max_x */, int max_y)
{
    if (rect_.y < 0)
        rect_.y = 0;
    if (rect_.bottom() > max_y)
        rect_.set_bottom(max_y);
}

void Ball::CheckBorder(int max_x, int max_y)
{
    if (rect_.right() < 0)
        Reset();
    if (rect_.x > max_x)
        Reset();

    if (rect_.y < 0)
    {
        rect_.y = 0;
        move_up_ = !move_up_;
    }
    if (rect_.bottom() > max_y)
    {
        rect_.set_bottom(max_y);
        move_up_ = !move_up_;
    }
}

void Ball::MoveAndCheckCollision(Player players[], int player_count)
{
    rect_.x += (move_left_) ? -vel_ : vel_;

    for (int i = 0; i < player_count; i++)
    {
        cookie::Rect player_rect = players[i].rect();

        if (rect_.CollideRect(player_rect))
        {
            if (move_left_)
                rect_.x = player_rect.right();
            else
                rect_.set_right(player_rect.x);

            move_left_ = !move_left_;
            vel_ = kMainVel_;
        }
    }

    rect_.y += (move_up_) ? -vel_ : vel_;

    for (int i = 0; i < player_count; i++)
    {
        cookie::Rect player_rect = players[i].rect();

        if (rect_.CollideRect(player_rect))
        {
            if (move_up_)
                rect_.y = player_rect.bottom();
            else
                rect_.set_bottom(player_rect.y);

            move_up_ = !move_up_;
            vel_ = kMainVel_;
        }
    }
}

void Ball::Reset()
{
    rect_.set_pos(start_pos_);
    move_up_ = randomBool();
    move_left_ = randomBool();
    vel_ = kStartVel_;
}