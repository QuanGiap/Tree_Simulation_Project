#include "Orange.h"

Orange::Orange(int height,int width){
    createData(height,width);
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
