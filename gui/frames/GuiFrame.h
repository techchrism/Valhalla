
#ifndef VALHALLA2_GUIFRAME_H
#define VALHALLA2_GUIFRAME_H


#include "GuiFrameStackInterface.h"

class GuiFrame
{
protected:
    GuiFrameStackInterface<GuiFrame*>* guiFrameStackInterface;
public:
    /*
     * Frame lifecycle:
     *  - First pushed to the framestack: add
     *  - Another item pushed over it: deactivate
     *  - The item that was over it was popped making this one the top again: activate
     *  - This item was popped: remove
     */

    virtual void activationHandler() {};
    virtual void deactivationHandler() {};
    virtual void addHandler() {};
    virtual void removeHandler() {};

    /*
     * There are pairs of these functions to ensure required behavior (currently only in the add function)
     * while allowing for custom defined behaviors in child classes
     */

    void onActivate();
    void onDeactivate();
    void onRemove();
    void onAdd(GuiFrameStackInterface<GuiFrame*>* guiFrameStackInterface);
};


#endif //VALHALLA2_GUIFRAME_H
