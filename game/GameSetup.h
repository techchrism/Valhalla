
#ifndef VALHALLA2_GAMESETUP_H
#define VALHALLA2_GAMESETUP_H


#include "choice/options/Options.h"
#include "state/GameState.h"
#include "../gui/frames/types/OptionsFrame.h"

class GameSetup
{
public:
    static OptionsFrame* getStartingOptions();
};


#endif //VALHALLA2_GAMESETUP_H
