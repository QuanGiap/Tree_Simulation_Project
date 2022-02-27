#include "TreeBaseBehavior.h"
TreeBaseBehavior::TreeBaseBehavior(){
}

void TreeBaseBehavior::setTreeBase(TreeBase& tree){
    this->tree = &tree;
}

bool TreeBaseBehavior::isOld() const{
    return tree->getAge() > 0;
}

TreeBase& TreeBaseBehavior::getTreeBase(){
    return *tree;
}

string TreeBaseBehavior::getType() const{
    return "Base behavior";
}
