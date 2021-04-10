#include "specific.h"
#include "pars_functions.h"

bool Par_Main(Program *p){
  if(!strsame(p -> str[p -> cw], "{")){
    return(false);
  }
  p -> cw++;
  if(Valid_Instructlst(p)){
    if(End_Clear(p)){
    return(true);
    }
  }
  return(false);
}
/*checks to make sure operator is valid*/
bool Valid_Op(Program *p){
  if(strcmp(p -> str[p -> cw], "+") == 0){
    p -> cw++;
    return(true);
  }
  if(strcmp(p -> str[p -> cw], "-") == 0){
    p -> cw++;
    return(true);
  }
  if(strcmp(p -> str[p -> cw], "*") == 0){
    p -> cw++;
    return(true);
  }
  if(strcmp(p -> str[p -> cw], "/") == 0){
    p -> cw++;
    return(true);
  }
  return(false);
}

/*checks to make sure var is valid*/
bool Valid_Var(Program *p){
  /*check to make sure it is a single letter*/
  if(strlen(p -> str[p -> cw]) != 1){
    return(false);
  }
  /*check the letter is between A and Z*/
  if(p -> str[p -> cw][0] >= 'A' &&\
     p -> str[p -> cw][0] <= 'Z'){
       p -> cw++;
       return(true);
  }
  return(false);
}

bool Valid_Num(Program *p){
  int length = strlen(p -> str[p -> cw]);
  int j = 0, cnt = 0;
  /*checks number doesnt start with '.' */
  if(p -> str[p ->cw][0] == '.'){
    return(false);
  }
  /*checks to make sure all chars in string are numbers\
  or "."*/
  if(p -> str[p ->cw][0] == '-'){
    j = 1;
  }
  /*this runs through the whole string chekcing its valid*/
  for(; j < length; j++){
    if(p -> str[p -> cw][j] == '.'){
      cnt++;
    }
    if(!isdigit(p -> str[p -> cw][j]) &&\
      p -> str[p -> cw][j] != '.'){
      return(false);
    }
  }
  /*in the above 4 loop we also check for the number of\
  full stops and if theres more than on then we fail*/
  if(cnt > 1){
    return(false);
  }
  p -> cw++;
  return(true);
}

bool Valid_Varnum(Program *p){
  if(Valid_Num(p) || Valid_Var(p)){
    return(true);
  }
  return(false);
}

bool Valid_Polish(Program *p){
  if(strcmp(p -> str[p -> cw], ";") == 0){
    p -> cw++;
    return(true);
  }
  if(!Valid_Op(p) && !Valid_Varnum(p)){
    return(false);
  }
  return(Valid_Polish(p));
}

/*check set is valid*/
bool Valid_Set(Program *p){
  if(strcmp(p -> str[p -> cw], "SET") != 0){
  return(false);
  }
  p -> cw++;  /*point to next string after set*/
  /*we then check if the var is valid*/
  if(!Valid_Var(p)){
    return(false);
  }
  if(strcmp(p -> str[p -> cw], ":=") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after :=*/
  if(!Valid_Polish(p)){
    return(false);
  }
  return(true);
}

bool Valid_Do(Program *p){
  if(strcmp(p -> str[p -> cw], "DO") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after do*/
  if(!Valid_Var(p)){
    return(false);
  }
  if(strcmp(p -> str[p -> cw], "FROM") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after from*/
  if(!Valid_Varnum(p)){
    return(false);
  }
  if(strcmp(p -> str[p -> cw], "TO") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after to*/
  if(!Valid_Varnum(p)){
    return(false);
  }
  if(strcmp(p -> str[p -> cw], "{") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after {*/
  if(!Valid_Instructlst(p)){
    return(false);
  }
  return(true);
}

bool Valid_Instruct(Program *p){
  if(!Valid_Fd(p) && !Valid_Lt(p) && !Valid_Rt(p) && \
  !Valid_Do(p) && !Valid_Set(p)){
    return(false);
  }
  return(true);
}

bool Valid_Instructlst(Program *p){
  if(strcmp(p -> str[p -> cw], "}") == 0){
    p -> cw++;
    return(true);
  }

  if(!Valid_Instruct(p)){
    return(false);
  }
  return(Valid_Instructlst(p));
}

bool Valid_Fd(Program *p){
  if(strcmp(p -> str[p -> cw], "FD") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after FD*/
  if(!Valid_Varnum(p)){
    return(false);
  }
  return(true);
}

bool Valid_Lt(Program *p){
  if(strcmp(p -> str[p -> cw], "LT") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after FD*/
  if(!Valid_Varnum(p)){
    return(false);
  }
  return(true);
}

bool Valid_Rt(Program *p){
  if(strcmp(p -> str[p -> cw], "RT") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after FD*/
  if(!Valid_Varnum(p)){
    return(false);
  }
  return(true);
}
/*checks to make sure theres noting after the end of the \
closing bracket*/
bool End_Clear(Program *p){
  if(strlen(p -> str[p -> cw]) == 0){
    return(true);
  }
  return(false);
}
