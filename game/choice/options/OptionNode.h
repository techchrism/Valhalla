
#ifndef VALHALLA_OPTIONNODE_H
#define VALHALLA_OPTIONNODE_H

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


#endif //VALHALLA_OPTIONNODE_H
