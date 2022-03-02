#ifndef LEMON_H
#define LEMON_H
#include "TreeBase.h"
class Lemon:public TreeBase{
public:
    Lemon(int pos, vector<vector<bool>>*& table);
    virtual int getGrownSpeed() const override;
    virtual string getFruitColor() const override;
    virtual string getType() const override;
};

#endif // LEMON_H
