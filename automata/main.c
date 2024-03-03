#include "automataWorkspace.h"

// TODO: Seperate Debug codes out completely. If possible, function that you would like to inspect, should pass into debug() function.
// TODO: Add user interaction mode -i, that it waits for user testing string.

// TODO: Add support for Quiet -q
// TODO: Add support for Progress bar -P
// TODO: Add support for no cached -n
// TODO: Add support for only report -R

// TODO: Add support for no recursive (for NFA -- check only until it is accept.) -r
// TODO: Add support for Listing all route (for NFA) -l

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