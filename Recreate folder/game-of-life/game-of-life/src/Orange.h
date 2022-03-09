// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
//
// The purpose of this program is to create a class called Orange that 
// overrides TreeBase functions to match the discription of an orange tree.

#ifndef ORANGE_H
#define ORANGE_H
#include "TreeBase.h"
class Orange:public TreeBase{
public:
    // The Orange constructor
    Orange(int pos,bool isWater, vector<vector<bool>>*& table);
    // return the grown speed 5
    virtual int getGrownSpeed() const override;
    // The getFruitColor member function returns a string representing the
    // color of the fruit being grown. Returns "orange."
    virtual string getFruitColor() const override;
    // The getType member function returns a string representing the type of
    // fruit that the tree is growing. Returns "Orange."
    virtual string getType() const override;
};

#endif // ORANGE_H
