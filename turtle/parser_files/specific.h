#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
/*Borrowed your code here Neill and thanks for the term,\
really appreciate it!*/
#include "general.h"

#define BUFF 1
#define MAXEXPR 15
#define TESTARR 50
#define NUMALPHA 26
#define strsame(A,B) (strcmp(A,B)==0)

typedef enum bool {false, true} bool;

typedef struct prog{
  char** str;
  int cw;
  int size;
}Program;
