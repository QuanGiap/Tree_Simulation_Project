// Quan Giap/Niels Larson, CS& 132, Winter 2022
// Final Programming Assignment, 3/2/22

#include "Old.h"

Old::Old(TreeBase& tree):Adult(tree){
    setRatio(2);
}
bool Old::isOld(){
    return false;
}
string Old::getType() const{
    return "Old";
}
