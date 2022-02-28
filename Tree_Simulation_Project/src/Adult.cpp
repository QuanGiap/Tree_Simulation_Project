#include "Adult.h"
#include "Old.h"
Adult::Adult(TreeBase& tree):TreeBaseBehavior(tree){}

TreeBaseBehavior* Adult::switchState(){
    return new Old(getTreeBase());
}

string Adult::getType() const{
    return "Adult";
}
