
#include "TimeTravelChoice.h"

int TimeTravelChoice::onPop(GameState *state, bool onAuto)
{
    return CHOICE_SPECIAL_NONE;
}

int TimeTravelChoice::onPush(GameState *state, bool onAuto)
{
    return CHOICE_SPECIAL_TRAVELBACK;
}