
#include "GameSetup.h"
#include "choice/choices/TimeTravelChoice.h"
#include "choice/actions/PortalAction.h"

OptionsFrame* GameSetup::getStartingOptions()
{
    GameState startingGameState;
    Options startingOptions;

    //Choice* choice = new TimeTravelChoice();
    startingOptions.addOption("Time Travel Back", new PortalAction());
    startingOptions.setText("These are the starting options.\nChoose wisely.");

    return new OptionsFrame(startingGameState, startingOptions);
}