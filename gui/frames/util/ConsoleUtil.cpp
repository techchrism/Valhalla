
#include "ConsoleUtil.h"

void ConsoleUtil::printString(HANDLE screenBuffer, unsigned short x, unsigned short y, string data)
{
    CHAR_INFO wordData[data.length()];
    for(int i = 0; i < data.length(); i++)
    {
        wordData[i].Char.AsciiChar = data[i];
        wordData[i].Attributes = WHITE_TEXT;
    }

    short finishX = x + data.length();
    short finishY = y + 1;
    SMALL_RECT box;
    box.Left = x;
    box.Top = y;
    box.Right = finishX;
    box.Bottom = finishY;
    //= {x, y, finishX, finishY};
    short length = data.length();

    WriteConsoleOutput(screenBuffer, wordData, {length, 1}, {0, 0}, &box);
}