
#ifndef VALHALLA_GUIFRAME_H
#define VALHALLA_GUIFRAME_H


#include "GuiFrameStackInterface.h"
#include <windows.h>

#define KEY_UP 0x26
#define KEY_DOWN 0x28
#define KEY_LEFT 0x25
#define KEY_RIGHT 0x27

#define KEY_BACKSPACE 8
#define KEY_DELETE 127
#define KEY_ENTER 13
#define KEY_ESC 27

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

    // Input events
    virtual void handleInput(int code) {};
    virtual void handleArrow(int code) {};
    virtual void handleCtrl(int code) {};
    virtual void handleMouse(MOUSE_EVENT_RECORD m) {};

    // Animation events
    virtual void handleAnimationFrame(unsigned long frame) {};

    // Resize events
    virtual void onResize() {};
};


#endif //VALHALLA_GUIFRAME_H
