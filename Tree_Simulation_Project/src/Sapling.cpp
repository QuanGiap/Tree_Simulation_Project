// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Sapling.h"
#include "Adult.h"

Sapling::Sapling(TreeBase& tree):TreeBaseBehavior(tree){
    setRatio(6);
}
bool Sapling::isOld(){
    return getTreeBase().getAge() > 5;
}
string Sapling::getType() const{
    return "Sapling";
}
TreeBaseBehavior* Sapling::switchState(){
    return new Adult(getTreeBase());
}
