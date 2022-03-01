#include "Apple.h"
Apple::Apple(int height,int width):TreeBase(height,width){}

int Apple::getGrownSpeed() const{
    return 10;
}

string Apple::getFruitColor() const{
    return "red";
}

string Apple::getType () const {
    return "Apple";
}
