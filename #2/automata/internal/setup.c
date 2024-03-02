#include "automata.h"

int setup(char* mode){
    char trueFileDir[100] = "cache/";
    strcat(trueFileDir, projectName);
    strcat(trueFileDir, "_true.txt");
    passContainer = fopen(trueFileDir, mode);

    char falseFileDir[100] = "cache/";
    strcat(falseFileDir, projectName);
    strcat(falseFileDir, "_false.txt");
    failContainer = fopen(falseFileDir, mode);

    char testFailFileDir[100] = "cache/";
    
	switch(mode[0]){
        case 'R': case 'r':
            strcat(testFailFileDir, projectName);
            strcat(testFailFileDir, "_failedList.txt");
            testFailContainer = fopen(testFailFileDir, "w");
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