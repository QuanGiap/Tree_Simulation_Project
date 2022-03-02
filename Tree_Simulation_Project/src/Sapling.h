#ifndef SAPLING_H
#define SAPLING_H
#include "TreeBaseBehavior.h"
class Sapling:public TreeBaseBehavior{
public:
    Sapling(TreeBase& tree);
    virtual void update() override;
    virtual TreeBaseBehavior* switchState() override;
    virtual bool isOld() override;
    virtual string getType() const override;
private:
    int count;
};

#endif // SAPLING_H
