
#ifndef VALHALLA2_TIMETRAVELCHOICE_H
#define VALHALLA2_TIMETRAVELCHOICE_H


#include "../Choice.h"

class TimeTravelChoice : public Choice
{
public:
    virtual int onPush(GameState* state, bool onAuto) override;
    virtual int onPop(GameState* state, bool onAuto) override;
};


#endif //VALHALLA2_TIMETRAVELCHOICE_H
