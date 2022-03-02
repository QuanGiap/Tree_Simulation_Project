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
