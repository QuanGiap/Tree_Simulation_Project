#ifndef ORANGE_H
#define ORANGE_H
#include "TreeBase.h"
class Orange:public TreeBase{
public:
    Orange();
    virtual int getGrownSpeed() const override;
    virtual string getFruitColor() const override;
    virtual string getType() const override;

};

#endif // ORANGE_H
