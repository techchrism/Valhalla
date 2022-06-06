
#ifndef VALHALLA_GUIFRAMESTACKINTERFACE_H
#define VALHALLA_GUIFRAMESTACKINTERFACE_H

template <typename T>
class GuiFrameStackInterface
{
public:
    virtual int getLength() = 0;
    virtual bool isEmpty() = 0;

    virtual T pop() = 0;
    virtual T top() = 0;
    virtual void pop(int amount) = 0;
    virtual void push(T frame) = 0;
};

#endif //VALHALLA_GUIFRAMESTACKINTERFACE_H
