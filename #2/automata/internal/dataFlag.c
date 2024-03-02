#include "automataLib.h"

int setPass(char *str){
    fprintf(passContainer, "%s\n", str);

    return 0;
}

int setFail(char *str){
    fprintf(failContainer, "%s\n", str);

    return 0;
}