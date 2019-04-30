
#include "ChoicesStack.h"

ChoicesStack::ChoicesStack(GameState *state)
{
    this->state = state;
}

void ChoicesStack::push(Choice *choice, bool onAuto)
{
    choices.push(choice);

    // Check if the choice is "special" (such as popping the stack from time travel)
    int special = choice->onPush(state, onAuto);
    if(special != CHOICE_SPECIAL_NONE)
    {
        handleSpecialChoice(special);
    }
}

void ChoicesStack::handleSpecialChoice(int code)
{
    switch(code)
    {
        case CHOICE_SPECIAL_TRAVELBACK:
        {

            break;
        }
        default:
        {
            break;
        }
    }
}

Choice* ChoicesStack::pop(bool onAuto)
{
    choices.top()->onPop(state, onAuto);
    return choices.pop();
}

bool ChoicesStack::isEmpty()
{
    return choices.isEmpty();
}

Choice* ChoicesStack::top()
{
    return choices.top();
}

int ChoicesStack::getLength()
{
    return choices.getLength();
}