#include "internal/automata.h"

void init(){
    setProjectName(""); // Put your project name here.
    // size = 16; // The default size of string is 16
}

void control(char *str){
    // Example codes
    int size = strlen(str);

    if(size%2 == 0){
        setPass(str);
    }
    else{
        setFail(str);
    }
}

int automata(char *str){

    // Example codes, count string if string length dividable by 2 or not.
    char state = 'A';
    for(int idx=0; str[idx]!='\0'; idx++){
        switch(str[idx]){
            case '0': case '1':
                switch(state){
                    case 'A':
                        state = 'B';
                        break;
                    case 'B':
                        state = 'A';
                        break;
                }
                break;
            default:
                printf("Invalid character, the character will be treated as NULL\n");
                break;
        }
    }
    switch(state){
        case 'A':
            return TRUE;
        case 'B':
            return FALSE;
        default:
            printf("Invalid state...\n");
            return -1;
    }
}