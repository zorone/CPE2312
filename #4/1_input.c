#include <stdio.h>

enum Q {A, B, C, D, E, F}; // enum คือ การประกาศ ให้ตัวอักษร มีค่าเป็น ตัวเลข
char alphabet[2] = {'0', '1'};
int q0 = A;
int transitionTable[6][2] = {{B, E}, {C, D}, {C, C}, {E, F}, {F, E}, {F, D}};
int final[6] = {0, 0, 1, 1, 0, 0};
int transitionOld(int state, char inputCh);
int transition(int state, char inputCh);
int extendedTransition(int state, char *inputStr);
int acceptOrNot(int state);

int main(void){

    char *inputStr;
    scanf("%s", inputStr);
    printf("result = %d\n", extendedTransition(q0, inputStr));
    printf("transition B, 1 = %d\n", transition(B, '1'));
    acceptOrNot(extendedTransition(q0, inputStr));
    return 0;
}

int transition(int state, char inputCh){
    int index = inputCh - 48;
    return transitionTable[state][index];
}

int transitionOld(int state, char inputCh){
    if (state == A){
        if(inputCh == '0'){
            state = B;
        }
        else if(inputCh == '1'){
            state = A;
        }
    }
    else if (state == B){
        if(inputCh == '0'){
            state = B;
        }
        else if(inputCh == '1'){
            state = C;
        }
    }
    else if (state == C){
        if(inputCh == '0'){
            state = B;
        }
        else if(inputCh == '1'){
            state = A;
        }
    }

    return state;
}

int extendedTransition(int state, char *inputStr){
    int i = 0;
    while(inputStr[i] != '\0'){
        state = transition(state, inputStr[i]);
        i++;
    }

    return state;
}

int acceptOrNot(int state){
    if(final[state] == 1){
        printf("Yes, accept\n");
    }
    else{
        printf("Not accept\n");
    }

    return final[state];
}