// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
// 
// The purpose of this program is to create a class called Adult that gives the
// editor a constructor and functions inherited from TreeBaseBehavior that have
// been overriden to better simulate an adult tree's behavior.
// Grow in this Behaviour is 2 height : 1 width

#ifndef ADULT_H
#define ADULT_H
#include "TreeBaseBehavior.h"
class Adult : public TreeBaseBehavior{
public:
    Adult(TreeBase& tree);
    //update giving fruit position in vector position form from TreeBase datab (not write yet)
    virtual void giveFruit();
    //Return new TreeBaseBehavior* of "Old" state
    virtual TreeBaseBehavior* switchState()override;
    //check if the age reach requirement to switch state
    virtual bool isOld()override;
    //Return string Adult
    virtual string getType() const override;
private:
    TreeBase* tree;
};

#endif // ADULT_H
