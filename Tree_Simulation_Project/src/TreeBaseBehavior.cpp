// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "TreeBaseBehavior.h"
#include <iostream>
TreeBaseBehavior::~TreeBaseBehavior(){}
TreeBaseBehavior::TreeBaseBehavior(TreeBase& tree){
    this->tree = &tree;
    ratio = 2;
    count = 0;
}
bool TreeBaseBehavior::isWood(int i, int j){
    return tree->isWood(i,j);
}
bool TreeBaseBehavior::isOld(){
    return tree->getAge() > 0;
}
void TreeBaseBehavior::update(){
    //if(tree->canGrow()){
    count=(count+1)%ratio;
    grow(count==0);
    //}
    tree->setAge(tree->getAge()+1);
}
void TreeBaseBehavior::setRatio(int ratio){
    this->ratio = ratio;
}
TreeBaseBehavior* TreeBaseBehavior::switchState(){
    return new TreeBaseBehavior(*tree);
}
void TreeBaseBehavior::growWidth(){
    int offSet = 1+(tree->getWidth()/2);
    int startSet = tree->getHeight() - tree->getWidth()+(tree->getWidth()/2);
    for(int i = startSet;i >=0;i--){
        //add wood on the left side tree
        tree->setTrue(tree->getHeightData()-i-1,tree->getPlantPos()-offSet-1);
        //add wood in the right side tree
        tree->setTrue(tree->getHeightData()-i-1,tree->getPlantPos()+offSet-1);
    }
    tree->setWidth(tree->getWidth()+2);
}
void TreeBaseBehavior::die(){
    tree->setDead(true);
}
void TreeBaseBehavior::grow(bool isGrowW){
    if(isGrowW) growWidth();
    else{
        int setPosTime = tree->getWidth()/2+1;
        int startSet = tree->getHeightData() - tree->getHeight() - 1;
        for(int i = 0;i<setPosTime;i++){
            //add wood on the left side tree
            tree->setTrue(startSet+i,tree->getPlantPos()-i-1);
            //add wood on the right side tree
            tree->setTrue(startSet+i,tree->getPlantPos()+i-1);
        }
        tree->setHeight(tree->getHeight()+1);
    }
}
TreeBase& TreeBaseBehavior::getTreeBase(){
    return *tree;
}

string TreeBaseBehavior::getType() const{
    return "Base behavior";
}
