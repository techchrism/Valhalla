
#include "BasicGuiFrame.h"

void BasicGuiFrame::activationHandler()
{
    SetConsoleActiveScreenBuffer(screenBuffer);
}

void BasicGuiFrame::addHandler()
{
    SetConsoleActiveScreenBuffer(screenBuffer);
}

void BasicGuiFrame::removeHandler()
{
    CloseHandle(screenBuffer);
}