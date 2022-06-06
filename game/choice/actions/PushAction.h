
#ifndef VALHALLA_PUSHACTION_H
#define VALHALLA_PUSHACTION_H


#include "../Action.h"

class PushAction : public Action
{
private:
    GuiFrame* frame;
public:
    PushAction(GuiFrame* frame);
    virtual void onAction(GameState* gameState, GuiFrameStackInterface<GuiFrame*>* guiFrameStackInterface) override;
};


#endif //VALHALLA_PUSHACTION_H
