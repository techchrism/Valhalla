cmake_minimum_required(VERSION 3.13)
project(Valhalla2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic")

add_executable(Valhalla2 main.cpp structures/StackNode.h structures/Stack.h gui/frames/structure/GuiFrameStack.cpp gui/frames/structure/GuiFrameStack.h gui/frames/structure/GuiFrame.cpp gui/frames/structure/GuiFrame.h gui/frames/structure/GuiFrameStackInterface.h gui/test/FrameTest.cpp gui/test/FrameTest.h gui/frames/abstract/BasicGuiFrame.cpp gui/frames/abstract/BasicGuiFrame.h gui/frames/types/DemoFrame.cpp gui/frames/types/DemoFrame.h gui/frames/util/ConsoleUtil.cpp gui/frames/util/ConsoleUtil.h gui/frames/types/PortalFrame.cpp gui/frames/types/PortalFrame.h gui/frames/types/LightningFrame.cpp gui/frames/types/LightningFrame.h game/choice/ChoicesStack.cpp game/choice/ChoicesStack.h game/choice/Choice.h game/state/GameState.cpp game/state/GameState.h game/choice/options/Options.cpp game/choice/options/Options.h game/choice/options/OptionNode.cpp game/choice/options/OptionNode.h)