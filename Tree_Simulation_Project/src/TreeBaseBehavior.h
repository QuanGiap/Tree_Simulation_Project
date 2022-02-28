#ifndef TREE_BASE_BEHAVIOR_H
#define TREE_BASE_BEHAVIOR_H
#include "TreeBase.h"
class TreeBaseBehavior{
public:
    TreeBaseBehavior(TreeBase& tree);
    TreeBase& getTreeBase();
    bool isWood(int i,int j);
    void grow(bool isGrowW);
    virtual TreeBaseBehavior* switchState();
    virtual void update();
    virtual bool isOld() const;
    virtual string getType() const;
private:
    void growWidth();
    TreeBase* tree;
};
#endif
