
#ifndef VALHALLA2_OPTIONNODE_H
#define VALHALLA2_OPTIONNODE_H

#include <string>
#include "../Choice.h"
#include "../Action.h"

using namespace std;

class OptionNode
{
public:
    OptionNode* next;
    string text;
    Action* action;

    OptionNode(string text, Action* choice);
    ~OptionNode();
};


#endif //VALHALLA2_OPTIONNODE_H
