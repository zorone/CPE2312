#include<stdio.h>
#include<string.h>

int main(int argc, char *argv){
    char str[17] = "\0";
    int prev = 0;
    int oneCharCount = -1;
    int idx = 1;
    long count = 0;
    int carryOut = 0;
    int maxIdx = 0;
    int isStringWider = 0;

    for(int length = 1; length < 17; length++){
        maxIdx = length-1;
        str[length] = '\0';
        do {
            if(oneCharCount > maxIdx){
            	isStringWider = 1;
            	break;
            }

            else{
                oneCharCount = 0;
                for(idx = maxIdx; idx > -1; idx--){
                    switch(str[idx]){
                        case '1':
                            if(idx == maxIdx || carryOut){
                                carryOut = 1;
                            }
                            else{
                                oneCharCount++;
                                break;
                            }
                        case '\0': 
                            carryOut = 1;
                            str[idx] = '0';
                            break;
                        case '0':
                            if(idx == maxIdx){
                                oneCharCount++;
                                str[idx] = '1';
                            }
                            else if(carryOut){
                                oneCharCount++;
                                str[idx] = '1';
                            }
                            carryOut = 0;
                            break;
                        default:
                            printf("Error: somethings unexpected happens while generating string.");
                    }
                }
            }
            printf("%5ld: %16s\n", count, str);
            count++;
        }
        while(1);
        prev = length;
    }

    return 0;
}