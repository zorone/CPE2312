#include "internal/automata.h"

// TODO: Seperate Debug codes out completely. If possible, function that you would like to inspect, should pass into debug() function.
// TODO: Add user interaction mode -i, that it waits for user testing string.

// ? https://www.freecodecamp.org/news/extern-keyword-function-tutorial/
// internal data
FILE *passContainer = '\0';
FILE *failContainer = '\0';
FILE *testFailContainer = '\0';
int isTesting = 0;

// user data
char projectName[100] = "\0";
int size = 16;
int allocateSize;
long passStatus = 0;

int main(int argc, char *argv[]){
    init();

    setup("w");
    loop();
    fileClose();

    setup("r");
    test();
    fileClose();

    return 0;
}