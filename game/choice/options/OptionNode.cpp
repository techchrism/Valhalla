
#include "OptionNode.h"

OptionNode::OptionNode(string text, Action* action)
{
    this->text = text;
    this->action = action;
    this->next = nullptr;
}

OptionNode::~OptionNode()
{
    delete action;
}