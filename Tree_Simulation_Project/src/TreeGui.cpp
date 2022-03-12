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
int const DELAY = 100;
TreeGui::TreeGui(int height, int width) {
    isRunning = false;
    treeInformation = nullptr;
    months = 0;
    isPlanting = false;
    this->width = width;
    this->height = height;
    //create data grid
    gridTable = new vector<vector<bool>>;
    createDataGrid(false);
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
    gtextArea->setFont("MS Shell Dlg 5");
    gwin->addToRegion(gtextArea,GWindow::Region::REGION_NORTH);
    //add lable
    lable = new GLabel("Month :");
    gwin->addToRegion(lable,GWindow::Region::REGION_NORTH);   
    lable->setFont("MS Shell Dlg 10");
    //Add GButoon
    plantButton = new GButton("Plant mode");
    clearButton = new GButton("Clear");
    autoButton = new GButton("Run");
    gwin->addToRegion(plantButton,GWindow::Region::REGION_SOUTH);
    gwin->addToRegion(clearButton,GWindow::Region::REGION_SOUTH);
    gwin->addToRegion(autoButton,GWindow::Region::REGION_SOUTH);
    autoButton->setActionListener([this]{setAuto();});
    plantButton->setActionListener([this]{setPlantMode();});
    clearButton->setActionListener([this]{clear();});
    //holding the line operate else it will cause segmentation fault
    while(gwin->isOpen()){}
}
void TreeGui::createDataGrid(bool isOverride){
    for(int i = 0;i < height;i++){
        vector<bool> temp;
        for(int j = 0;j<width;j++){
            temp.push_back(false);
        };
        if(isOverride) (*gridTable)[i] = temp;
        else gridTable->push_back(temp);
    }
}
void TreeGui::clickGui(GEvent& e){
    gtextArea->setText("");
    //set to null ptr every time user click the gui
    treeInformation=nullptr;
    //see which spot click in data grid in x direction.
    int plantPos = e.getX()/GRID_SIZE;
    if(isPlanting){
        int i = 0;
        //checking if there is no trees in plant position
        while(i<behavList.size()
              && !behavList[i]->getTreeBase().isInTheWay(plantPos)){
            i++;
        }
        //i == list of tree size --> no tree in the way
        if(i == behavList.size()){
            addTree(plantPos);
        }
        else{
            gtextArea->setText("Can't plant in that position");
        }
    }
    else{
        //checking if there is any tree is at the click point
        for(int i = 0;i<behavList.size()&&treeInformation == nullptr;i++){
            if(behavList[i]->getTreeBase().isInTheWay(plantPos)){
                treeInformation = behavList[i];
            }
        }
    }
}
void TreeGui::addTree(int pos){
    //determine which tree player choose
    int choice = gChosPlant->getSelectedIndex();
    bool isWater = waterBox->isChecked();
    TreeBase* tree;
    int i = 0;
    //determine which slot tree should insert
    while(i < behavList.size()
          && behavList[i]->getTreeBase().getPlantPos()<pos){
        i+=1;
    }
    if(choice == 0) tree = new Apple(pos,isWater,gridTable);
    else if(choice == 1) tree = new Lemon(pos,isWater,gridTable);
    else tree = new Orange(pos,isWater,gridTable);
    //if tree is plant at the last spot
    if(i == behavList.size()) behavList.push_back(new Sapling(*tree));
    else behavList.insert(behavList.begin()+i,new Sapling(*tree));
    draw();
}
void TreeGui::clear(){
    for(int i = 0; i < behavList.size(); i++){
            delete &behavList[i]->getTreeBase();
            delete behavList[i];
    }
    behavList.clear();
    createDataGrid(true);
    months = 0;
    //set to nullptr to avoid pointer error
    treeInformation = nullptr;
    //clear out the gui
     gcan->clear();
     gcan->repaint();
}
void TreeGui::setAuto(){
    if(!isRunning){
        autoButton->setText("Stop");
        autoButton->setBackground("red");
        isRunning = true;
    }
    else{
        autoButton->setText("Run");
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
    gcan->clear();
    showInformation();
    updateTree();
    draw();
    }
}
void TreeGui::showInformation()const{
    lable->setText("Month :"+to_string(months));
    if(treeInformation!=nullptr){
        string isWater = treeInformation->getTreeBase().isWatered() ? "True" : "False";
        gtextArea->setText("Tree: "+treeInformation->getTreeBase().getType()+'\t'
               +"Tree state: "+treeInformation->getType()+'\t'
               +"Age(Month): "+to_string(treeInformation->getTreeBase().getAge())+'\n'
               +"Height of the tree: "+to_string(treeInformation->getTreeBase().getHeight())+'\t'
               +"Width of the tree: "+to_string(treeInformation->getTreeBase().getWidth())+'\t'
                           +"Tree is water: "+isWater);
    }
}
void TreeGui::updateTree(){
    months+=1;
        for(int i = 0; i < behavList.size(); i++) {
            behavList[i]->update();
            //check if tree is old enough to switch state
            if(behavList[i]->isOld()) {
                TreeBaseBehavior* copy = behavList[i]->switchState();
                //check if the pointer tree for showing information is ==
                //pointer tree begin to switch state
                //avoiding the pointer to tree is got deleted
                if(treeInformation == behavList[i]) treeInformation = copy;
                delete behavList[i];
                behavList[i] = copy;
            }
        }
        //check if any tree collided
        //need to check if size is not 0 else cause a crash
        for(int i = 0;behavList.size() != 0 && i < behavList.size()-1; i++) {
            if(behavList[i]->getTreeBase().isInTheWay(behavList[i+1]->getTreeBase())){
                int height1 = behavList[i]->getTreeBase().getHeight();
                int width1 = behavList[i]->getTreeBase().getWidth();
                int height2 = behavList[i+1]->getTreeBase().getHeight();
                int width2 = behavList[i+1]->getTreeBase().getWidth();
                //which tree have larger area survive
                if(height1*width1>height2*width2){
                     behavList[i+1]->die();
                }
                else if(height1*width1<height2*width2){
                    behavList[i]->die();
                }
                //if equal then if 50:50
                else{
                    int choice = rand()%2;
                    behavList[i+choice]->die();
                }
            }
        }
        //delete any tree that is die
        for(int i = 0; i < behavList.size(); i++){
            if(behavList[i]->getTreeBase().getDead()){
                if(treeInformation == behavList[i]) treeInformation = nullptr;
                delete &behavList[i]->getTreeBase();
                delete behavList[i];
                behavList.erase(behavList.begin()+i);
                i--;
            }
        }
}
void TreeGui::drawOval(int x, int y, int height, int width, string color){
    gcan->setColor(color);
    gcan->setFillColor(color);
    GOval oval(0,0,width,height);
    oval.setCenterX(x);
    oval.setCenterY(y);
    gcan->fillOval(oval.getBounds());
}
void TreeGui::draw(){
    gcan->setColor("brown");
    gcan->setFillColor("brown");
    //drawing the body of the tree
    for(int j = 0; j < gridTable->size(); j++) {
        for(int k = 0; k < (*gridTable)[0].size(); k++) {
            if((*gridTable)[j][k]) {
                gcan->fillRect(GRID_SIZE * k, GRID_SIZE * j, GRID_SIZE, GRID_SIZE);
            }
        }
    }
    //draw the leaf of the tree (ellipse shape)
    for(int i = 0; i < behavList.size(); i++) {
        int wid = behavList[i]->getTreeBase().getWidth()*GRID_SIZE*3;
        int hei = behavList[i]->getTreeBase().getHeight()*GRID_SIZE;
        int x = ((behavList[i]->getTreeBase().getPlantPos())*GRID_SIZE)+GRID_SIZE/2;
        int y = (behavList[i]->getTreeBase().getHeightData() -
                 behavList[i]->getTreeBase().getHeight())*GRID_SIZE;
        drawOval(x, y, hei,wid,"green");
        //drawing the fruit of the tree
        vector<int>* fruitLocate = &behavList[i]->getTreeBase().setFruitLocate();
        string fruitColor = behavList[i]->getTreeBase().getFruitColor();
        if(fruitLocate->size() != 0){
            for(int i = 0;i<fruitLocate->size();i+=2){
                drawOval((*fruitLocate)[i]*GRID_SIZE, (*fruitLocate)[i+1]*GRID_SIZE
                        , GRID_SIZE*2,GRID_SIZE*2,fruitColor);
            }
        }
    }
    gcan->repaint();
}
