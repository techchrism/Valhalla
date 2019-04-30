
#ifndef VALHALLA2_ACTION_H
#define VALHALLA2_ACTION_H


#include "../state/GameState.h"
#include "../../gui/frames/structure/GuiFrameStackInterface.h"
#include "../../gui/frames/structure/GuiFrame.h"

class Action
{
public:
    virtual void onAction(GameState* gameState, GuiFrameStackInterface<GuiFrame*>* guiFrameStackInterface) = 0;
};


#endif //VALHALLA2_ACTION_H
