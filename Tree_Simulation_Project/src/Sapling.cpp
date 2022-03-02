#include "Sapling.h"
#include "Adult.h"

Sapling::Sapling(TreeBase& tree):TreeBaseBehavior(tree){
    count=0;
}
void Sapling::update(){
    count=(count+1)%5;
    grow(count==0);
}
bool Sapling::isOld(){
    return getTreeBase().setAge() > 5;
}
string Sapling::getType() const{
    return "Sapling";
}
TreeBaseBehavior* Sapling::switchState(){
    return new Adult(getTreeBase());
}
