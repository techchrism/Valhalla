
#include "GuiFrameStack.h"

void GuiFrameStack::push(GuiFrame* frame)
{
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