#include "TreeBaseBehavior.h"
TreeBaseBehavior::TreeBaseBehavior(TreeBase& tree){
    this->tree = &tree;
}
bool TreeBaseBehavior::isWood(int i, int j){
    return tree->isWood(i,j);
}
bool TreeBaseBehavior::isOld(){
    return tree->getAge() > 0;
}

void TreeBaseBehavior::update(){
    grow(rand()%2==0);
}
TreeBaseBehavior* TreeBaseBehavior::switchState(){
    return new TreeBaseBehavior(*tree);
}
void TreeBaseBehavior::growWidth(){
    int offSet = 1+(tree->getWidth()/2);
    int startSet = tree->getHeight() - tree->getWidth()+(tree->getWidth()/2);
    for(int i = startSet;i >=0;i--){
        //add wood on the left side tree
        tree->setTrue(tree->getHeightData()-i-1,tree->getPlantPos()-offSet);
        //add wood in the right side tree
        tree->setTrue(tree->getHeightData()-i-1,tree->getPlantPos()+offSet);
    }
    tree->getWidth()+=2;
}
void TreeBaseBehavior::grow(bool isGrowW){
    if(isGrowW) growWidth();
    int setPosTime = tree->getWidth()/2+1;
    if(isGrowW) setPosTime -= 1;
    int startSet = tree->getHeightData() - tree->getHeight() - 1;
    for(int i = 0;i<setPosTime;i++){
        //add wood on the left side tree
        tree->setTrue(startSet+i,tree->getPlantPos()-i);
        //add wood on the right side tree
        tree->setTrue(startSet+i,tree->getPlantPos()+i);
    }
    tree->getHeight()+=1;
    tree->getAge()+=1;
}
TreeBase& TreeBaseBehavior::getTreeBase(){
    return *tree;
}

string TreeBaseBehavior::getType() const{
    return "Base behavior";
}
