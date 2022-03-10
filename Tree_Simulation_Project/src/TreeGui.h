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
private:
    /*
     * Main system of update. Function will
     * show information of the tree if it pointed,
     * clear the gui, update trees and draw the gui.
     */
    void updateAll();
    /*
     * function will run if the user click on the canvas.
     * Clear out the text on lable. Set the tree pointer
     * to null pointer.
     * if the user is planning the tree, it will call
     * plant tree fuction if the planting spot is valid
     * else check if the click is at the growing tree
    */
    void clickGui(GEvent& e);
    //Clear out tree behavior list
    void clear();
    //adding tree to the gui base on what
    //the user whant to plant and is it
    //water or not
    //checking which position should insert in list of tree
    //which is important to determine which tree collided
    void addTree(int pos);
    //updating the tree behavior grow
    //checking if any tree colided each other
    //and then remove any tree that is dead
    void updateTree();
    //setting bool run true or false
    //and modified the text, the back ground color
    //of auto button
    void setAuto();
    //setting bool plant true or false
    //and modified the text, the back ground color
    //of plant button
    void setPlantMode();
    //drawing the the trees
    //then draw the leaf and fruit of each tree
    void draw();
    //create or overide the bool data grid base on given
    //isOveride or not
    void createDataGrid(bool isOverride);
    //if the user point the growing tree
    //showing the information in the GAreatext
    //showing the tree type, the state of the tree,
    //width and height of the tree
    //and tree is watered or not
    void showInformation()const;
    //use to draw the oval in gcanvas base on given position, size(width and height)
    //, use to draw leaf and fruit
    void drawOval(int x,int y,int height,int width,string color);
    vector<TreeBaseBehavior*> behavList;
    vector<vector<bool>>* gridTable;
    int gridSize;
    int months;
    int width;
    int height;
    bool isRunning;
    bool isPlanting;
    //use to show the formation of the pointed tree
    TreeBaseBehavior* treeInformation;
    //main window
    GWindow* gwin;
    //use to draw tree, leaf and fruit
    GCanvas* gcan;
    //choosing which tree to plant
    //Have 3 trees: Lemon, apple and orange
    GChooser* gChosPlant;
    //Tick box, use to determine if the user want the tree
    //is watered or not on planting
    GCheckBox* waterBox;
    //Use to output the information of the tree,
    //or warning the player if that place can't plant
    GTextArea* gtextArea;
    //Use as the timer, show how many month past
    GLabel* lable;
    //Use to set to plant mode or cancel
    GButton* plantButton;
    //clear out the gui and restart the gui plant tree
    GButton* clearButton;
    //run or stop the time in gui.
    GButton* autoButton;
};

#endif // TREEGUI_H
