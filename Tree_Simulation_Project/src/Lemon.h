// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
// 
// The purpose of this program is to create a class called Lemon that 
// overrides TreeBase functions to match the discription of a lemon tree.

#ifndef LEMON_H
#define LEMON_H
#include "TreeBase.h"
class Lemon:public TreeBase{
public:
    // The Apple constructor accepts an integer of the tree's horizontal
    // position, a boolean of if it's being watered, and a reference to the 2d
    // vector it will grow in.
    Lemon(int pos,bool isWater, vector<vector<bool>>*& table);
    //return the grown speed 5
    virtual int getGrownSpeed() const override;
    // The getFruitColor member function returns a string representing the
    // color of the fruit being grown. Returns "yellow"
    virtual string getFruitColor() const override;
    //return string "Lemon"
    virtual string getType() const override;
};

#endif // LEMON_H
