#include "entities.h"

void Player::Update()
{
    float movement = 0;

    if (move_up_)
        movement -= vel_;
    if (move_down_)
        movement += vel_;

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
    if (rect_.x < 0)
    {
        rect_.x = 0;
        move_left_ = !move_left_;
    }
    if (rect_.right() > max_x)
    {
        rect_.set_right(max_x);
        move_left_ = !move_left_;
    }

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
        }
    }
}