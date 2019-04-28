
#ifndef VALHALLA2_GUIFRAMESTACKINTERFACE_H
#define VALHALLA2_GUIFRAMESTACKINTERFACE_H

template <typename T>
class GuiFrameStackInterface
{
public:
    virtual int getLength() = 0;
    virtual bool isEmpty() = 0;

    virtual T pop() = 0;
    virtual T top() = 0;
    virtual void push(T frame) = 0;
};

#endif //VALHALLA2_GUIFRAMESTACKINTERFACE_H
