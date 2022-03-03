// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Project, 3/2/22
//
// This program's behavior is to display the tree growing simulation that
// takes place in the 2d vector of bools, but in a graphics window.

#ifndef TREEGUI_H
#define TREEGUI_H
#include "TreeBaseBehavior.h"
#include "gwindow.h"
#include "gbutton.h"
using namespace sgl;
class TreeGui
{
public:
    // The TreeGui constructor accepts two integers representing the the height
    // and width of the Gwindow, a reference to a vector of all the trees and 
    // their behaviors, and a reference to a 2d vector representing the growing
    // space of the trees.
    TreeGui(int height, int width, vector<TreeBaseBehavior*>*& behavior,  vector<vector<bool>>*& table);
private:
    vector<TreeBaseBehavior*>* behavList;
    vector<vector<bool>>* table;
    GWindow* gwin;
    GButton* tickButton;
};

#endif // TREEGUI_H
