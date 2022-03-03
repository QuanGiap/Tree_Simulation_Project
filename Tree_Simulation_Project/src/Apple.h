// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
// 
// The purpose of this program is to create a class called Apple that 
// overrides TreeBase functions to match the discription of an apple tree.

#ifndef APPLE_H
#define APPLE_H
#include"TreeBase.h"
class Apple:public TreeBase{
public:
    Apple(int pos,bool isWater, vector<vector<bool>>*& table);
    virtual int getGrownSpeed()const override;
    virtual string getFruitColor() const override;
    virtual string getType() const override;
};

#endif // APPLE_H
