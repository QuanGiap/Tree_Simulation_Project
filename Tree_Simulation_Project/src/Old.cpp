// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Old.h"

Old::Old(TreeBase& tree):TreeBaseBehavior(tree){}
bool Old::isOld(){
    return getTreeBase().getAge()>50;
}
string Old::getType() const{
    return "Old";
}
