#include "Orange.h"

Orange::Orange(int pos, vector<vector<bool>>*& table):TreeBase(pos,table){
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
