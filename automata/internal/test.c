#include "automataLib.h"

int test(){
    char *testStr = malloc(sizeof(char)*size);
    int signal = 0;
    int output;
    int allFail = 0;
    int trueFail = 0;
    int falseFail = 0;
    int allCount = 0;
    int trueCount = 0;
    int falseCount = 0;
    long trueLabelIndex = -1;
    long falseLabelIndex = -1;
    double allAccuracy = 100;
    double trueAccuracy = 100;
    double falseAccuracy = 100;

    memset(testStr, '\0', allocateSize*sizeof(char));

    trueLabelIndex = ftell(testFailContainer);

    printf("***********************************True Test************************************\n");
    while(signal != EOF){
        allCount++;
        trueCount++;
        output = automata(testStr);

        if(output == TRUE){
            allAccuracy = (double)allFail/(double)allCount * 100.0;
            trueAccuracy = (double)trueFail/(double)trueCount * 100.0;
            printf("%*s: PASS%-20s%5.2lf  %5.2lf\n", size, testStr, " ", trueAccuracy, allAccuracy);
        }
        else{
            trueFail++;
            allFail++;

            allAccuracy = (double)allFail/(double)allCount * 100.0;
            trueAccuracy = (double)trueFail/(double)trueCount * 100.0;

            printf("%*s: FAIL%-20s%5.2lf  %5.2lf\n", size, testStr, " ", trueAccuracy, allAccuracy);
            fprintf(testFailContainer, "%5d %5d %*s\n", allFail, trueFail, size, testStr);
        }
        
        signal = fscanf(passContainer, "%s\n", testStr);
    }

    fprintf(testFailContainer, "\n");
    falseLabelIndex = ftell(testFailContainer);

    printf("********************************************************************************\n");
    printf("**********************************False Test************************************\n");

    signal = fscanf(failContainer, "%s\n", testStr);
    while(signal != EOF){
        allCount++;
        falseCount++;
        output = automata(testStr);

        if(output == FALSE){
            allAccuracy = (double)allFail/(double)allCount * 100.0;
            trueAccuracy = (double)falseFail/(double)falseCount * 100.0;
            printf("%*s: PASS%-20s%5.2lf  %5.2lf\n", size, testStr, " ", falseAccuracy, allAccuracy);
        }
        else{
            allFail++;
            falseFail++;
            
            allAccuracy = (double)allFail/(double)allCount * 100.0;
            falseAccuracy = (double)falseFail/(double)falseCount * 100.0;

            printf("%*s: FAIL%-20s%5.2lf  %5.2lf\n", size, testStr, " ", falseAccuracy, allAccuracy);
            fprintf(testFailContainer, "%5d %5d %*s\n", allFail, falseFail, size, testStr);
        }
        
        signal = fscanf(failContainer, "%s\n", testStr);
    }

    free(testStr);

    fprintf(testFailContainer, "\n, There are %d cases that is failed.\n", allFail);
    fprintf(testFailContainer, "There are %d failed cases in Accepted condition.\n", trueFail);
    fprintf(testFailContainer, "There are %d failed cases in Denied condition.\n", falseFail);
    fseek(testFailContainer, falseLabelIndex, SEEK_SET);
    if(falseFail){
        fprintf(testFailContainer, "FALSE condition: FAILED %d from %d\n", falseFail, falseCount);
        fprintf(testFailContainer, "ACCURACY RATE: %5.2lf\n", falseAccuracy);
    }

    printf("********************************************************************************\n");
    fseek(testFailContainer, trueLabelIndex, SEEK_SET);
    if(allFail){
        fprintf(testFailContainer, "ALL condition: FAILED %d from %d\n", allFail, allCount);
        fprintf(testFailContainer, "ACCURACY RATE: %5.2lf\n\n", allAccuracy);
    }
    else{
        fprintf(testFailContainer, "Your automata operation is working properly.\n");
        return 0;
    }
    if(trueFail){
        fprintf(testFailContainer, "TRUE condition: FAILED %d from %d\n", trueFail, trueCount);
        fprintf(testFailContainer, "ACCURACY RATE: %5.2lf\n\n", trueAccuracy);
    }

    return 1;
}