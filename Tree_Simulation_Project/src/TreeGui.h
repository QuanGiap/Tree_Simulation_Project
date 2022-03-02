#ifndef TREEGUI_H
#define TREEGUI_H
#include "TreeBaseBehavior.h"
#include "gwindow.h"
#include "gbutton.h"
using namespace sgl;
class TreeGui
{
public:
    TreeGui(int height, int width, vector<TreeBaseBehavior>& behavior,  vector<vector<bool>>*& table);
private:
    vector<TreeBaseBehavior>* behav;
    vector<vector<bool>>* table;
    GWindow* gwin;
    GButton* tickButton;
};

#endif // TREEGUI_H
