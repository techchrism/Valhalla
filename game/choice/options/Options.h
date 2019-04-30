
#ifndef VALHALLA2_OPTIONS_H
#define VALHALLA2_OPTIONS_H


#include "../Choice.h"
#include "OptionNode.h"
#include <string>
using namespace std;

class Options
{
private:
    OptionNode* start;
    OptionNode* end;
public:
    OptionNode* selected;

    Options();
    ~Options();

    void addOption(string text, Choice* choice);
    int getLength();
    OptionNode* getStart();
};


#endif //VALHALLA2_OPTIONS_H
