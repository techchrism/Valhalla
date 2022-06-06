
#ifndef VALHALLA_PORTALACTION_H
#define VALHALLA_PORTALACTION_H


#include "../Action.h"
#include "../../../gui/frames/structure/GuiFrame.h"

class PortalAction : public Action
{
public:
    virtual void onAction(GameState* gameState, GuiFrameStackInterface<GuiFrame*>* guiFrameStackInterface) override;
};


#endif //VALHALLA_PORTALACTION_H
