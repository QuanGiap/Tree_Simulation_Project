// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Lemon.h"

Lemon::Lemon(int pos,bool isWater, vector<vector<bool>>*& table):TreeBase(pos,isWater,table){
}

int Lemon::getGrownSpeed() const{
    return 5;
}

string Lemon::getFruitColor() const{
    return "yellow";
}

string Lemon::getType() const{
    return "Lemon";
}
