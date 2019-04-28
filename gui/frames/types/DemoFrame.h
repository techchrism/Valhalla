
#ifndef VALHALLA2_DEMOFRAME_H
#define VALHALLA2_DEMOFRAME_H


#include "../abstract/BasicGuiFrame.h"
#include "../util/ConsoleUtil.h"

class DemoFrame : public BasicGuiFrame
{
private:
    int lineCounter = 1;
public:
    DemoFrame();

    void addHandler() override;
    void handleInput(int code) override;
    void handleArrow(int code) override;
};


#endif //VALHALLA2_DEMOFRAME_H
