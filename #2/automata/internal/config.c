#include "automataLib.h"

int setProjectName(char* name){
    strcpy(projectName, name);
    return 0;
}

int setSize(int length) {
    size = length;
    return 0;
}