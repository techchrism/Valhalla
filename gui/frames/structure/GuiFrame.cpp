
#include "GuiFrame.h"

void GuiFrame::onAdd(GuiFrameStackInterface<GuiFrame*>* guiFrameStackInterface)
{
    this->guiFrameStackInterface = guiFrameStackInterface;
    addHandler();
}

void GuiFrame::onRemove()
{
    removeHandler();
}

void GuiFrame::onDeactivate()
{
    deactivationHandler();
}

void GuiFrame::onActivate()
{
    activationHandler();
}
