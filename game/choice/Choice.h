
#ifndef VALHALLA2_CHOICE_H
#define VALHALLA2_CHOICE_H


#include "../state/GameState.h"
#include "ChoicesStack.h"

#define CHOICE_SPECIAL_TRAVELBACK 1
#define CHOICE_SPECIAL_NONE 0

class Choice
{
public:
    virtual int onPush(GameState* state, bool onAuto) = 0;
    virtual int onPop(GameState* state, bool onAuto) = 0;
};


#endif //VALHALLA2_CHOICE_H
