
#include "GuiFrameStack.h"

GuiFrameStack::GuiFrameStack()
{
    inputHandle = GetStdHandle(STD_INPUT_HANDLE);
}

void GuiFrameStack::push(GuiFrame* frame)
{
    // Reset the animation tick
    tick = 0;

    // Call the deactivate handler for the old top frame and the add handler for the new one
    if(!frames.isEmpty())
    {
        frames.top()->onDeactivate();
    }
    frames.push(frame);
    frames.top()->onAdd(this);
}

GuiFrame* GuiFrameStack::pop()
{
    // Call the remove handler for the frame being popped and pop it
    frames.top()->onRemove();
    GuiFrame* old = frames.pop();

    // Then call the activation handler for the current frame
    if(!frames.isEmpty())
    {
        frames.top()->onActivate();
    }

    // Reset the animation tick
    tick = 0;

    return old;
}

GuiFrame* GuiFrameStack::top()
{
    return frames.top();
}

bool GuiFrameStack::isEmpty()
{
    return frames.isEmpty();
}

int GuiFrameStack::getLength()
{
    return frames.getLength();
}

void GuiFrameStack::handleAnimationTick()
{
    if(!frames.isEmpty())
    {
        frames.top()->handleAnimationFrame(tick);
        tick++;
    }
}

void GuiFrameStack::handleEvents()
{
    // Get console events (NOTE: this is a blocking operation)
    DWORD numRead;
    INPUT_RECORD inBuf[128];
    ReadConsoleInput(inputHandle, inBuf, 128, &numRead);

    // Iterate through the events
    for(int i = 0; i < numRead; i++)
    {
        // Don't handle input if there's nothing in the stack
        if(frames.isEmpty())
        {
            break;
        }

        // Send the event to what's on top of the stack
        switch(inBuf[i].EventType)
        {
            case KEY_EVENT:
            {
                // If it's a keyboard event, handle it
                KEY_EVENT_RECORD ev = inBuf[i].Event.KeyEvent;
                DWORD vk = ev.wVirtualKeyCode;
                if(ev.bKeyDown)
                {
                    // Check if the ctrl key is pressed
                    if(((ev.dwControlKeyState & LEFT_CTRL_PRESSED) == LEFT_CTRL_PRESSED ||
                        (ev.dwControlKeyState & RIGHT_CTRL_PRESSED) == RIGHT_CTRL_PRESSED)
                       && vk != VK_CONTROL)
                    {
                        // Sends 1 for a, 2-b, 3-c, ect.
                        // Add 96 to convert to proper ascii
                        top()->handleCtrl(ev.uChar.AsciiChar + 96);
                    }
                    else if(vk == VK_LEFT || vk == VK_RIGHT || vk == VK_UP || vk == VK_DOWN)
                    {
                        top()->handleArrow(vk);
                    }
                    else
                    {
                        top()->handleInput(ev.uChar.AsciiChar);
                    }
                }
                break;
            }
            case WINDOW_BUFFER_SIZE_EVENT:
            {
                // Handle window resize events
                top()->onResize();
                break;
            }
            case MOUSE_EVENT:
            {
                top()->handleMouse(inBuf[i].Event.MouseEvent);
            }
            default:
            {
                break;
            }
        }
    }
}