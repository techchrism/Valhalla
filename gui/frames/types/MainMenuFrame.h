
#ifndef VALHALLA_MAINMENUFRAME_H
#define VALHALLA_MAINMENUFRAME_H


#include "../abstract/BasicGuiFrame.h"
#include "../util/ConsoleUtil.h"

#include <string>
using namespace std;

class MainMenuFrame : public BasicGuiFrame
{
public:
    MainMenuFrame();

    void handleInput(int code) override;
};


#endif //VALHALLA_MAINMENUFRAME_H
