#include "Lemon.h"

Lemon::Lemon(int pos,bool isWater, vector<vector<bool>>*& table):TreeBase(pos,isWater,table){
}

int Lemon::getGrownSpeed() const{
    return 10;
}

string Lemon::getFruitColor() const{
    return "yellow";
}

string Lemon::getType() const{
    return "Lemon";
}
