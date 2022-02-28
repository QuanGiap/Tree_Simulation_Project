#include "Old.h"

Old::Old(TreeBase& tree):TreeBaseBehavior(tree){}
string Old::getType() const{
    return "Old";
}
