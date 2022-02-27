#include "TreeBaseBehavior.h"
TreeBaseBehavior::TreeBaseBehavior(){
}

void TreeBaseBehavior::setTreeBase(TreeBase& tree){
    this->tree = &tree;
}

bool TreeBaseBehavior::IsOld() const{
    return tree->getAge() > 0;
}
TreeBase& TreeBaseBehavior::getTreeBase(){
    return *tree;
}
