// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22
// 
// This program's behavior is to create a class called TreeBase that gives the
// editor a constructor and member functions to keep track of the position,
// width, height, age, leaf color and fruit color of the new tree, as well as
// if it is being watered or not.

#ifndef TREE_BASE_H
#define TREE_BASE_H
#include <string>
#include <vector>
using namespace std;
class TreeBase{
public:
  // The TreeBase constructor accepts an integer of the tree's horizontal
  // position, a boolean of if it's being watered, and a reference to the 2d 
  // vector it will grow in.
  TreeBase(int pos,bool isWater, vector<vector<bool>>*& table);
  // The setAge member function returns the address of the TreeBase's private
  // month variable so it can be altered outside of the class.
  int& setAge();
  // The getWidthData member function returns the length of first index of vector data
  int getWidthData() const;
  // The getHeightData member function returns the the length of vector data
  int getHeightData() const;
  // The getPlantPos member function returns an integer of the tree's
  // horizontal position at it's center of the tree.
  int getPlantPos()const;
  // The setHeight member function returns the address of the TreeBase's private
  // height variable so it can be altered outside of the class.
  int& setHeight();
  // The setWidth member function returns the address of the TreeBase's private
  // Width variable so it can be altered outside of the class.
  int& setWidth();
  //Check if this tree is in the way of other tree
  bool isInTheWay(TreeBase& other);
  bool isInTheWay(int plantLocation);
  // The isWood member function accepts two integers representing the row and
  // column of the table and returns whether or not there is a peice of the
  // tree at that point.
  bool isWood(int col,int row)const;
  //Return bool check if the tree is dead, can modifed;
  bool& setDead();
  //return vector location of the fruit, also can modified;
  vector<int>& setFruitLocate();
  // The setTrue member function accepts two integers representing the row and
  // column of the table and sets that point equal to true, displaying a peice
  // of tree at that point.
  void setTrue(int i,int j);
  // The getLeafColor member function returns the private string leafColor that
  // represents the color of leaves the TreeBase has.
  string getLeafColor() const;
  // The setLeafColor member function accepts a reference string of the desired color and
  // sets the private string leafColor to the given string.
  void setLeafColor(const string& color);
  // The getGrownSpeed member function returns the integer representing how 
  // quickly the tree will grow each tick.
  virtual int getGrownSpeed() const;
  // The getFruitColor member function returns the string representation of the
  // color of the fruit the tree bears, which will be null in this case because
  // the tree has not been set yet.
  virtual string getFruitColor() const;
  // The getType member function returns the string representation of the stage
  // the tree is currently in, which will be base in this case because the tree
  // has not been set yet.
  virtual string getType() const;
private:
  string leafColor;
  bool isWater;
  bool isDead;
  vector<vector<bool>>* data;
  vector<int> fruitLocation;
  int plantPosition;
  int width;
  int height;
  int month;
};
// The overloaded << operator accepts a reference to a TreeBase and any
// previous ostream and returns that ostream plus the ASCII representation of
// the TreeBase.
ostream& operator<<(ostream& out, TreeBase& tree);
#endif
