
#ifndef VALHALLA_OPTIONS_H
#define VALHALLA_OPTIONS_H


#include "../Choice.h"
#include "OptionNode.h"
#include <string>
using namespace std;

class Options
{
private:
    OptionNode* start;
    OptionNode* end;
    string text;
public:
    OptionNode* selected;

    Options();
    ~Options();

    void setText(string text);
    void addOption(string text, Action* action);
    int getLength();
    OptionNode* getStart();
    string getText();
};


#endif //VALHALLA_OPTIONS_H
