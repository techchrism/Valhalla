
#include "GameSetup.h"
#include "choice/choices/TimeTravelChoice.h"
#include "choice/actions/PortalAction.h"
#include "choice/actions/LightningAction.h"
#include "choice/actions/PushAction.h"

OptionsFrame* GameSetup::getStartingOptions()
{
    GameState startingGameState;

    Options complete;
    complete.setText("You defeat the goblin and you now have a choice: ");
    complete.addOption("Go left through the hallway", new PortalAction());
    complete.addOption("Go straight through the door", new PortalAction());
    OptionsFrame* completeFrame = new OptionsFrame(startingGameState, complete);

    Options deathOptions;
    deathOptions.setText("You were about to die but you realized you can travel back in time");
    deathOptions.addOption("Travel back in time", new PortalAction());
    OptionsFrame* deathFrame = new OptionsFrame(startingGameState, deathOptions);

    Options firstEncounter;
    firstEncounter.setText("During one of your regular heists on another planet, you encounter a goblin.\n\"HALT\" shouts the goblin. He has a laser out and is about to shoot.");
    firstEncounter.addOption("Fire Lightning Bolts", new LightningAction(completeFrame));
    firstEncounter.addOption("Run in Fear", new PushAction(deathFrame));
    OptionsFrame* firstEncounterFrame = new OptionsFrame(startingGameState, firstEncounter);

    Options startingOptions;
    startingOptions.addOption("Sounds Good", new PushAction(firstEncounterFrame));
    startingOptions.setText("You've just woken up.\n\nIt appears you're a wizard who goes back in time to steal art for\nyour town, who needs it to power a crystal to stop\nthe raging meteors falling on Earth.\n\nTo play, press the number on your keyboard coresponding to your choice.");



    return new OptionsFrame(startingGameState, startingOptions);
}