#include "TreeBase.h"
TreeBase::TreeBase(int rows, int cols){
    leafColor = "green";
    month = 0;
    for(int i = 0;i < rows;i++){
        vector<bool> temp;
        for(int j = 0;j<cols;j++){
            temp.push_back(false);
        }
        data.push_back(temp);
    }
    width = 1;
    height = 2;
    data[rows-1][cols/2] = true;
    data[rows-2][cols/2] = true;
    leafPoint.push_back(rows-2);
    leafPoint.push_back(cols/2);
}
void TreeBase::setTrue(int i, int j){
    data[i][j] = true;
}
int& TreeBase::getWidth(){
    return width;
}
int& TreeBase::getHeight(){
    return height;
}
int TreeBase::getWidthData() const{
    return data[0].size();
}
int TreeBase::getHeightData() const{
    return data.size();
}
vector<int>& TreeBase::getLeafLocate(){
    return leafPoint;
}
bool TreeBase::isWood(int col, int row)const{
    if(row<0||col<0||row>=getWidthData()||col>=getHeightData()) return false;
    return data[col][row];
}
int& TreeBase::getAge() {
    return month;
}
string TreeBase::getLeafColor() const{
    return leafColor;
}
void TreeBase::setLeafColor(string color){
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
