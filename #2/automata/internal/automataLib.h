#pragma once

#ifndef AUTOMATA
#define AUTOMATA
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#endif

#ifndef AUTOMATALIBRARY_EXPORTS
#define AUTOMATALIBRARY_API __declspec(dllexport)
#else
#define	AUTOMATALIBRARY_API __declspec(dllimport)
#endif // AUTOMATALIBRARY_EXPORTS


// internal
extern AUTOMATALIBRARY_API int init();
extern AUTOMATALIBRARY_API int setup(char* mode);
extern AUTOMATALIBRARY_API int setProjectName(char* name);
extern AUTOMATALIBRARY_API int setSize(int length);
extern AUTOMATALIBRARY_API int loop();
extern AUTOMATALIBRARY_API int setPass(char *str);
extern AUTOMATALIBRARY_API int setFail(char *str);
extern AUTOMATALIBRARY_API int test();
extern AUTOMATALIBRARY_API int fileClose();

#ifndef INC
#define INC
// internal data
extern AUTOMATALIBRARY_API FILE *passContainer;
extern AUTOMATALIBRARY_API FILE *failContainer;
extern AUTOMATALIBRARY_API FILE *testFailContainer;
extern AUTOMATALIBRARY_API int isTesting;
extern AUTOMATALIBRARY_API int allocateSize;

// user data
extern AUTOMATALIBRARY_API char projectName[100];
extern AUTOMATALIBRARY_API int size;
#endif