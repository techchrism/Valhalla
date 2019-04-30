
#ifndef VALHALLA2_OPTIONNODE_H
#define VALHALLA2_OPTIONNODE_H

#include <string>
#include "../Choice.h"

using namespace std;

class OptionNode
{
public:
    OptionNode* next;
    string text;
    Choice* choice;

    OptionNode(string text, Choice* choice);
    ~OptionNode();
};


#endif //VALHALLA2_OPTIONNODE_H
