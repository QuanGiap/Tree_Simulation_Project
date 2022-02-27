#include "TreeBase.h"
TreeBase::TreeBase(){
    leafColor = "green";
    year = 0;
}
int TreeBase::getAge() const{
    return year;
}
string TreeBase::getLeafColor() const{
    return leafColor;
}
void TreeBase::setLeafColor(string color){
    leafColor = color;
}
int TreeBase::getGrownSpeed() const{
    return 0;
}
string TreeBase::getFruitColor() const{
    return "null";
}
string TreeBase::getType() const{
    return "Base";
}
