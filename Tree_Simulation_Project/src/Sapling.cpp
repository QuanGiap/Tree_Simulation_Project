#include "Sapling.h"
#include "Adult.h"

Sapling::Sapling(TreeBase& tree):TreeBaseBehavior(tree){}
TreeBaseBehavior* Sapling::switchState(){
    return new Adult(getTreeBase());
}
