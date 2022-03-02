#ifndef APPLE_H
#define APPLE_H
#include"TreeBase.h"
class Apple:public TreeBase{
public:
    Apple(int pos, vector<vector<bool>>*& table);
    virtual int getGrownSpeed()const override;
    virtual string getFruitColor() const override;
    virtual string getType() const override;
};

#endif // APPLE_H
