#include "TreeBase.h"
#include <iostream>
using namespace std;
TreeBase::TreeBase(int pos,bool isWater,vector<vector<bool>>*& table){
    leafColor = "green";
    month = 0;
    width = 1;
    height = 2;
    data = table;
    (*data)[getHeightData()-1][pos] = true;
    (*data)[getHeightData()-2][pos] = true;
    plantPosition = pos;
    this->isWater = isWater;
}
int TreeBase::getPlantPos() const{
    return plantPosition;
}
void TreeBase::setTrue(int i, int j){
    if(i>=0 && i<getHeightData() && j>=0 && j <getWidthData())
        (*data)[i][j] = true;
}
int& TreeBase::setWidth(){
    return width;
}
int& TreeBase::setHeight(){
    return height;
}
int TreeBase::getWidthData() const{
    return (*data)[0].size();
}
int TreeBase::getHeightData() const{
    return (*data).size();
}
bool TreeBase::isWood(int col, int row)const{
    if(row<0||col<0||row>=getWidthData()||col>=getHeightData()) return false;
    return (*data)[col][row];
}
int& TreeBase::setAge() {
    return month;
}
string TreeBase::getLeafColor() const{
    return leafColor;
}
void TreeBase::setLeafColor(const string color){
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
