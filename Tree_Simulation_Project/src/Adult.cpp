#include "Adult.h"
#include "Old.h"
Adult::Adult(TreeBase& tree):TreeBaseBehavior(tree){}

bool Adult::isOld(){
    return getTreeBase().getAge()>10;
}
TreeBaseBehavior* Adult::switchState(){
    return new Old(getTreeBase());
}

string Adult::getType() const{
    return "Adult";
}
