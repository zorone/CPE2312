#include "automata.h"

int loop(){

    // TODO: Added status report. (Percentages, and string length at any given time.)

    allocateSize = size + 1;
    char *str = malloc(sizeof(char)*allocateSize);

    memset(str, '\0', allocateSize*sizeof(char)); // https://stackoverflow.com/questions/3082914/c-compile-error-variable-sized-object-may-not-be-initialized#comment106435006_3082914
    int prev = 0;
    int oneCharStreakCount = 0;
    int idx = 1;
    long count = 0;
    int carryOut = 0;
    int sizePreference = 0;
    int maxIdx = 0;
    int isStringWider = 0;

    for(int length = 1; length < allocateSize; length++){

        maxIdx = length-1;
        str[length] = '\0';
        do {
            idx = prev - oneCharStreakCount;
            if(idx < 0){
            	isStringWider = 1;
            	break;
            }
                
            if(oneCharStreakCount || isStringWider){
                for(int i = idx+1; i < length; i++){
                    str[i] = '0';
                }
                str[idx] = '1';
                oneCharStreakCount = 0;
                isStringWider = 0;
            }

            else{
                oneCharStreakCount = 0;
                sizePreference = maxIdx;
                for(; idx > -1; idx--){
                    switch(str[idx]){
                        case '1':
                            if(idx == sizePreference){
                                oneCharStreakCount++;
                                sizePreference--;
                            }
                            if(idx == maxIdx || carryOut){
                                carryOut = 1;
                            }
                            else{
                                break;
                            }
                        case '\0': 
                            str[idx] = '0';
                            break;
                        case '0':
                            if(idx == maxIdx){
                                str[idx] = '1';
                                oneCharStreakCount++;
                                sizePreference--;
                            }
                            else if(carryOut){
                                str[idx] = '1';
                            }
                            carryOut = 0;
                            break;
                        default:
                            printf("Error: somethings unexpected happens while generating string.");
                    }
                }
            }

            control(str);
            count++;
        }
        while(1);

        prev = length;
    }

    // https://stackoverflow.com/questions/23375466/heap-corruption-detected-when-using-free
    free(str);
    return 0;
}