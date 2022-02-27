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

}

void TreeBaseBehavior::growWidth(){

}
void TreeBaseBehavior::grow(bool isGrowW){

}
TreeBase& TreeBaseBehavior::getTreeBase(){
    return *tree;
}

string TreeBaseBehavior::getType() const{
    return "Base behavior";
}
