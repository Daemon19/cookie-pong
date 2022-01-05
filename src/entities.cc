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