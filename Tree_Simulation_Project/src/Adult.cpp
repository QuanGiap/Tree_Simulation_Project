// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Adult.h"
#include "Old.h"
#include <math.h>
Adult::Adult(TreeBase& tree):TreeBaseBehavior(tree){
    setRatio(3);
}
void Adult::giveFruit(){
    clearFruitLocation();
    int treeArea = getTreeBase().getWidth() * getTreeBase().getHeight();
    int amount = treeArea / 10;
    int realAmount = getTreeBase().isWatered()? amount : amount/2;
    int leafWidth = getTreeBase().getWidth() * 2.5;
    int a = leafWidth/2;
    int b = getTreeBase().getHeight()/4;
    for(int i = 0; i < realAmount; i++) {
        int x = rand() % (leafWidth) - a;
        int randomRangeY = b * sqrt(1+((x*x)/(a*a)));
        int y = rand() % (randomRangeY*2) - randomRangeY;
        x = x + getTreeBase().getPlantPos();
        y = y + (getTreeBase().getHeightData()-getTreeBase().getHeight());
        if(x>0 && y<getTreeBase().getHeightData()){
            getTreeBase().setFruitLocate().push_back(x);
            getTreeBase().setFruitLocate().push_back(y);
        }
    }
}
void Adult::grow(bool isWidth){
    giveFruit();
    TreeBaseBehavior::grow(isWidth);
}
void Adult::clearFruitLocation(){
    getTreeBase().setFruitLocate().clear();
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
