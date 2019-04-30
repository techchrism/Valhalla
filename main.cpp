#include <iostream>
#include "structures/Stack.h"
#include "gui/frames/structure/GuiFrameStack.h"
#include "gui/test/FrameTest.h"
#include "gui/frames/types/DemoFrame.h"
#include <windows.h>

using namespace std;

int main()
{
    // Basic frame stack for display frames
    GuiFrameStack displayManager;

    // Push a demo frame to test things
    displayManager.push(new DemoFrame());

    // As long as there are frames, handle events in those frames (mouse, keyboard, resizing)
    while(!displayManager.isEmpty())
    {
        displayManager.handleEvents();
    }

    // Once the frame stack is empty (all frames popped) exit the program
    return 0;
}