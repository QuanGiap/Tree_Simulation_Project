// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "TreeGui.h"

TreeGui::TreeGui(int height, int width, vector<TreeBaseBehavior*>*& behaviorList, vector<vector<bool>>*& table) {
    this->table = table;
    behavList = behaviorList;
    gwin = new GWindow(width / 2, height / 2);
    gwin->setTitle("Tree Simulation");
    gwin->setLocation(300, 150);
    gwin->setBackground("White");
    gwin->setTimerListener(500, [this]{updateAll();});
}

void TreeGui::updateAll() {
    gwin->clear();
    for(int i = 0; i < (*behavList).size(); i++) {
        (*behavList)[i]->update();
        for(int j = 0; j < (*table).size(); j++) {
            for(int k = 0; k < (*table).size(); k++) {
                if((*table)[j][k]) {
                    gwin->setColor("brown");
                    gwin->setFillColor("brown");
                    gwin->drawRect(10 * k, 10 * j, 10, 10);
                    gwin->fillRect(10 * k, 10 * j, 10, 10);
                }
            }
        }
    }
}
