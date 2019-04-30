
#include "PortalFrame.h"

PortalFrame::PortalFrame()
{
    screenBuffer = ConsoleUtil::generateBuffer();
    ConsoleUtil::hideCursor(screenBuffer);
}

void PortalFrame::render()
{
    internalTick++;
    scale += 0.04;

    short width = ConsoleUtil::getBufferWidth(screenBuffer);
    short height = ConsoleUtil::getBufferHeight(screenBuffer);

    char types[4] = {' ', '#', '@', '*'};
    WORD colors[3] = {
            144 | 15,
            80 | 11,
            16 | 15
    };

    for(int y = 0; y < height; y++)
    {
        CHAR_INFO portal[width];
        for(int x = 0; x < width; x++)
        {
            int distance = sqrt(pow(x - (width / 2), 2) + pow((y - (height / 2)) * scale, 2));

            portal[x].Attributes = colors[((int)((distance * 1.3) + internalTick) % 12) / 3];

            portal[x].Char.AsciiChar = types[((int)((distance * 0.8) + internalTick) % 12) / 3];
        }

        ConsoleUtil::writeOutput(screenBuffer, 0, y, portal, width, 1);
    }

    if(scale >= 4.5)
    {
        guiFrameStackInterface->pop();
    }
}

void PortalFrame::handleAnimationFrame(unsigned long tick)
{
    if(tick % 2 == 0)
    {
        render();
    }
}