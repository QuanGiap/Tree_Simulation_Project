#include "TreeBaseBehavior.h"
TreeBaseBehavior::TreeBaseBehavior(TreeBase& tree){
    this->tree = &tree;
}
bool TreeBaseBehavior::isWood(int i, int j){
    return tree->isWood(i,j);
}
bool TreeBaseBehavior::isOld() const{
    return tree->getAge() > 0;
}

void TreeBaseBehavior::update(){
    grow(false);
}

void TreeBaseBehavior::growWidth(){
    int midPos = tree->getWidthData()/2;
    int posSet = midPos-1-(tree->getWidth()/2);
    //add wood on the left side tree
    for(int i = 0;i < tree->getHeight() - tree->getWidth();i++){
        tree->setTrue(i,posSet);
    }
    //add wood in the right side tree
    posSet = midPos+1+(tree->getWidth()/2);
    for(int i = 0;i < tree->getHeight()-tree->getWidth();i++){
        tree->setTrue(i,posSet);
    }
    tree->getWidth()+=2;
}
void TreeBaseBehavior::grow(bool isGrowW){
    if(isGrowW) growWidth();
    int setPosTime = tree->getWidth()/2+1;
    if(isGrowW) setPosTime -= 2;
    int midPos = tree->getWidthData()/2;
    for(int i = 0;i<setPosTime;i++){
        //add wood on the left side tree
        tree->setTrue(tree->getHeight()+1-i,midPos-i);
        //add wood on the right side tree
        tree->setTrue(tree->getHeight()+1-i,midPos+i);
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
