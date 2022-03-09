// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Apple.h"
Apple::Apple(int pos,bool isWater, vector<vector<bool>>*& table):TreeBase(pos,isWater,table){}

int Apple::getGrownSpeed() const{
    return 8;
}

string Apple::getFruitColor() const{
    return "red";
}

string Apple::getType () const {
    return "Apple";
}
