
#ifndef VALHALLA_BASICGUIFRAME_H
#define VALHALLA_BASICGUIFRAME_H


#include "../structure/GuiFrame.h"
#include <windows.h>

class BasicGuiFrame : public GuiFrame
{
protected:
    HANDLE screenBuffer;
public:
    void activationHandler() override;
    void addHandler() override;
    void removeHandler() override;
};


#endif //VALHALLA_BASICGUIFRAME_H
