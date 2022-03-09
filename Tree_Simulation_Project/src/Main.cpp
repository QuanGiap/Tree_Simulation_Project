#include "TreeGui.h"
#include <time.h>       /* time */
using namespace std;

//The main function only need to construct The GUI and run it.
int main(){
    srand (time(NULL));
    TreeGui treeScape(200,300);
    return 0;
}
