// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "TreeGui.h"
#include <iostream>
#include <string>
#include "TreeGui.h"
#include "Lemon.h"
#include "Apple.h"
#include "Orange.h"
#include "Sapling.h"

int const GRID_SIZE = 4;
int const DELAY = 250;
TreeGui::TreeGui(int height, int width) {
    isRunning = false;
    months = 0;
    isPlanting = false;
    //create data grid
    gridTable = new vector<vector<bool>>;
    for(int i = 0;i < height;i++){
        vector<bool> temp;
        for(int j = 0;j<width;j++){
            temp.push_back(false);
        };
        gridTable->push_back(temp);
    }
    //create test;
    behavList.push_back(new Sapling(*new Lemon(10,false,gridTable)));
    behavList.push_back(new Sapling(*new Lemon(25,false,gridTable)));
    //Add window
    gwin = new GWindow(GRID_SIZE*width+100, GRID_SIZE*height+100);
    gwin->setTitle("Tree Simulation");
    gwin->setBackground("White");
    gwin->setExitOnClose(true);   
    gwin->setTimerListener(DELAY, [this]{updateAll();});
    //Add canvas
    gcan = new GCanvas(GRID_SIZE*width, GRID_SIZE*height);
    gcan->setBackground("blue");
    gcan->setAutoRepaint(false);
    gcan->setClickListener([this](GEvent e){clickGui(e);});
    gwin->addToRegion(gcan,GWindow::Region::REGION_CENTER);
    //Add GChooser
    gChosPlant = new GChooser();
    gChosPlant->addItem("Apple");
    gChosPlant->addItem("Lemon");
    gChosPlant->addItem("Orange");
    gwin->addToRegion(gChosPlant,GWindow::Region::REGION_SOUTH);
    //Add checkbox
    waterBox = new GCheckBox("Add water?");
    gwin->addToRegion(waterBox,GWindow::Region::REGION_SOUTH);
    //Add text area
    gtextArea = new GTextArea(3,100);
    gtextArea->setEditable(false);
    gwin->addToRegion(gtextArea,GWindow::Region::REGION_NORTH);
    //add lable
    lable = new GLabel("Month :");
    gwin->addToRegion(lable,GWindow::Region::REGION_NORTH);
    //Add GButoon
    plantButton = new GButton("Plant mode");
    clearButton = new GButton("Clear");
    autoButton = new GButton("Set auto on");
    gwin->addToRegion(plantButton,GWindow::Region::REGION_SOUTH);
    gwin->addToRegion(clearButton,GWindow::Region::REGION_SOUTH);
    gwin->addToRegion(autoButton,GWindow::Region::REGION_SOUTH);
    autoButton->setActionListener([this]{setAuto();});
    plantButton->setActionListener([this]{setPlantMode();});
    //holding the line operate else it will cause segmentation fault
    while(gwin->isOpen()){}
}
void TreeGui::clickGui(GEvent& e){
    if(isPlanting)
        addTree(e.getX()/GRID_SIZE);
}
void TreeGui::addTree(int pos){
    int choice = gChosPlant->getSelectedIndex();
    bool isWater = waterBox->isChecked();
    TreeBase* tree;
    int i = 0;
    while(i < behavList.size() && behavList[i]->getTreeBase().getPlantPos()<pos){
        i+=1;
    }
    if(choice == 0) tree = new Apple(pos,isWater,gridTable);
    else if(choice == 1) tree = new Lemon(pos,isWater,gridTable);
    else tree = new Orange(pos,isWater,gridTable);
    if(i == behavList.size()) behavList.push_back(new Sapling(*tree));
    else behavList.insert(behavList.begin()+i,new Sapling(*tree));
}
void TreeGui::setAuto(){
    //comparing char, avoiding compare string to reduce run time complexity
    if(!isRunning){
        autoButton->setText("Turn off");
        autoButton->setBackground("red");
        isRunning = true;
    }
    else{
        autoButton->setText("Set auto on");
        autoButton->setBackground("white");
        isRunning = false;
    }
}
void TreeGui::setPlantMode(){
    if(!isPlanting){
        plantButton->setText("Cancel planting");
        plantButton->setBackground("red");
        isPlanting = true;
    }
    else{
        plantButton->setText("Plant mode");
        plantButton->setBackground("white");
        isPlanting = false;
    }
}
void TreeGui::updateAll() {
    if(isRunning){
    months +=1;
    lable->setText("Month :"+to_string(months));
    gcan->clear();
    updateTree();
    draw();
    }
}
void TreeGui::updateTree(){
    for(int i = 0; i < behavList.size(); i++) {
        behavList[i]->update();
        if(behavList[i]->isOld()) {
            TreeBaseBehavior* copy = behavList[i]->switchState();
            delete behavList[i];
            behavList[i] = copy;
        }
    }
    //check if any tree colided
    for(int i = 0; i < behavList.size()-1; i++) {
        if(behavList[i]->getTreeBase().isInTheWay(behavList[i+1]->getTreeBase())){
            int height1 = behavList[i]->getTreeBase().getHeight();
            int width1 = behavList[i]->getTreeBase().getWidth();
            int height2 = behavList[i+1]->getTreeBase().getHeight();
            int width2 = behavList[i+1]->getTreeBase().getWidth();
            //which tree have larger area survive
            if(height1*width1>height2*width2){
            behavList[i+1]->getTreeBase().setDead(true);
            }
            else if(height1*width1<height2*width2){
                behavList[i]->getTreeBase().setDead(true);
            }
            else{
                int choice = rand()%2;
                behavList[i+choice]->getTreeBase().setDead(true);
            }
        }
    }
    //delete any tree that is die
    for(int i = 0; i < behavList.size(); i++){
        if(behavList[i]->getTreeBase().getDead()){
            delete &behavList[i]->getTreeBase();
            delete behavList[i];
            behavList.erase(behavList.begin()+i);
            i--;
        }
    }
    cout<<"Done delete"<<endl;
}
void TreeGui::draw(){
    gcan->setColor("brown");
    gcan->setFillColor("brown");
    for(int j = 0; j < gridTable->size(); j++) {
        for(int k = 0; k < (*gridTable)[0].size(); k++) {
            if((*gridTable)[j][k]) {
                gcan->fillRect(GRID_SIZE * k, GRID_SIZE * j, GRID_SIZE, GRID_SIZE);
            }
        }
    }
    gcan->setColor("green");
    gcan->setFillColor("green");
    for(int i = 0; i < behavList.size(); i++) {
        int wid = behavList[i]->getTreeBase().getWidth()*GRID_SIZE*3;
        int hei = behavList[i]->getTreeBase().getHeight()*GRID_SIZE;
        int x = ((behavList[i]->getTreeBase().getPlantPos())*GRID_SIZE)-GRID_SIZE/2;
        int y = (behavList[i]->getTreeBase().getHeightData() - behavList[i]->getTreeBase().getHeight())*GRID_SIZE;
        GOval oval(0,0,wid,hei);
        oval.setCenterX(x);
        oval.setCenterY(y);
        gcan->fillOval(oval.getBounds());
    }
    gcan->repaint();
}
