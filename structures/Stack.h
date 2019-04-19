#ifndef VALHALLA2_STACK_H
#define VALHALLA2_STACK_H

#include "StackNode.h"

template <typename T>
class Stack
{
private:
    StackNode<T>* end;
    int length;

public:
    Stack()
    {
        end = nullptr;
        length = 0;
    }

    int getLength()
    {
        return length;
    }

    bool isEmpty()
    {
        return (length == 0);
    }

    T top()
    {
        return end->data;
    }

    T pop()
    {
        if(isEmpty())
        {
            // This should return an error (exceptions maybe) but instead it will crash the program
            return end->data;
        }
        else
        {
            // Get the top data to return
            T data = top();

            if(length == 1)
            {
                // If this is the only item, delete the stack
                delete end;
                end = nullptr;
            }
            else
            {
                // Otherwise make "end" the new end of the stack
                StackNode<T>* oldEnd = end;
                end = end->prev;
                delete oldEnd;
            }
            length--;

            return data;
        }
    }

    void push(T data)
    {
        StackNode<T>* newNode = new StackNode<T>(data);
        if(length == 0)
        {
            end = newNode;
        }
        else
        {
            newNode->prev = end;
            end = newNode;
        }
        length++;
    }
};

#endif //VALHALLA2_STACK_H
