
#ifndef VALHALLA2_GAMESTATE_H
#define VALHALLA2_GAMESTATE_H


#include "../entities/Entity.h"

class GameState
{
public:
    int playerHealth;
    int playerMaxHealth;

    Entity enemy;
    bool fighting;
};


#endif //VALHALLA2_GAMESTATE_H
