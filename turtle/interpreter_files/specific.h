#ifndef SPECIFIC_H
#define SPECIFIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include "general.h"
#include "neillsdl2.h"

#define DELAY 10000
#define BUFF 1
#define MAXEXPR 20
#define TESTARR 50
#define NUMALPHA 26
#define PI_OVER_180 0.017453292
#define NUMALPHA 26
#define FULLCIRCLE 360
#define SET_CW 2
#define MIDHEIGHT 300
#define MIDWIDTH 400
#define RND 0.5
#define WHITE 200
#define strsame(A,B) (strcmp(A,B)==0)

/*the code below was taked from Neill Campbells ATDs*/
#define ELEMSIZE 20
#define STACKTYPE "Realloc"
#define FIXEDSIZE 16
#define SCALEFACTOR 2
typedef double stacktype;
typedef struct stack stack;
/*this stops here*/

typedef enum bool {false, true} bool;

typedef struct prog{
  char** str;
  /*used to store variable A - Z set during program.*/
  double var[26];
  int var_idx;
  /*defining whether or not the variable has been set*/
  bool var_set[26];
  int cw;
  int size;
  double x;
  double y;
  double angle;
  double dist_ang;
  SDL_Simplewin sw;

}Program;

/*the code below was taked from Neill Campbells ATDs*/
struct stack {
   stacktype* a;
   int size;
   int capacity;
};
/*this stops here*/

#endif
