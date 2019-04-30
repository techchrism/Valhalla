
#include "PortalFrame.h"

PortalFrame::PortalFrame()
{
    // Create the buffer and hide the cursor
    screenBuffer = ConsoleUtil::generateBuffer();
    ConsoleUtil::hideCursor(screenBuffer);
}

void PortalFrame::render()
{
    // Increase the internal tick (used as a time constant) and the scale for the portal
    internalTick++;
    scale += 0.04;

    short width = ConsoleUtil::getBufferWidth(screenBuffer);
    short height = ConsoleUtil::getBufferHeight(screenBuffer);

    // Different characters and colors for the portal
    char types[4] = {' ', '#', '@', '*'};
    WORD colors[3] = {
            BG_BLUE | FG_WHITE,
            BG_PURPLE | FG_LIGHTCYAN,
            BG_NAVYBLUE | FG_WHITE
    };

    // Write the portal data line by line
    for(int y = 0; y < height; y++)
    {
        CHAR_INFO portal[width];
        for(int x = 0; x < width; x++)
        {
            // Use trig distance formula from the center of the screen
            // Includes custom scaling factor in y-direction for portal wrapping effects
            int distance = sqrt(pow(x - (width / 2), 2) + pow((y - (height / 2)) * scale, 2));

            // Based on the time constant and the distance from center, decide what color and character to show
            // Apply a speed factor (1.3 and 0.8) to make the colors travel faster than the characters
            // Use modulus to make each color/character band 3x thicker
            portal[x].Attributes = colors[((int)((distance * 1.3) + internalTick) % 12) / 3];
            portal[x].Char.AsciiChar = types[((int)((distance * 0.8) + internalTick) % 12) / 3];
        }

        ConsoleUtil::writeOutput(screenBuffer, 0, y, portal, width, 1);
    }

    // Once the scaling factor has reached this point, exit the portal
    if(scale >= 4.5)
    {
        guiFrameStackInterface->pop();
    }
}

void PortalFrame::handleAnimationFrame(unsigned long tick)
{
    // Do a portal tick every other regular tick
    if(tick % 2 == 0)
    {
        render();
    }
}