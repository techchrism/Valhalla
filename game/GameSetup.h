
#ifndef VALHALLA_GAMESETUP_H
#define VALHALLA_GAMESETUP_H


#include "choice/options/Options.h"
#include "state/GameState.h"
#include "../gui/frames/types/OptionsFrame.h"

class GameSetup
{
public:
    static OptionsFrame* getStartingOptions();
};


#endif //VALHALLA_GAMESETUP_H
