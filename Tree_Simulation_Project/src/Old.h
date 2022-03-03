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
    //calling the grow function. Grow width every time it call
    virtual void update() override;
    //Return "Old"
    virtual string getType() const override;
    //Check if tree is old enough to die
    virtual bool isOld() override;
};

#endif // OLD_H
