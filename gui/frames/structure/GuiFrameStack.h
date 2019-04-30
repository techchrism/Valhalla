#ifndef VALHALLA2_GUIFRAMESTACK_H
#define VALHALLA2_GUIFRAMESTACK_H


#include "../../../structures/Stack.h"
#include "GuiFrameStackInterface.h"
#include "GuiFrame.h"
#include <windows.h>

class GuiFrameStack : public GuiFrameStackInterface<GuiFrame*>
{
private:
    Stack<GuiFrame*> frames;
    HANDLE inputHandle;
    unsigned long tick = 0;
public:
    GuiFrameStack();

    void handleEvents();
    void handleAnimationTick();

    bool isEmpty() override;
    int getLength() override;

    GuiFrame* pop() override;
    void pop(int amount) override;
    GuiFrame* top() override;
    void push(GuiFrame* frame) override;
};


#endif //VALHALLA2_GUIFRAMESTACK_H
