#include "Old.h"

Old::Old(TreeBase& tree):TreeBaseBehavior(tree){}
void Old::update(){
    grow(true);
}
bool Old::isOld(){
    return getTreeBase().setAge()>50;
}
string Old::getType() const{
    return "Old";
}
