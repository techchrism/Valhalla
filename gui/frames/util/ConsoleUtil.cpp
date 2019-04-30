
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