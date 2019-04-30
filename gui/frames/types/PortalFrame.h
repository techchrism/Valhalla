
#ifndef VALHALLA2_PORTALFRAME_H
#define VALHALLA2_PORTALFRAME_H

#include "../abstract/BasicGuiFrame.h"
#include "../util/ConsoleUtil.h"
#include <math.h>

class PortalFrame : public BasicGuiFrame
{
private:
    unsigned long internalTick = 0;
    double scale = 0.4;

    void render();
public:
    PortalFrame();

    // Override the add handler
    //void addHandler() override;

    // Listen for animation ticks
    void handleAnimationFrame(unsigned long tick) override;
};


#endif //VALHALLA2_PORTALFRAME_H
