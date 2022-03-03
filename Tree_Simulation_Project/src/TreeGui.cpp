// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "TreeGui.h"

TreeGui::TreeGui(int height, int width,vector<TreeBaseBehavior*>*& behaviorList,  vector<vector<bool>>*& table)
{
    this->table = table;
    behavList = behaviorList;
}
