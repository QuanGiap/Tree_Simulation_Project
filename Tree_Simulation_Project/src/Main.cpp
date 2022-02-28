#include <iostream>
#include <console.h>
#include "Lemon.h"
#include "Apple.h"
#include "Orange.h"
#include "Sapling.h"
#include "Old.h"
using namespace std;
int main(){
    TreeBase* test = new Lemon(50,50);
    TreeBaseBehavior test2(*test);
    char input ='a';
      while(input!= 'b'){
        cout<<*test;
        test2.update();
        cin>>input;
      }
    return 0;
}
