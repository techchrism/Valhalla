
#ifndef VALHALLA2_BASICGUIFRAME_H
#define VALHALLA2_BASICGUIFRAME_H


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


#endif //VALHALLA2_BASICGUIFRAME_H
