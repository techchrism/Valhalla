
#include "GameSetup.h"
#include "choice/choices/TimeTravelChoice.h"
#include "choice/actions/PortalAction.h"
#include "choice/actions/LightningAction.h"

OptionsFrame* GameSetup::getStartingOptions()
{
    GameState startingGameState;
    Options startingOptions;

    startingOptions.addOption("Time Travel Back", new LightningAction());
    startingOptions.setText("These are the starting options.\nChoose wisely.");

    return new OptionsFrame(startingGameState, startingOptions);
}