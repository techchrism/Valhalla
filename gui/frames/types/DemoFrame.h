
#ifndef VALHALLA2_DEMOFRAME_H
#define VALHALLA2_DEMOFRAME_H


#include "../abstract/BasicGuiFrame.h"
#include "../util/ConsoleUtil.h"

class DemoFrame : public BasicGuiFrame
{
private:
    // Counter to keep track of what line output is on (so we don't overwrite old text)
    int lineCounter = 1;
public:
    DemoFrame();

    // Override the add handler, and the keyboard/arrow handlers
    void addHandler() override;
    void handleInput(int code) override;
    void handleArrow(int code) override;
};

#endif //VALHALLA2_DEMOFRAME_H
