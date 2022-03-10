// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Old.h"

Old::Old(TreeBase& tree):Adult(tree){
    setRatio(2);
}
bool Old::isOld()const{
    return getTreeBase().getAge()>1000;
}
void Old::grow(bool isWidth){
    Adult::grow(isWidth);
}
string Old::getType() const{
    return "Old";
}
TreeBaseBehavior* Old::switchState()const{
    getTreeBase().setDead(true);
    return new TreeBaseBehavior(getTreeBase());
}
