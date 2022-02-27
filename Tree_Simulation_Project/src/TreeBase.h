#ifndef TREE_BASE_H
#define TREE_BASE_H
#include <string>
#include <vector>
using namespace std;
class TreeBase{
public:
  TreeBase();
  void createData(int height, int width);
  int getAge() const;
  int getWidth() const;
  int getHeight() const;
  bool isWood(int col,int row)const;
  void setTrue(int i,int j);
  vector<int> getLeafLocate();
  void updateLeafLocate(int i, int j);
  string getLeafColor() const;
  void setLeafColor(string color);
  virtual int getGrownSpeed() const;
  virtual string getFruitColor() const;
  virtual string getType() const = 0;
private:
  string leafColor;
  vector<int> leafPoint;
  vector<vector<bool>> data;
  int year;
};
#endif
