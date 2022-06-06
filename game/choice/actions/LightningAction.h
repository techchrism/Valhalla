
#ifndef VALHALLA2_LIGHTNINGACTION_H
#define VALHALLA2_LIGHTNINGACTION_H


#include "../Action.h"

class LightningAction : public Action
{
private:
    GuiFrame* next;
public:
    LightningAction(GuiFrame* next);
    virtual void onAction(GameState* gameState, GuiFrameStackInterface<GuiFrame*>* guiFrameStackInterface) override;
};


#endif //VALHALLA2_LIGHTNINGACTION_H
