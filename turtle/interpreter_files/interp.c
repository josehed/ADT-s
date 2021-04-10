#include "specific.h"
#include "interp_functions.h"

int main(int argc, char *argv[]){
  FILE *fp;
  int i = 0;
  Program* prog = calloc(1, sizeof(Program));

  if(argc != 2){
    fprintf(stderr, "Please enter one file name.\n");
    exit(1);
  }
  test();
  Init_Prog(argv[1], prog);
  if(!(fp = fopen(argv[1], "r"))){
    fprintf(stderr, "Cannot open %s\n", argv[1]);
    exit(1);
  }
  Neill_SDL_Init(&prog -> sw);
  Neill_SDL_SetDrawColour(&prog -> sw, WHITE, WHITE, WHITE);
  /*reading in file*/
  while(fscanf(fp, "%s", prog -> str[i]) == 1 &&\
  i < prog -> size){
    i++;
  };
    if(!Par_Main(prog)){
      fprintf(stderr,\
      "Error around word number %d, character %s\n",\
      prog -> cw, prog -> str[prog -> cw]);
      exit(1);
  };
  printf("Parsed OK\n");
  fclose(fp);
  while(!prog -> sw . finished){
    Neill_SDL_Events(&prog -> sw);
  }
  SDL_Quit();
  atexit(SDL_Quit);
  n2dfree((void**)prog -> str, prog -> size + BUFF);
  free(prog);
  return(0);
}
