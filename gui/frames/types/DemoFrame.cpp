
#include "DemoFrame.h"
#include "PortalFrame.h"

DemoFrame::DemoFrame()
{
    screenBuffer = ConsoleUtil::generateBuffer();
    ConsoleUtil::hideCursor(screenBuffer);
}

void DemoFrame::addHandler()
{
    // Sets this screen buffer as the active one and prints "Hello world" initially
    SetConsoleActiveScreenBuffer(screenBuffer);
    string text = "Hello world!";
    short x = ConsoleUtil::getProportionalLength(screenBuffer, 0.5, text.length());
    short y = ConsoleUtil::getProportionalHeight(screenBuffer, 0.5, 1);
    ConsoleUtil::printString(screenBuffer, x, y, text);
}

void DemoFrame::handleArrow(int code)
{
    // Print to the console when an arrow is pressed
    //ConsoleUtil::printString(screenBuffer, 0, lineCounter++, "Got arrow");
}

void DemoFrame::handleInput(int code)
{
    if(code == KEY_ESC)
    {
        // Pop this item if the escape key is pressed
        // If this is the only frame in the stack, this will exit the program
        guiFrameStackInterface->pop();
    }
    else if(code == KEY_ENTER)
    {
        // Display a portal
        guiFrameStackInterface->push(new PortalFrame());
    }
    else
    {
        // If it's not escape, print to the screen about getting input
        ConsoleUtil::shakeConsoleSmall();
    }
}

void DemoFrame::handleAnimationFrame(unsigned long tick)
{
    //ConsoleUtil::printString(screenBuffer, lineCounter++, 0, ".");
}