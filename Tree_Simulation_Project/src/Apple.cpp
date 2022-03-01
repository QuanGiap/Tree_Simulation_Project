#include "Apple.h"
Apple::Apple(int i, int j, vector<vector<bool>>& table):TreeBase(i,j,table){}

int Apple::getGrownSpeed() const{
    return 10;
}

string Apple::getFruitColor() const{
    return "red";
}

string Apple::getType () const {
    return "Apple";
}
