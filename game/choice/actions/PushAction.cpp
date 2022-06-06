
#include "PushAction.h"

PushAction::PushAction(GuiFrame *frame)
{
    this->frame = frame;
}

void PushAction::onAction(GameState *gameState, GuiFrameStackInterface<GuiFrame *> *guiFrameStackInterface)
{
    guiFrameStackInterface->push(frame);
}