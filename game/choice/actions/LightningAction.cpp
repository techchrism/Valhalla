
#include "LightningAction.h"
#include "../../../gui/frames/types/LightningFrame.h"

void LightningAction::onAction(GameState *gameState, GuiFrameStackInterface<GuiFrame*>* guiFrameStackInterface)
{
    guiFrameStackInterface->push(new LightningFrame());
}