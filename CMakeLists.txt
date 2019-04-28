cmake_minimum_required(VERSION 3.13)
project(Valhalla2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(Valhalla2 main.cpp structures/StackNode.h structures/Stack.h gui/frames/GuiFrameStack.cpp gui/frames/GuiFrameStack.h gui/frames/GuiFrame.cpp gui/frames/GuiFrame.h gui/frames/GuiFrameStackInterface.h gui/test/FrameTest.cpp gui/test/FrameTest.h structures/StackInterface.h)