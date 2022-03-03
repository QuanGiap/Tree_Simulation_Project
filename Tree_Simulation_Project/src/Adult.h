// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
// 
// The purpose of this program is to create a class called Adult that gives the
// editor a constructor and functions inherited from TreeBaseBehavior that have
// been overriden to better simulate an adult tree's behavior.

#ifndef ADULT_H
#define ADULT_H
#include "TreeBaseBehavior.h"
class Adult : public TreeBaseBehavior{
public:
    Adult(TreeBase& tree);
    //calling the grow function. Grow height 2 time and width 1 time in order
    virtual void update() override;
    //update giving fruit position in vector position form from TreeBase datab (not write yet)
    virtual void giveFruit();
    //Return new TreeBaseBehavior* of "Old" state
    virtual TreeBaseBehavior* switchState()override;
    //check if the age reach requirement to switch state
    virtual bool isOld()override;
    //Return string Adult
    virtual string getType() const override;
private:
    int count;
};

#endif // ADULT_H
