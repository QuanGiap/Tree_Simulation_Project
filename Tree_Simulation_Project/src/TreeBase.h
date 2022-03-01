#ifndef TREE_BASE_H
#define TREE_BASE_H
#include <string>
#include <vector>
using namespace std;
class TreeBase{
public:
  TreeBase(int i, int j, vector<vector<bool>>& table);
  int& getAge();
  int getWidthData() const;
  int getHeightData() const;
  int& getHeight();
  int& getWidth();
  bool isWood(int col,int row)const;
  int getPlantPos()const;
  void setTrue(int i,int j);
  vector<int>& getLeafLocate();
  string getLeafColor() const;
  void setLeafColor(const string color);
  virtual int getGrownSpeed() const;
  virtual string getFruitColor() const;
  virtual string getType() const;
private:
  string leafColor;
  vector<int> leafPoint;
  vector<vector<bool>>* data;
  vector<int> fruitLocation;
  int plantPosition;
  int width;
  int height;
  int month;
};
ostream& operator<<(ostream& out, TreeBase& tree);
#endif
