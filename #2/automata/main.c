#include "automataWorkspace.h"

// TODO: Seperate Debug codes out completely. If possible, function that you would like to inspect, should pass into debug() function.

int main(int argc, char *argv[]){
    init();
    config();

    setup("w");
    loop();
    fileClose();

    setup("r");
    test();
    fileClose();

    return 0;
}