#include "Orange.h"

Orange::Orange(int pos,bool isWater, vector<vector<bool>>*& table):TreeBase(pos, isWater,table){
}

int Orange::getGrownSpeed() const{
    return 10;
}

string Orange::getFruitColor() const{
    return "orange";
}

string Orange::getType() const{
    return "Orange";
}
