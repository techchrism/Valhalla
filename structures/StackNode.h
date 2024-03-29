#ifndef VALHALLA_STACKNODE_H
#define VALHALLA_STACKNODE_H

template <typename T>
class StackNode
{
public:
    T data;
    StackNode<T>* prev;

    StackNode(T data)
    {
        this->data = data;
        this->prev = nullptr;
    }
};

#endif //VALHALLA_STACKNODE_H
