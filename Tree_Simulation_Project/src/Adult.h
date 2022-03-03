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
    virtual void update() override;
    virtual void giveFruit();
    virtual TreeBaseBehavior* switchState()override;
    virtual bool isOld()override;
    virtual string getType() const override;
private:
    int count;
};

#endif // ADULT_H
