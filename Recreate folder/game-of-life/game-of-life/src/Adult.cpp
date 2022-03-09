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
    int treeArea = getTreeBase().getWidth() * getTreeBase().getHeight();
    int areaMulti = treeArea % 10;
    int waterMulti = 1;
    int possWidth = getTreeBase().getWidth() * 3;
    int a = possWidth;
    int b = getTreeBase().getHeight();
    int h = getTreeBase().getPlantPos();
    int k = getTreeBase().getHeight();
    if(getTreeBase().isWatered()) {
        waterMulti = 2;
    }
    for(int i = 0; i < waterMulti * areaMulti; i++) {
        int x = h - (a / 2) + (rand() % possWidth);
        int possHeight = sqrt((b * b) * ((a * a) - (h * h) + (2 * h * x) - (x * x) / (a * a))) * 2;
        int y = k - (b / 2) + (rand() % possHeight);
        getTreeBase().setFruitLocate().push_back(x);
        getTreeBase().setFruitLocate().push_back(y);
    }
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
