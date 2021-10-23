#pragma once

class Player
{
    int x, y;
    int speed;
    public:
    int getX() const;
    int getY() const;
    int getSpeed() const;
    void setSpeed(int const s);
    void Move(int const xa, int const ya);
};