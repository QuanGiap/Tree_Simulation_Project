// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Project, 3/2/22
//
// This program's behavior is to display the tree growing simulation that
// takes place in the 2d vector of bools, but in a graphics window.

#ifndef TREEGUI_H
#define TREEGUI_H
#include "TreeBaseBehavior.h"
#include "gwindow.h"
#include "gwindow.h"
#include "gbutton.h"
#include "gcanvas.h"
#include "gevent.h"
#include "gchooser.h"
#include "gcheckbox.h"
#include "gtextarea.h"
#include "glabel.h"
using namespace sgl;
class TreeGui
{
public:
    // The TreeGui constructor accepts two integers representing the the height
    // and width of the grid data
    TreeGui(int height, int width);
    void updateAll();
private:
    void clickGui(GEvent& e);
    void clear();
    void addTree(int pos);
    void updateTree();
    void setAuto();
    void setPlantMode();
    void draw();
    void createDataGrid(bool isOverride);
    void showInformation();
    vector<TreeBaseBehavior*> behavList;
    vector<vector<bool>>* gridTable;
    int gridSize;
    int months;
    int width;
    int height;
    bool isRunning;
    bool isPlanting;
    TreeBaseBehavior* treeInformation;
    GWindow* gwin;
    GCanvas* gcan;
    GChooser* gChosPlant;
    GCheckBox* waterBox;
    GTextArea* gtextArea;
    GLabel* lable;
    GButton* plantButton;
    GButton* clearButton;
    GButton* autoButton;
};

#endif // TREEGUI_H
