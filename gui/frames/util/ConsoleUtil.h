
#ifndef VALHALLA2_CONSOLEUTIL_H
#define VALHALLA2_CONSOLEUTIL_H

#include <windows.h>
#include <string>
using namespace std;

#define WHITE_TEXT FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED

class ConsoleUtil
{
public:
    static void printString(HANDLE screenBuffer, unsigned short x, unsigned short y, string data);
};


#endif //VALHALLA2_CONSOLEUTIL_H
