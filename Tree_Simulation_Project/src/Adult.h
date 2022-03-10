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
    // The Adult constructor accepts a reference to a TreeBase and
    //setting the ratio to 3 height : 1 width
    Adult(TreeBase& tree);
    //add giving fruit location every time the tree grow
    virtual void grow(bool isWidth) override;
    //Return new TreeBaseBehavior* of "Old" state
    virtual TreeBaseBehavior* switchState() const override;
    //check if the age reach 450
    virtual bool isOld() const override;
    //Return string Adult
    virtual string getType() const override;
private:
    //clear out the fruit location vector;
    void clearFruitLocation();
    //update giving fruit position in vector position from TreeBase data
    //every even index is x, odd index is y
    //doing calculating making the point is inside the leaf area (ellipse);
    //giving out random x random range base on the width of the tree/2;
    //then calculate the random range need to be for the y
    virtual void giveFruit();
};

#endif // ADULT_H
