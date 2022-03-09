// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Orange.h"

Orange::Orange(int pos,bool isWater, vector<vector<bool>>*& table):TreeBase(pos, isWater,table){
}

int Orange::getGrownSpeed() const{
    return 7;
}

string Orange::getFruitColor() const{
    return "orange";
}

string Orange::getType() const{
    return "Orange";
}
