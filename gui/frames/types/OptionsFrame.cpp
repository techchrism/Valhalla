
#include "OptionsFrame.h"

OptionsFrame::OptionsFrame(GameState state, Options options)
{
    screenBuffer = ConsoleUtil::generateBuffer();
    ConsoleUtil::hideCursor(screenBuffer);

    this->state = state;
    this->options = options;
}

void OptionsFrame::addHandler()
{
    reRender();
}

void OptionsFrame::activationHandler()
{
    reRender();
}

void OptionsFrame::reRender()
{
    SetConsoleActiveScreenBuffer(screenBuffer);

    currentX = STARTING_X;
    currentY = STARTING_Y;
    currentChar = 0;
}

void OptionsFrame::handleInput(int code)
{
    if(code == KEY_ENTER)
    {
        // Keep calling this function until it returns false
        // This prints all the text at once
        while(printNextChar()){}
    }
}

bool OptionsFrame::printNextChar()
{
    // Print the next character and return "false" if it's the last one
    if(currentChar >= options.getText().length())
    {
        return false;
    }
    else
    {
        char ch = options.getText()[currentChar];

        // If it's a newline character, increment y and reset x
        if(ch == '\n')
        {
            currentY++;
            currentX = STARTING_X;
        }
        else
        {
            // Print just a single character
            CHAR_INFO data;
            data.Char.AsciiChar = ch;
            data.Attributes = WHITE_TEXT;
            ConsoleUtil::writeOutput(screenBuffer, currentX, currentY, &data, 1, 1);

            currentX++;
        }
        currentChar++;
    }
}

void OptionsFrame::handleAnimationFrame(unsigned long tick)
{
    if(tick % 3 == 0)
    {
        printNextChar();
    }
}