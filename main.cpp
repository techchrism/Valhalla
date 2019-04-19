#include <iostream>
#include "structures/Stack.h"

using namespace std;

// Function designed to run tests to ensure the code is working properly
// Not a full blown testing suite but close enough for our needs
// Will be removed on release
void runTests()
{
    cout << "Running tests..." << endl;
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

int main()
{
    runTests();

    return 0;
}
