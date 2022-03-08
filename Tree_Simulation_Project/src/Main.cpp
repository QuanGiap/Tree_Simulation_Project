#include <iostream>
#include <console.h>
#include "TreeGui.h"
#include "Lemon.h"
#include "Apple.h"
#include "Orange.h"
#include "Sapling.h"
#include <time.h>       /* time */
using namespace std;

//The main function only need to construct The GUI and run it.
//This is beta version so it gonna need to construct the tree
//and vector behavior and output the picture of 2 tree.
int main(){
    srand (time(NULL));
    char animateinput = 'n';
    cout << "Animate trees? y/n ";
    cin >> animateinput;
    if(animateinput == 'y')
      TreeGui treeScape(200,300);
    return 0;
}
