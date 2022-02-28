#ifndef OLD_H
#define OLD_H
#include "TreeBaseBehavior.h"

class Old:public TreeBaseBehavior{
public:
    Old(TreeBase& tree);
    virtual string getType() const override;
};

#endif // OLD_H
