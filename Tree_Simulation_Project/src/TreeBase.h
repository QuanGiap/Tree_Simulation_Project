#ifndef TREE_BASE_H
#define TREE_BASE_H
#include <string>
using namespace std;
class TreeBase{
public:
  TreeBase();
  int getAge() const;
  string getLeafColor() const;
  void setLeafColor(string color);
  virtual int getGrownSpeed() const;
  virtual string getFruitColor() const;
  virtual string getType() const = 0;
private:
  string leafColor;
  int year;
};
#endif
