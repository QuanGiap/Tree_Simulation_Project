#include <iostream>
#include <console.h>
#include "Lemon.h"
#include "Apple.h"
#include "Orange.h"
#include "Sapling.h"
using namespace std;
int main(){
    TreeBase* test = new Lemon(25,25);
    TreeBaseBehavior* test2 = new Sapling(*test);
    char input ='a';
      while(input!= 'b'){
        test2->update();
        cout<<*test;
        cout<<test->getAge()<<endl;
        if(test2->isOld()) {
            test2 = test2->switchState();
        }
        cout<<test2->getType()<<endl;
        cin>>input;
      }
    return 0;
}
