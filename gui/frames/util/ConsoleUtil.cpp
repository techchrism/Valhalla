
#include "ConsoleUtil.h"

void ConsoleUtil::writeOutput(HANDLE screenBuffer, short x, short y, CHAR_INFO *text,
                              short columns, short rows)
{
    // Normalize x/y to console coordinates and bounding box
    short finishX = x + columns;
    short finishY = y + rows;
    SMALL_RECT box = {x, y, finishX, finishY};

    WriteConsoleOutput(screenBuffer, text, {columns, rows}, {0, 0}, &box);
}

short ConsoleUtil::getBufferHeight(HANDLE screenBuffer)
{
    CONSOLE_SCREEN_BUFFER_INFO buffInfo;
    GetConsoleScreenBufferInfo(screenBuffer, &buffInfo);
    return buffInfo.dwSize.Y;
}

short ConsoleUtil::getBufferWidth(HANDLE screenBuffer)
{
    CONSOLE_SCREEN_BUFFER_INFO buffInfo;
    GetConsoleScreenBufferInfo(screenBuffer, &buffInfo);
    return buffInfo.dwSize.X;
}

void ConsoleUtil::printString(HANDLE screenBuffer, short x, short y, string data)
{
    // Convert a string to CHAR_INFO for data output
    CHAR_INFO wordData[data.length()];
    for(int i = 0; i < data.length(); i++)
    {
        wordData[i].Char.AsciiChar = data[i];
        wordData[i].Attributes = WHITE_TEXT;
    }

    writeOutput(screenBuffer, x, y, wordData, data.length(), 1);
}

short ConsoleUtil::getProportionalLength(HANDLE screenBuffer, double fraction, short length)
{
    // Returns a position on the buffer based on the buffer size, the fraction of that size, and the length of the text
    return ((double) getBufferWidth(screenBuffer) * fraction) - (length / 2);
}

short ConsoleUtil::getProportionalHeight(HANDLE screenBuffer, double fraction, short height)
{
    return ((double) getBufferHeight(screenBuffer) * fraction) - (height / 2);
}

void ConsoleUtil::shakeConsole(int scale, int amount)
{
    // Get the window handle and position
    HWND win = GetConsoleWindow();
    RECT consolePos;
    GetWindowRect(win, &consolePos);

    int width = consolePos.right - consolePos.left;
    int height = consolePos.bottom - consolePos.top;

    // Change the window position randomly to simulate shaking
    for(int i = 0; i < amount; i++)
    {
        int changeX = (rand() % static_cast<int>(scale + 1)) - (scale / 2);
        int changeY = (rand() % static_cast<int>(scale + 1)) - (scale / 2);
        MoveWindow(win, consolePos.left + changeX, consolePos.top + changeY, width, height, true);
        Sleep(50);
    }

    // Reset back to it's starting position
    MoveWindow(win, consolePos.left, consolePos.top, width, height, true);
}

void ConsoleUtil::shakeConsoleSmall()
{
    shakeConsole(35, 3);
}

void ConsoleUtil::shakeConsoleLarge()
{
    shakeConsole(100, 6);
}