#ifndef TREE_BASE_BEHAVIOR_H
#define TREE_BASE_BEHAVIOR_H
#include "TreeBase.h"
class TreeBaseBehavior{
public:
    TreeBaseBehavior();
    TreeBase& getTreeBase();
    void setTreeBase(TreeBase& tree);
    void growWidth();
    void growHeight();
    virtual bool isOld() const;
    virtual string getType() const = 0;
private:
    TreeBase* tree;
};
#endif
