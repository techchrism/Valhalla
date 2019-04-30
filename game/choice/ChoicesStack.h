
#ifndef VALHALLA2_CHOICESSTACK_H
#define VALHALLA2_CHOICESSTACK_H


#include "Choice.h"
#include "../../structures/Stack.h"

class ChoicesStack
{
private:
    Stack<Choice*> choices;
    GameState* state;
public:
    ChoicesStack(GameState* state);
    int getLength();
    bool isEmpty();
    Choice* top();
    Choice* pop(bool onAuto);
    void push(Choice* choice, bool onAuto);

    void handleSpecialChoice(int code);
};


#endif //VALHALLA2_CHOICESSTACK_H
