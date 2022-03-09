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
#include <time.h>
using namespace std;
class TreeBase{
public:
  //The destructor of TreeBase(empty function)
  virtual ~TreeBase();
  // The TreeBase constructor accepts an integer of the tree's horizontal
  // position, a boolean of if it's being watered, and a reference to the 2d 
  // vector it will grow in.
  TreeBase(int pos,bool isWater, vector<vector<bool>>*& table);
  // The getAge member function returns the age of treeBase;
  int getAge();
  // setting the age from tree base
  void setAge(int age);
  // The getWidthData member function returns the length of first index of vector data
  int getWidthData() const;
  // The getHeightData member function returns the the length of vector data
  int getHeightData() const;
  // The getPlantPos member function returns an integer of the tree's
  // horizontal position at it's center of the tree.
  int getPlantPos()const;
  // The getHeight member function returns the height of tree base
  int getHeight();
  // The setHeight member function setting the height of tree base
  void setHeight(int height);
  // The getWidth member function returns the width of tree base
  int getWidth();
  // The setWidth member function setting the width of tree base
  void setWidth(int width);
  //Check if this tree is in the way of other tree. From left to right;
  bool isInTheWay(TreeBase& other);
  //Check if the position going to plant is in the way of this tree
  bool isInTheWay(int plantLocation);
  // The isWood member function accepts two integers representing the row and
  // column of the table and returns whether or not there is a peice of the
  // tree at that point.
  bool isWood(int col,int row)const;
  //Return bool check if the tree is dead;
  bool getDead();
  //Setting the tree bool base on param given
  void setDead(bool isDead);
  //check if the amount reach more than 100. Every time this function get called
  //the amount is plus the grown speed. If it is not watered, grow speed is reduce by half
  bool canGrow();
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
  virtual string getType() const = 0;
private:
  string leafColor;
  bool isWater;
  bool isDead;
  //the amount is enough to grow. Speed is based on grown speed sum
  int AmountToGrown;
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
