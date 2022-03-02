#include "Lemon.h"

Lemon::Lemon(int i, int j, vector<vector<bool>>*& table):TreeBase(i,j,table){
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
