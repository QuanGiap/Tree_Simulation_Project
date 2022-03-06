// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "TreeGui.h"
int const GRID_SIZE = 10;
TreeGui::TreeGui(int height, int width, vector<TreeBaseBehavior*>*& behaviorList, vector<vector<bool>>*& table) {
    this->table = table;
    behavList = behaviorList;
    gwin = new GWindow(GRID_SIZE*width, GRID_SIZE*height);
    gwin->setTitle("Tree Simulation");
    gwin->setBackground("White");
    gwin->setAutoRepaint(false);
    gwin->setTimerListener(1000, [this]{updateAll();});
}

void TreeGui::updateAll() {
    gwin->clear();
    gwin->toFront();
    for(int i = 0; i < (*behavList).size(); i++) {
        (*behavList)[i]->update();
    }
    gwin->setColor("brown");
    gwin->setFillColor("brown");
    for(int j = 0; j < (*table).size(); j++) {
        for(int k = 0; k < (*table)[0].size(); k++) {
            if((*table)[j][k]) {
                gwin->fillRect(GRID_SIZE * k, GRID_SIZE * j, GRID_SIZE, GRID_SIZE);
            }
        }
    }
    gwin->setColor("green");
    gwin->setFillColor("green");
    for(int i = 0; i < (*behavList).size(); i++) {
        int wid = (*behavList)[i]->getTreeBase().setWidth()*25;
        int hei = (*behavList)[i]->getTreeBase().setHeight()*10;
        int x = (((*behavList)[i]->getTreeBase().getPlantPos())*GRID_SIZE)-GRID_SIZE/2;
        int y = ((*behavList)[i]->getTreeBase().getHeightData() - (*behavList)[i]->getTreeBase().setHeight())*GRID_SIZE;
        GOval oval(0,0,wid,hei);
        oval.setCenterX(x);
        oval.setCenterY(y);
        gwin->fillOval(oval.getBounds());
    }
    gwin->repaint();
}
