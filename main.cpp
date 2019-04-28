#include <iostream>
#include "structures/Stack.h"
#include "gui/frames/structure/GuiFrameStack.h"
#include "gui/test/FrameTest.h"
#include "gui/frames/types/DemoFrame.h"
#include <windows.h>

using namespace std;

int main()
{
    GuiFrameStack displayManager;
    displayManager.push(new DemoFrame());
    while(!displayManager.isEmpty())
    {
        displayManager.handleEvents();
    }

    return 0;
}
