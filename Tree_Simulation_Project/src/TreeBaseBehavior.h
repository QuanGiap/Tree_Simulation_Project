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
    virtual bool isOld();
    virtual string getType() const;
    void die();
private:
    void growWidth();
    TreeBase* tree;
    vector<vector<bool>> *data = new vector<vector<bool>>;
};
#endif
