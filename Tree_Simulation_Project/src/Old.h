// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
// 
// The purpose of this program is to create a class called Old that gives the
// editor a constructor and functions inherited from TreeBaseBehavior that have
// been overriden to better simulate an old tree's behavior.
// Grow in this Behaviour is always width;
#ifndef OLD_H
#define OLD_H
#include "Adult.h"

class Old:public Adult{
public:
    // The Old constructor accepts a reference to a TreeBase and
    // setting the ratio to 2 height : 1 width
    Old(TreeBase& tree);
    //Return "Old"
    virtual string getType() const override;
    //Always return true if the tree is 1000 months old
    virtual bool isOld() const override;
    //set the tree death is true then return TreeBaseBehavior
    virtual TreeBaseBehavior* switchState() const override;
};

#endif // OLD_H
