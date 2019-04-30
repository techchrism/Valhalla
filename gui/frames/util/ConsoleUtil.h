
#ifndef VALHALLA2_CONSOLEUTIL_H
#define VALHALLA2_CONSOLEUTIL_H

#include <windows.h>
#include <string>
using namespace std;

#define WHITE_TEXT FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED
#define FG_BLACK 0
#define FG_BLUE 1
#define FG_GREEN 2
#define FG_CYAN 3
#define FG_RED 4
#define FG_MAGENTA 5
#define FG_BROWN 6
#define FG_LIGHTGRAY 7
#define FG_GRAY 8
#define FG_LIGHTBLUE 9
#define FG_LIGHTGREEN 10
#define FG_LIGHTCYAN 11
#define FG_LIGHTRED 12
#define FG_LIGHTMAGENTA 13
#define FG_YELLOW 14
#define FG_WHITE 15

#define BG_NAVYBLUE 16
#define BG_GREEN 32
#define BG_TEAL 48
#define BG_MAROON 64
#define BG_PURPLE 80
#define BG_OLIVE 96
#define BG_SILVER 112
#define BG_GRAY 128
#define BG_BLUE 144
#define BG_LIME 160
#define BG_CYAN 176
#define BG_RED 192
#define BG_MAGENTA 208
#define BG_YELLOW 224
#define BG_WHITE 240

class ConsoleUtil
{
public:
    static HANDLE generateBuffer();
    static void hideCursor(HANDLE screenBuffer);

    static void writeOutput(HANDLE screenBuffer, short x, short y, CHAR_INFO* text, short columns, short rows);
    static void printString(HANDLE screenBuffer, short x, short y, string data);

    static short getBufferHeight(HANDLE screenBuffer);
    static short getBufferWidth(HANDLE screenBuffer);

    static short getProportionalLength(HANDLE screenBuffer, double fraction, short length);
    static short getProportionalHeight(HANDLE screenBuffer, double fraction, short height);

    static void shakeConsole(int scale, int amount);
    static void shakeConsoleSmall();
    static void shakeConsoleLarge();
};


#endif //VALHALLA2_CONSOLEUTIL_H
