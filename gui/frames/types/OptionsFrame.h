
#ifndef VALHALLA2_OPTIONSFRAME_H
#define VALHALLA2_OPTIONSFRAME_H


#include "../../../game/state/GameState.h"
#include "../../../game/choice/options/Options.h"
#include "../abstract/BasicGuiFrame.h"
#include "../util/ConsoleUtil.h"

#define STARTING_Y 3
#define STARTING_X 10

class OptionsFrame : public BasicGuiFrame
{
private:
    GameState state;
    Options options;

    short currentX;
    short currentY;
    int currentChar;

    void reRender();
    bool printNextChar();
public:
    OptionsFrame(GameState state, Options options);

    virtual void handleAnimationFrame(unsigned long tick) override;
    virtual void handleInput(int code) override;
    virtual void addHandler() override;
    virtual void activationHandler() override;
};


#endif //VALHALLA2_OPTIONSFRAME_H
