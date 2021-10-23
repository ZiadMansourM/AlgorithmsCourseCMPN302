#include <iostream>
#include "Player.h"

#define LOG(x) std::cout << x << std::endl

int main()
{
    Player player;
    player.setSpeed(2);
    player.Move(5, 2);
    LOG(player.getX());
    LOG(player.getY());
    LOG(player.getSpeed());
    return 0;
}