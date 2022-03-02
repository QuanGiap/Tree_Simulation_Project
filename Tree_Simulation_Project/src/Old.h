#ifndef OLD_H
#define OLD_H
#include "TreeBaseBehavior.h"

class Old:public TreeBaseBehavior{
public:
    Old(TreeBase& tree);
    virtual void update() override;
    virtual string getType() const override;
    virtual bool isOld() override;
};

#endif // OLD_H
