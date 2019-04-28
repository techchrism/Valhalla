
#ifndef VALHALLA2_FRAMETEST_H
#define VALHALLA2_FRAMETEST_H


#include "../frames/structure/GuiFrame.h"
#include <string>
#include <iostream>
using namespace std;

class FrameTest : public GuiFrame
{
private:
    string name;
public:
    FrameTest(string name);

    void activationHandler() override;
    void deactivationHandler() override;
    void addHandler() override;
    void removeHandler() override;
};


#endif //VALHALLA2_FRAMETEST_H
