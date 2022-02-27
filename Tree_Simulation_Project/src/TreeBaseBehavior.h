#ifndef TREE_BASE_BEHAVIOR_H
#define TREE_BASE_BEHAVIOR_H
#include "TreeBase.h"
class TreeBaseBehavior{
public:
    TreeBaseBehavior();
    void setTreeBase(TreeBase& tree);
    virtual bool IsOld() const;
    TreeBase& getTreeBase();
    virtual void grow();
    virtual bool isOld() const;
    virtual string getType() const;

private:
    TreeBase* tree;
};
#endif
