
#include "DemoFrame.h"

DemoFrame::DemoFrame()
{
    screenBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
                                             FILE_SHARE_READ | FILE_SHARE_WRITE,
                                             NULL,
                                             CONSOLE_TEXTMODE_BUFFER,
                                             NULL);
}

void DemoFrame::addHandler()
{
    SetConsoleActiveScreenBuffer(screenBuffer);
    ConsoleUtil::printString(screenBuffer, 0, 0, "Hello world!");
}

void DemoFrame::handleArrow(int code)
{
    ConsoleUtil::printString(screenBuffer, 0, lineCounter++, "Got arrow");
}

void DemoFrame::handleInput(int code)
{
    if(code == KEY_ESC)
    {
        guiFrameStackInterface->pop();
    }
    else
    {
        ConsoleUtil::printString(screenBuffer, 0, lineCounter++, "Got input");
    }
}