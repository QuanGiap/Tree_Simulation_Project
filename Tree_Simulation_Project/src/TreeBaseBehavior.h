// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
// 
// This program's behavior is to create a class called TreeBaseBehavior that
// gives the editor a constructor and member functions that control the growing
// behavior of the TreeBase.

#ifndef TREE_BASE_BEHAVIOR_H
#define TREE_BASE_BEHAVIOR_H
#include "TreeBase.h"
class TreeBaseBehavior{
public:
    // The destructor of TreeBaseBehavior(empty function)
    virtual ~TreeBaseBehavior();
    // The TreeBaseBehavior constructor accepts a reference to a TreeBase and
    // sets the private TreeBase member variable equal to the passed TreeBase.
    TreeBaseBehavior(TreeBase& tree);
    // The getTreeBase member variable returns the address of the private
    // member variable tree so it can be altered outside of the class.
    TreeBase& getTreeBase();
    // The die member function stops the growth of the tree.
    void die();
    //setting ratio for the tree. Count
    void setRatio(int ratio);
    // The grow member function accepts a bool value representing whether or
    // not the tree is meant to grow and will add one to the tree's height if
    // the value is false and one to the width if it's true.
    void grow(bool isGrowW);
    // The isWood member function accepts two integers representing the row and
    // column of the table and returns whether or not there is a peice of the
    // tree at that point. 
    bool isWood(int i,int j);
    // The switchState member function returns a new TreeBaseBehavior as a 
    // pointer with the private member variable tree passed to the constructor.
    virtual TreeBaseBehavior* switchState();
    // The update member function calls the grow function with a 50% chance to
    // pass true and grow the tree's width as well as height.
    // This function will be overrided by other class
    virtual void update();
    // The isOld member function returns true if the tree's age has exceeded
    // the set limit for each stage of tree, which in this case would always
    // return false because the tree's stage starts at sapling.
    virtual bool isOld();
    // The getType member function returns a string representing the stage of
    // the tree. In this case it returns "Base behavior."
    virtual string getType() const;
private:
    // The private growWidth member function adds wood to each side of the 
    // current tree all the way up to one less of the previous layer.
    void growWidth();
    TreeBase* tree;
    int count;
    int ratio;
};
#endif
