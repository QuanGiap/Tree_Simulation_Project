#include "Adult.h"
#include "Old.h"
Adult::Adult(TreeBase& tree):TreeBaseBehavior(tree){
    count = 0;
}
void Adult::giveFruit(){

}
void Adult::update(){
    count = (count+1)%2;
    grow(count==0);
}
bool Adult::isOld(){
    return getTreeBase().setAge()>10;
}
TreeBaseBehavior* Adult::switchState(){
    return new Old(getTreeBase());
}

string Adult::getType() const{
    return "Adult";
}
