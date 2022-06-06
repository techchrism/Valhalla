
#include "LightningAction.h"
#include "../../../gui/frames/types/LightningFrame.h"

LightningAction::LightningAction(GuiFrame *next)
{
    this->next = next;
}

void LightningAction::onAction(GameState *gameState, GuiFrameStackInterface<GuiFrame*>* guiFrameStackInterface)
{
    guiFrameStackInterface->push(new LightningFrame(next));
}