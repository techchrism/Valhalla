#include <iostream>
#include "structures/Stack.h"
#include "gui/frames/GuiFrameStack.h"
#include "gui/test/FrameTest.h"

using namespace std;

// Functions designed to run tests to ensure the code is working properly
// Not a full blown testing suite but close enough for our needs
// Will be removed on release

void runStackTests()
{
    cout << "Running stack tests..." << endl;
    Stack<int> intStack;
    cout << "Initial stack length: " << intStack.getLength() << endl;
    for(int i = 0; i < 10; i++)
    {
        intStack.push(i + 1);
    }
    cout << "New stack length: " << intStack.getLength() << endl;
    cout << "Stack contents:" << endl;
    while(!intStack.isEmpty())
    {
        cout << intStack.pop() << endl;
    }
    cout << "Empty stack length: " << intStack.getLength() << endl;
}

void runBasicFrameStackTests()
{
    cout << "Running basic FrameStack tests..." << endl;
    GuiFrameStack frameStack;
    cout << endl;
    frameStack.push(new FrameTest("First one"));
    cout << endl;
    frameStack.push(new FrameTest("Second one"));
    cout << endl;
    frameStack.push(new FrameTest("pop-me"));
    cout << endl;
    frameStack.push(new FrameTest("Third one"));
    cout << endl;

    /*
    Outputs the following:
        First one has been added

        First one has been deactivated
        Second one has been added

        Second one has been deactivated
        pop-me has been added
        Trying a self-pop!
        pop-me has been removed
        Second one has been activated

        Second one has been deactivated
        Third one has been added
     */

    while(!frameStack.isEmpty())
    {
        frameStack.pop();
    }
}

int main()
{
    //runStackTests();
    runBasicFrameStackTests();

    return 0;
}
