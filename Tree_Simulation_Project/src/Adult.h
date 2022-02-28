#ifndef ADULT_H
#define ADULT_H
#include "TreeBaseBehavior.h"
class Adult : public TreeBaseBehavior{
public:
    Adult(TreeBase& tree);
    virtual TreeBaseBehavior* switchState()override;
    virtual string getType() const override;
};

#endif // ADULT_H
