#include <iostream>
#include <console.h>
#include "TreeGui.h"
#include "Lemon.h"
#include "Apple.h"
#include "Orange.h"
#include "Sapling.h"
#include <time.h>       /* time */
using namespace std;
int const ROW_MAX = 25;
int const COLS_MAX = 50;
//The main function only need to construct The GUI and run it.
//This is beta version so it gonna need to construct the tree
//and vector behavior and output the picture of 2 tree.
int main(){
    srand (time(NULL));
    vector<vector<bool>> *data = new vector<vector<bool>>;
    vector<TreeBaseBehavior*>* behavList = new vector<TreeBaseBehavior*>;
    for(int i = 0;i < ROW_MAX;i++){
        vector<bool> temp;
        for(int j = 0;j<COLS_MAX;j++){
            temp.push_back(false);
        };
        data->push_back(temp);
    }
    TreeBase* test = new Lemon(10,false, data);
    TreeBase* test2 = new Lemon(30,false, data);
    TreeBaseBehavior* test3 = new Sapling(*test);
    TreeBaseBehavior* test4 = new Sapling(*test2);
    behavList->push_back(test3);
    behavList->push_back(test4);
    //
    char animateinput = 'n';
    cout << "Animate trees? y/n ";
    cin >> animateinput;
    if(animateinput == 'y') {
      TreeGui treeScape = TreeGui(1440, 900, behavList, data);
    }
    //
    char input ='a';
      while(input!= 'b'){
        (*behavList)[0]->update();
        (*behavList)[1]->update();
        cout<<*test;
        cout<<test->setAge()<<endl;
        cout<<test->setWidth()<<endl;
        cout<<test->setHeight()<<endl;
        if(test3->isOld()) {
            test3 = test3->switchState();
        }
        cout<<test3->getType()<<endl;
        cin>>input;
      }
    return 0;
}
