#ifndef APPLE_H
#define APPLE_H
#include"TreeBase.h"
class Apple:public TreeBase{
public:
    Apple();
    virtual int getGrownSpeed()const override;
    virtual string getFruitColor() const override;
    virtual virtual string getType() const override;
};

#endif // APPLE_H
