#include "Player.h"

int Player :: getX() const
{
    return x;
}
int Player :: getY() const
{
    return y;
}
int Player :: getSpeed() const
{
    return speed;
}
void Player :: setSpeed(int const s) 
{
    speed = s;
}
void Player :: Move(int const xa, int const ya)
{
    x += xa * speed;
    y += ya * speed;
}