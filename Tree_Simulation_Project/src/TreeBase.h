#ifndef TREE_BASE_H
#define TREE_BASE_H
#include <string>
#include <vector>
using namespace std;
class TreeBase{
public:
  TreeBase(int rows, int col);
  int& getAge();
  int getWidthData() const;
  int getHeightData() const;
  int& getHeight();
  int& getWidth();
  bool isWood(int col,int row)const;
  void setTrue(int i,int j);
  vector<int>& getLeafLocate();
  string getLeafColor() const;
  void setLeafColor(string color);
  virtual int getGrownSpeed() const;
  virtual string getFruitColor() const;
  virtual string getType() const = 0;
private:
  string leafColor;
  vector<int> leafPoint;
  vector<vector<bool>> data;
  int width;
  int height;
  int month;
};
#endif
