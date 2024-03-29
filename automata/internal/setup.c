#include "automataLib.h"

/*  TODO: dynamics variable passContainer, failContainer, and testFailContainer. In cases using -n[ocache]
 *        It should possible to use same interface, both via RAM, and also storage.
 */

int init(){
    // ? https://www.freecodecamp.org/news/extern-keyword-function-tutorial/
    // ? https://learn.microsoft.com/en-us/cpp/error-messages/tool-errors/linker-tools-error-lnk2001?view=msvc-170&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(LNK2001)%26rd%3Dtrue
    int isTesting;
    char projectName[100] = "\0";
    int size = 16; // default size is 16

    return 0;
}

int setup(char* mode){
    char trueFileDir[100] = "cache/";
    strcat(trueFileDir, projectName);
    strcat(trueFileDir, "_true.txt");
    FILE *passContainer = fopen(trueFileDir, mode);

    char falseFileDir[100] = "cache/";
    strcat(falseFileDir, projectName);
    strcat(falseFileDir, "_false.txt");
    FILE *failContainer = fopen(falseFileDir, mode);

    char testFailFileDir[100] = "cache/";
    
	switch(mode[0]){
        case 'R': case 'r':
            strcat(testFailFileDir, projectName);
            strcat(testFailFileDir, "_failedList.txt");
            FILE *testFailContainer = fopen(testFailFileDir, "w");
            isTesting = 1;
    }

    return 0;
}

int fileClose(){
    fclose(passContainer);
    fclose(failContainer);
    if(isTesting){
        fclose(testFailContainer);
        isTesting = 0;
    }

    return 0;
}