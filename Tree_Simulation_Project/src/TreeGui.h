#ifndef TREEGUI_H
#define TREEGUI_H
#include "TreeBaseBehavior.h"
#include "gwindow.h"
#include "gbutton.h"
using namespace sgl;
class TreeGui
{
public:
    TreeGui(int height, int width, TreeBaseBehavior& behavior);
private:
    TreeBaseBehavior* behav;
    GWindow* gwin;
    GButton* tickButton;
};

#endif // TREEGUI_H
