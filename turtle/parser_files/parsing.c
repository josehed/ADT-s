#include "specific.h"
#include "pars_functions.h"


int main(int argc, char *argv[]){
  FILE *fp;
  int i = 0;
  char a[MAXEXPR];
  Program* prog = calloc(1, sizeof(Program));
  prog -> cw = 0;
  prog -> size = 0;

  if(argc != 2){
    fprintf(stderr, "Please enter one file name.\n");
    exit(1);
  }
  test();
  /*opening file*/
  if(!(fp = fopen(argv[1], "r"))){
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    exit(1);
  }
  /*the code below finds the size of the file*/
  while(fscanf(fp, "%s", a) == 1){
    prog -> size++;
  };
  fclose(fp);
  /*we close and open again to make sure were at the start*/
  if(!(fp = fopen(argv[1], "r"))){
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    exit(1);
  }
  /*making space for the file*/
  /*buff is added so that the End_Clear check wont go out\
  of bounds*/
  prog -> str = (char**)n2dcalloc(prog -> size + BUFF, MAXEXPR, sizeof(char*));
  /*reading in file*/
  while(fscanf(fp, "%s", prog -> str[i++]) == 1 &&\
        i < prog -> size);
  if(!Par_Main(prog)){
    fprintf(stderr,\
    "Error around word number %d, character %s\n",\
    prog -> cw, prog -> str[prog -> cw]);
    exit(1);
  };
  printf("Parsed OK\n");
  fclose(fp);
  n2dfree((void**)prog -> str, prog -> size + BUFF);
  free(prog);
  return(0);
}
