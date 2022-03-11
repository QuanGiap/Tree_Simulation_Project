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
    int amount = treeArea / 30;
    int realAmount = getTreeBase().isWatered()? amount : amount/2;
    //let make the middle point of ellipse is (0,0) for easier calculation
    //the width diameter of ellispe is 3 time the width of tree but making
    //less to 2.5 time
    int leafWidth = getTreeBase().getWidth() * 2.5;
    //turn to radius width
    int a = leafWidth/2;
    //the height diameter of ellispe is equal to height of the tree but make less
    //to 0.5 time and turn to radius
    int b = getTreeBase().getHeight()/4;
    for(int i = 0; i < realAmount; i++) {
        //get random x
        int x = rand() % (leafWidth) - a;
        //get random y
        int randomRangeY = b * sqrt(1+((x*x)/(a*a)));
        int y = rand() % (randomRangeY*2) - randomRangeY;
        x = x + getTreeBase().getPlantPos();
        y = y + (getTreeBase().getHeightData()-getTreeBase().getHeight());
        //making sure x and y is still in range of the grid table
        if(x>0 && x<getTreeBase().getWidthData()
                && y<getTreeBase().getHeightData()){
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
