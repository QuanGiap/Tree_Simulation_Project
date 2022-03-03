// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
// 
// The purpose of this program is to create a class called Old that gives the
// editor a constructor and functions inherited from TreeBaseBehavior that have
// been overriden to better simulate an old tree's behavior.

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
