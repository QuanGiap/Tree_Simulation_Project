#include "Lemon.h"

Lemon::Lemon(int height,int width){
    createData(height,width);
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
