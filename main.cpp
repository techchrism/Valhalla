#include <iostream>
#include "structures/Stack.h"
#include "gui/frames/structure/GuiFrameStack.h"
#include "gui/test/FrameTest.h"
#include "gui/frames/types/DemoFrame.h"
#include <windows.h>

using namespace std;

DWORD WINAPI threadedFunction(LPVOID lpParameter)
{
    GuiFrameStack* gui = (GuiFrameStack*) lpParameter;

    DWORD ticks = GetTickCount();
    while(!gui->isEmpty())
    {
        // Use the system tick counter to avoid some multithreading pitfalls
        // (Namely calling functions on an unitialized object)
        DWORD currentTicks = GetTickCount();
        if(currentTicks - ticks >= 1)
        {
            // Call the animation tick function of the gui manager which passes it to the top frame
            gui->handleAnimationTick();
            ticks = currentTicks;
        }
        Sleep(1);
    }
    return 0;
}

int main()
{
    // Basic frame stack for display frames
    GuiFrameStack displayManager;

    // Push a demo frame to test things
    displayManager.push(new DemoFrame());

    // Start animation worker thread
    CreateThread(nullptr, 0, threadedFunction, &displayManager, 0, nullptr);

    // As long as there are frames, handle events in those frames (mouse, keyboard, resizing)
    while(!displayManager.isEmpty())
    {
        displayManager.handleEvents();
    }

    // Once the frame stack is empty (all frames popped) exit the program
    return 0;
}