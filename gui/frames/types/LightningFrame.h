
#ifndef VALHALLA_LIGHTNINGFRAME_H
#define VALHALLA_LIGHTNINGFRAME_H

#include "../abstract/BasicGuiFrame.h"
#include "../util/ConsoleUtil.h"

class LightningFrame : public BasicGuiFrame
{
private:
    double boltPos;
    int phase;
    void displayBolt();

    GuiFrame* next;
public:
    LightningFrame(GuiFrame* next);

    void handleAnimationFrame(unsigned long tick) override;
};


#endif //VALHALLA_LIGHTNINGFRAME_H
