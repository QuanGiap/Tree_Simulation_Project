// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Adult.h"
#include "Old.h"
Adult::Adult(TreeBase& tree):TreeBaseBehavior(tree){
    setRatio(2);
}
void Adult::giveFruit(){

}
bool Adult::isOld(){
    return getTreeBase().getAge()>10;
}
TreeBaseBehavior* Adult::switchState(){
    return new Old(getTreeBase());
}

string Adult::getType() const{
    return "Adult";
}
