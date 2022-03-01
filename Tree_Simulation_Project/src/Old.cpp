#include "Old.h"

Old::Old(TreeBase& tree):TreeBaseBehavior(tree){}
bool Old::isOld(){
    return getTreeBase().getAge()>50;
}
string Old::getType() const{
    return "Old";
}
