#ifndef TREEGUI_H
#define TREEGUI_H
#include "gwindow.h"
#include "gbutton.h"
using namespace sgl;
class TreeGui
{
public:
    TreeGui(int height, int width);
private:
    GWindow* gwin;
    GButton* tickButton;
};

#endif // TREEGUI_H
