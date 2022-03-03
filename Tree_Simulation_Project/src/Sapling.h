// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
//
// The purpose of this program is to create a class called Sapling that gives
// the editor a constructor and functions inherited from TreeBaseBehavior that
// have been overriden to better simulate a Sapling's behavior.

#ifndef SAPLING_H
#define SAPLING_H
#include "TreeBaseBehavior.h"
class Sapling:public TreeBaseBehavior{
public:
    // The Sapling constructor accepts a reference to a TreeBase and 
    // initializes the private count variable for the new tree at zero.
    Sapling(TreeBase& tree);
    // The update member function calls the grow member function with true once
    // every 5 counts and false the rest of the time, so the tree will grow 
    // width-wise once every 5 turns, growing height-wise the rest of those 5.
    virtual void update() override;
    // The switchState member function returns a new Adult TreeBaseBehavior 
    // pointer to take the place of this Sapling TreeBaseBehavior.
    virtual TreeBaseBehavior* switchState() override;
    // The isOld member function returns true if the age of the tree is over 5
    // ticks. Otherwise returns false.
    virtual bool isOld() override;
    // The getType member function returns a string representing the stage of
    // the tree is at so it may be identified easily. Returns "Sapling."
    virtual string getType() const override;
private:
    int count;
};

#endif // SAPLING_H
