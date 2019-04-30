
#include "PortalAction.h"
#include "../../../gui/frames/types/PortalFrame.h"

void PortalAction::onAction(GameState *gameState, GuiFrameStackInterface<GuiFrame*>* guiFrameStackInterface)
{
    guiFrameStackInterface->push(new PortalFrame());
}