#include "Sapling.h"
#include "Adult.h"

Sapling::Sapling(TreeBase& tree):TreeBaseBehavior(tree){}
bool Sapling::isOld(){
    return getTreeBase().getAge() > 5;
}
string Sapling::getType() const{
    return "Sapling";
}
TreeBaseBehavior* Sapling::switchState(){
    return new Adult(getTreeBase());
}
