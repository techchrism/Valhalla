
#include "LightningFrame.h"

LightningFrame::LightningFrame()
{
    screenBuffer = ConsoleUtil::generateBuffer();
    ConsoleUtil::hideCursor(screenBuffer);
}

void LightningFrame::displayBolt()
{
    short width = 3;
    short height = ConsoleUtil::getBufferHeight(screenBuffer) - 1;
    // boltpos is a double from 0 to 1. this turns it into an actual x position
    short x = (ConsoleUtil::getBufferWidth(screenBuffer) * boltPos);

    for(int j = 0; j < width; j++)
    {
        // Output the lightning bolt column by column
        CHAR_INFO boltFragment[height];
        for(int i = 0; i < height; i++)
        {
            // Erase it at the start and end
            if(phase == 0 || phase == 10)
            {
                boltFragment[i].Char.AsciiChar = ' ';
                boltFragment[i].Attributes = WHITE_TEXT;
            }
            // Flash the lightning bolt depending on if the phase is even or odd
            else if(phase % 2 == 0)
            {
                boltFragment[i].Char.AsciiChar = '|';
                boltFragment[i].Attributes = BG_YELLOW | FG_WHITE;
            }
            else if(phase % 2 == 1)
            {
                boltFragment[i].Char.AsciiChar = '*';
                boltFragment[i].Attributes = BG_WHITE | FG_YELLOW;
            }
        }
        ConsoleUtil::writeOutput(screenBuffer, x + j, 1, boltFragment, 1, height);
    }

}

void LightningFrame::handleAnimationFrame(unsigned long tick)
{
    if(tick <= 50)
    {
        // Animate clouds coming in for the first 50 ticks

        // This represents "percent completeness" from 0 to 50
        double cloudsFraction = ((tick * (100.0 / 50.0)) / 100.0);

        // Find the number of cloud characters from the percent completeness
        int cloudsAmount = (cloudsFraction * ConsoleUtil::getBufferWidth(screenBuffer));
        string clouds = "";
        for(int i = 0; i < cloudsAmount; i++)
        {
            clouds += "#";
        }
        ConsoleUtil::printString(screenBuffer, ConsoleUtil::getProportionalLength(screenBuffer, 0.5, clouds.length()), 0, clouds);
    }
    else if(tick <= 200)
    {
        // Decide where the lightning bolt will be on the first phase
        if(phase == 0)
        {
            boltPos = ((double) rand() / (RAND_MAX));
        }

        // Flash the lightning bolt (and shake the screen) for the next 10 phases
        if(phase <= 10)
        {
            displayBolt();
            if(phase == 4)
            {
                ConsoleUtil::shakeConsoleSmall();
            }
        }

        // Increment the phase every other tick (and reset it once it hits 20)
        if(tick % 2 == 0)
        {
            phase++;
            if(phase > 20)
            {
                phase = 0;
            }
        }
    }

    // End the animation after 250 ticks
    if(tick == 250)
    {
        guiFrameStackInterface->pop();
    }
}