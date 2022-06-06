
#ifndef VALHALLA_GAMESTATE_H
#define VALHALLA_GAMESTATE_H


#include "../entities/Entity.h"

class GameState
{
public:
    int playerHealth;
    int playerMaxHealth;

    Entity enemy;
    bool fighting;
};


#endif //VALHALLA_GAMESTATE_H
