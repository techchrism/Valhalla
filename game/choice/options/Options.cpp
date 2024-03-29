
#include "Options.h"

Options::Options()
{
    start = end = selected = nullptr;
}

Options::~Options()
{
    // Delete the stack to avoid memory leaks
    /*OptionNode* current = start;
    while(current != nullptr)
    {
        OptionNode* next = current->next;
        delete current;
        current = next;
    }*/
}

void Options::addOption(string text, Action *action)
{
    // Add the data as a new node
    OptionNode* node = new OptionNode(text, action);
    if(end == nullptr)
    {
        start = end =node;
    }
    else
    {
        end->next = node;
        end = node;
    }
}

int Options::getLength()
{
    // Go through the list until nullptr is reached to find the length
    int i = 0;
    OptionNode* current = start;
    while(current != nullptr)
    {
        current = current->next;
        i++;
    }
    return i;
}

OptionNode* Options::getStart()
{
    return start;
}

void Options::setText(string text)
{
    this->text = text;
}

string Options::getText()
{
    return text;
}