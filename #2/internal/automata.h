#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

// internal
int setup(char* mode);
int loop();
int setProjectName(char *name);
int setPass(char *str);
int setFail(char *str);
int test();
int fileClose();

// user defined
void init();
void control(char *str);
int automata(char *str);

#ifndef INC
#define INC
// internal data
extern FILE *passContainer;
extern FILE *failContainer;
extern FILE *testFailContainer;
extern int isTesting;

// user data
extern char projectName[100];
extern int size;
extern int allocateSize;

// debug
extern long passStatus;
#endif