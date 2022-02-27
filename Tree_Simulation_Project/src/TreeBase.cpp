#include "TreeBase.h"
TreeBase::TreeBase(int height, int width){
    leafColor = "green";
    year = 0;
    for(int i = 0;i < height;i++){
        vector<bool> temp;
        for(int j = 0;j<width;j++){
            temp.push_back(false);
        }
        data.push_back(temp);
    }
    data[height-1][width/2] = true;
    data[height-2][width/2] = true;
    leafPoint.push_back(height-2);
    leafPoint.push_back(width/2);
}
void TreeBase::setTrue(int i, int j){
    data[i][j] = true;
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
int TreeBase::getAge() const{
    return year;
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
