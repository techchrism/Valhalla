
#ifndef VALHALLA2_CONSOLEUTIL_H
#define VALHALLA2_CONSOLEUTIL_H

#include <windows.h>
#include <string>
using namespace std;

#define WHITE_TEXT FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED

class ConsoleUtil
{
public:
    static void writeOutput(HANDLE screenBuffer, short x, short y, CHAR_INFO* text, short columns, short rows);
    static void printString(HANDLE screenBuffer, short x, short y, string data);
};


#endif //VALHALLA2_CONSOLEUTIL_H