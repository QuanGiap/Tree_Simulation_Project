#include <iostream>
#include "gwindow.h"
int main(){
    std::cout<<"Hello world";
    sgl::GWindow gwin(300,300);
    gwin.setExitOnClose(true);
    return 0;
}
