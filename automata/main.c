#include "automataWorkspace.h"

// TODO: Seperate Debug codes out completely. If possible, function that you would like to inspect, should pass into debug() function.
// TODO: Add user interaction mode -i, that it waits for user testing string.

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