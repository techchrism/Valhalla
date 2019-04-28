
#include "FrameTest.h"

FrameTest::FrameTest(string name)
{
    this->name = name;
}

void FrameTest::activationHandler()
{
    cout << name << " has been activated" << endl;
}

void FrameTest::deactivationHandler()
{
    cout << name << " has been deactivated" << endl;
}

void FrameTest::addHandler()
{
    cout << name << " has been added" << endl;

    if(name == "pop-me")
    {
        cout << "Trying a self-pop!" << endl;
        guiFrameStackInterface->pop();
    }
}

void FrameTest::removeHandler()
{
    cout << name << " has been removed" << endl;
}