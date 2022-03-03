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
    Lemon(int pos,bool isWater, vector<vector<bool>>*& table);
    virtual int getGrownSpeed() const override;
    virtual string getFruitColor() const override;
    virtual string getType() const override;
};

#endif // LEMON_H
