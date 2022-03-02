#include "Orange.h"

Orange::Orange(int i, int j, vector<vector<bool>>*& table):TreeBase(i,j,table){
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
