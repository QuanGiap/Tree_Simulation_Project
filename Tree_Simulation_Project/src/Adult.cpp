// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Adult.h"
#include "Old.h"
Adult::Adult(TreeBase& tree):TreeBaseBehavior(tree){
    setRatio(3);
}
void Adult::giveFruit(){
    srand(time(NULL));
    vector<int> position;
    int possWidth = getTreeBase().getWidth() * 3;
    int possHeight = getTreeBase().getHeight();
    int x = getTreeBase().getPlantPos() - getTreeBase().getWidthData() + (rand() % possWidth);
    int y = getTreeBase().getHeightData() - (possHeight / 2) + (rand() % possHeight);
    getTreeBase().setFruitLocate().push_back(x);
    getTreeBase().setFruitLocate().push_back(y);
}
bool Adult::isOld()const{
    return getTreeBase().getAge()>650;
}
TreeBaseBehavior* Adult::switchState()const{
    return new Old(getTreeBase());
}

string Adult::getType() const{
    return "Adult";
}
