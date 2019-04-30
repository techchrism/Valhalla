
#include "OptionNode.h"

OptionNode::OptionNode(string text, Choice *choice)
{
    this->text = text;
    this->choice = choice;
    this->next = nullptr;
}

OptionNode::~OptionNode()
{
    delete choice;
}