// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
//
// The purpose of this program is to create a class called Sapling that gives
// the editor a constructor and functions inherited from TreeBaseBehavior that
// have been overriden to better simulate a Sapling's behavior.
// Grow in this Behaviour is 5 height : 1 width

#ifndef SAPLING_H
#define SAPLING_H
#include "TreeBaseBehavior.h"
class Sapling:public TreeBaseBehavior{
public:
    // The Sapling constructor accepts a reference to a TreeBase and
    // setting the ratio to 6 height : 1 width
    Sapling(TreeBase& tree);
    // The switchState member function returns a new Adult TreeBaseBehavior 
    // pointer to take the place of this Sapling TreeBaseBehavior.
    virtual TreeBaseBehavior* switchState() const override;
    // The isOld member function returns true if the age of the tree is over 200
    // months old. Otherwise returns false.
    virtual bool isOld() const override;
    // The getType member function returns a string representing the stage of
    // the tree is at so it may be identified easily. Returns "Sapling."
    virtual string getType() const override;
};

#endif // SAPLING_H
