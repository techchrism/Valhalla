
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

        // If this was the last character, print the options
        if(currentChar == options.getText().length())
        {
            int optionNum = 1;
            short y = currentY + 2;
            short x = -1;
            OptionNode* current = options.getStart();
            while(current != nullptr)
            {
                string text = to_string(optionNum) + ") " + current->text;

                // Set the x value only once (using -1 as a flag)
                if(x == -1)
                {
                    x = ConsoleUtil::getProportionalLength(screenBuffer, 0.5, text.length());
                }

                ConsoleUtil::printString(screenBuffer, x, y, text);

                y++;
                optionNum++;
                current = current->next;
            }
        }
    }
}

void OptionsFrame::handleAnimationFrame(unsigned long tick)
{
    if(tick % 3 == 0)
    {
        printNextChar();
    }
}