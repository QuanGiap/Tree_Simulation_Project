#include "Apple.h"
Apple::Apple(int pos, vector<vector<bool>>*& table):TreeBase(pos,table){}

int Apple::getGrownSpeed() const{
    return 10;
}

string Apple::getFruitColor() const{
    return "red";
}

string Apple::getType () const {
    return "Apple";
}
