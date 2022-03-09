// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Adult.h"
#include "Old.h"
Adult::Adult(TreeBase& tree):TreeBaseBehavior(tree){
    this->tree = &tree;
    setRatio(3);
}
void Adult::giveFruit(){
    srand(time(NULL));
    vector<int> position;
    int possWidth = (*tree).getWidth() * 3;
    int possHeight = (*tree).getHeight();
    int x = (*tree).getPlantPos() - (*tree).getWidthData() + (rand() % possWidth);
    int y = (*tree).getHeightData() - (possHeight / 2) + (rand() % possHeight);
    position.resize(x);
    position[x] = y;
    (*tree).setFruitLocate() = position;
}
bool Adult::isOld(){
    return getTreeBase().getAge()>250;
}
TreeBaseBehavior* Adult::switchState(){
    return new Old(getTreeBase());
}

string Adult::getType() const{
    return "Adult";
}
