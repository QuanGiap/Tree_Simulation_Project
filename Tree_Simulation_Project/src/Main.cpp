#include "TreeGui.h"
#include <time.h>
using namespace std;

//The main function only need to construct The GUI and run it.
int main(){
    srand (time(NULL));
    //setting the height of data is 200 and width is 300
    TreeGui treeScape(200,300);
    return 0;
}
