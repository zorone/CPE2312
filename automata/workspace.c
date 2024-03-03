#include "automataWorkspace.h"
#include "internal/automataLib.h"

// TODO: Add support for NFA. Maybe through add(). add() will automatically set and create 2D arr when first calling it.
//? NFA data storage structure; idx: {str, pathA, pathB, ...}; ex. 0: {1010: ACDA, AADA}

// TODO: Add support for setAlphabetList
// TODO: Add support for setProjectName

// TODO: Add support for user-defined testing. (In test() function.)

// TODO: Do documentation

void config(){
    // user data
    char projectName[100] = "\0"; // Add your project name here...
    // setSize(16); default string size is 16
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