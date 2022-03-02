#include <iostream>
#include <console.h>
#include "Lemon.h"
#include "Apple.h"
#include "Orange.h"
#include "Sapling.h"
#include <time.h>       /* time */
using namespace std;
int const ROW_MAX = 25;
int const COLS_MAX = 50;
int main(){
    srand (time(NULL));
    vector<vector<bool>> *data = new vector<vector<bool>>;
    for(int i = 0;i < ROW_MAX;i++){
        vector<bool> temp;
        for(int j = 0;j<COLS_MAX;j++){
            temp.push_back(false);
        }
        data->push_back(temp);
    }
    TreeBase* test = new Lemon(25,10, data);
    TreeBase* test2 = new Lemon(25,30,data);
    TreeBaseBehavior* test3 = new Sapling(*test);
    TreeBaseBehavior* test4 = new Sapling(*test2);
    char input ='a';
      while(input!= 'b'){
        test3->update();
        test4->update();
        cout<<*test;
        cout<<test->getAge()<<endl;
        if(test3->isOld()) {
            test3 = test3->switchState();
        }
        cout<<test3->getType()<<endl;
        cin>>input;
      }
    return 0;
}
