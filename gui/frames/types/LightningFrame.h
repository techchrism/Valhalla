
#ifndef VALHALLA2_LIGHTNINGFRAME_H
#define VALHALLA2_LIGHTNINGFRAME_H

#include "../abstract/BasicGuiFrame.h"
#include "../util/ConsoleUtil.h"

class LightningFrame : public BasicGuiFrame
{
private:
    double boltPos;
    int phase;
    void displayBolt();
public:
    LightningFrame();

    void handleAnimationFrame(unsigned long tick) override;
};


#endif //VALHALLA2_LIGHTNINGFRAME_H
