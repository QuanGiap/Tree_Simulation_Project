// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "TreeBase.h"
#include <iostream>
using namespace std;
TreeBase::TreeBase(int pos,bool isWater,vector<vector<bool>>*& table){
    leafColor = "green";
    month = 0;
    width = 1;
    height = 2;
    data = table;
    isDead = false;
    (*data)[getHeightData()-1][pos-1] = true;
    (*data)[getHeightData()-2][pos-1] = true;
    plantPosition = pos;
    this->isWater = isWater;
}
TreeBase::~TreeBase(){}
int TreeBase::getPlantPos() const{
    return plantPosition;
}
void TreeBase::setTrue(int i, int j){
    if(i>=0 && i<getHeightData() && j>=0 && j <getWidthData())
        (*data)[i][j] = true;
}
int TreeBase::getWidth()const{
    return width;
}
void TreeBase::setWidth(int width){
    this->width = width;
}
int TreeBase::getHeight()const{
    return height;
}
void TreeBase::setHeight(int height){
    this->height = height;
}
int TreeBase::getWidthData() const{
    return (*data)[0].size();
}
int TreeBase::getHeightData() const{
    return (*data).size();
}
vector<int>& TreeBase::setFruitLocate(){
    return fruitLocation;
}
bool TreeBase::isWood(int col, int row)const{
    if(row<0||col<0||row>=getWidthData()||col>=getHeightData()) return false;
    return (*data)[col][row];
}
bool TreeBase::isInTheWay(TreeBase &other)const{
    return (plantPosition+(width/2)) >= (other.getPlantPos()-other.getWidth()/2);
}
bool TreeBase::isInTheWay(int plantLocation)const{
    int areaRight = plantPosition + width/2;
    int areaLeft = plantPosition - width/2;
    return (areaLeft<=plantLocation&&plantLocation<=areaRight);
}
bool TreeBase::isWatered()const{
    return isWater;
}
bool TreeBase::canGrow(){
    int amount = isWater? getGrownSpeed() : getGrownSpeed()/2;
    AmountToGrown += amount;
    if(AmountToGrown>50){
        AmountToGrown = 0;
        return true;
    }
    return false;
}
bool TreeBase::getDead()const{
    return isDead;
}
void TreeBase::setDead(bool isDead){
    this->isDead = isDead;
}
int TreeBase::getAge()const{
    return month;
}
void TreeBase::setAge(int age){
    month = age;
}
string TreeBase::getLeafColor() const{
    return leafColor;
}
void TreeBase::setLeafColor(const string& color){
    leafColor = color;
}
int TreeBase::getGrownSpeed() const{
    return 0;
}
string TreeBase::getFruitColor() const{
    return "null";
}
string TreeBase::getType() const{
    return "Base";
}
ostream& operator<<(ostream& out, TreeBase& tree){
    for(int i=0;i<tree.getHeightData();i++){
        for(int j=0;j<tree.getWidthData();j++){
            if(tree.isWood(i,j)) out<<'X';
            else out<<'-';
        }
        out<<endl;
    }
    return out;
}
