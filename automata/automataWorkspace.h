#pragma once

#ifndef AUTOMATA
#define AUTOMATA
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#endif

#ifndef AUTOMATAWORKSPACE_EXPORTS
#define AUTOMATAWORKSPACE_API __declspec(dllexport)
#else
#define	AUTOMATAWORKSPACE_API __declspec(dllimport)
#endif // AUTOMATAWORKSPACE_EXPORTS

// user defined
extern AUTOMATAWORKSPACE_API void config();
extern AUTOMATAWORKSPACE_API void control(char *str);
extern AUTOMATAWORKSPACE_API int automata(char *str);