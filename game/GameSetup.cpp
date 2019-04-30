
#include "GameSetup.h"

OptionsFrame* GameSetup::getStartingOptions()
{
    GameState startingGameState;
    Options startingOptions;
    startingOptions.setText("These are the starting options.\nChoose wisely.");

    return new OptionsFrame(startingGameState, startingOptions);
}