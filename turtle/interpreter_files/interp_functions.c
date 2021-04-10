#include "specific.h"
#include "interp_functions.h"
#include "stack.h"

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
  p -> cw--; /*bring us back one so that in set*/
  if(!Do_Set(p)){
    return(false);
  }
  return(true);
}

bool Valid_Do(Program *p){
  double from, to;
  if(strcmp(p -> str[p -> cw], "DO") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after do*/
  if(!Valid_Var(p)){
    return(false);
  }
  p -> cw--; /*Valid_Var does cw++, we need to bring back*/
  Set_Var(p); /*sets var as valid*/

  if(strcmp(p -> str[p -> cw], "FROM") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after from*/
  if(!Valid_Varnum(p)){
    return(false);
  }
  if(!Extract_Num(p)){ /*this stuff here is extracting*/
    return(false);     /*the number from from and putting*/
  }                    /*it into the variable from*/
  from = p -> dist_ang;
  if(strcmp(p -> str[p -> cw], "TO") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after to*/
  if(!Valid_Varnum(p)){
    return(false);
  }
  if(!Extract_Num(p)){ /*this stuff here is extracting*/
    return(false);     /*the number from to and putting*/
  }                    /*it into the variable to*/
  to = p -> dist_ang;
  if(strcmp(p -> str[p -> cw], "{") != 0){
    return(false);
  }
  p -> cw++;  /*point to next string after {*/
  if(!Do_Do(p, from, to)){
    return(false);
  }
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
  if(!Do_Move(p)){
    return(false); /*just checks var set and moves coords*/
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
  if(!Turn_Left(p)){
    return(false); /*just checks var set and moves coords*/
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
  if(!Turn_Right(p)){
    return(false); /*just checks var set and moves coords*/
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

bool Do_Move(Program *p){
  double n_x, n_y;
  double rads;
  if(!Extract_Num(p)){
    return(false);
  }
  rads = p -> angle * PI_OVER_180;
  n_x = p -> x + (p -> dist_ang * cos(rads));
  n_y = p -> y + (p -> dist_ang * sin(rads));
  SDL_RenderDrawLine(p -> sw . renderer, (int)p -> x + RND,\
  (int)p -> y + RND, (int)n_x + RND, (int)n_y + RND);
  Neill_SDL_UpdateScreen(&p -> sw);
  p -> x = n_x;
  p -> y = n_y;
  return(true);
}

bool Turn_Right(Program *p){
double local_angle = 0;
  if(!Extract_Num(p)){
    return(false);
  }
  local_angle = p -> dist_ang;
  local_angle = fmod(local_angle, FULLCIRCLE);
  if(local_angle < 0){
    local_angle += FULLCIRCLE;
  }
  p -> angle = local_angle + p -> angle;
  p -> angle = fmod(p -> angle, FULLCIRCLE);
  return(true);
}

bool Turn_Left(Program *p){
double local_angle = 0;
  if(!Extract_Num(p)){
    return(false);
  }
  local_angle = p -> dist_ang;
  if(local_angle < 0){
    local_angle = fabs(local_angle);
    p -> angle = local_angle + p -> angle;
  }
  else{
    local_angle = fmod(local_angle, FULLCIRCLE);
    local_angle = FULLCIRCLE - local_angle;
    p -> angle = p -> angle + local_angle;
  }
  p -> angle = fmod(p -> angle, FULLCIRCLE);
  return(true);
}

bool Do_Do(Program *p, double from, double to){
int save_cw = p -> cw;
int save_var_idx = p -> var_idx;
/*dont not allow decending loops*/
if(to < from){
  return(false);
}
while(from <= to){
  p -> var[p -> var_idx] = from;
  p -> cw = save_cw;
  if(!Valid_Instructlst(p)){
    return(false);
  }
  p -> var_idx = save_var_idx;
  from++;
}
p -> cw--;
return(true);
}

void Set_Var(Program *p){
  char localvar;
  int localvar_idx;
  localvar = *p -> str[p -> cw];
  localvar_idx = localvar - 'A';
  p -> var_set[localvar_idx] = true;
  p -> var_idx = localvar_idx;
  p -> cw = p -> cw + 1;
}

bool Extract_Num(Program *p){
  char localvar;
  int localvar_idx;
  char *ptr;
  /*check if its a num or var*/
  /*as this has already gone through the parser the cw\
  points to the next function so we bring it back*/
  p -> cw = p -> cw - 1;
  if(Valid_Var(p)){
    p -> cw = p -> cw - 1; /*called Valid_Var so -1 cw*/
    localvar = *p -> str[p -> cw];
    localvar_idx = localvar - 'A';
    if(p -> var_set[localvar_idx] == false){
      return(false);
    }
    p -> dist_ang = p -> var[localvar_idx];
  }
  else{
    p -> dist_ang = strtod(p -> str[p -> cw], &ptr);
  }
  p -> cw = p -> cw + 1;
  return(true);
}

bool Do_Polish(Program *p){
  stack *s;
  stacktype a, b, c = 0;
  s = stack_init();
  /*this brings up back to the begining of the*/
  if(strcmp(p -> str[p -> cw + 1], ";") == 0){
    p -> cw++;
    if(!Extract_Num(p)){
      return(false);
    }
    p -> cw++;
    return(true);
  }
  while(strcmp(p -> str[p -> cw], ";") != 0){
    /*so the fillowing code just checks that the cw isnt\
    '-' as this seen as valid to Valid_Num for neg numbs*/
  if(strcmp(p -> str[p -> cw], "-") != 0 &&\
  Valid_Varnum(p)){
    Extract_Num(p);
    stack_push(s, p -> dist_ang);
  }
    else{
      if(!stack_pop(s, &a)){
        return(false);
      }
      if(!stack_pop(s, &b)){
       return(false);
      }
      switch(p -> str[p -> cw][0]){
        case '+':
          c = a + b;
          break;
        case '*':
          c = a * b;
          break;
        case '/':
          /*make sure your not dividing by 0*/
          if(fabs(a) < 0.000001){
            return(false);
          }
          c = b / a;
          break;
        case '-':
          c = b - a;
          break;
        default:
        return(false);
      }
    stack_push(s, c);
    p -> cw++;
    }
  }
  /*pop result into a*/
  if(!stack_pop(s, &a)){
    return(false);
  }
  /*if theres anything left on the stack return false*/
  if(stack_peek(s, &b) == true){
    return(false);
  }
  p -> dist_ang = a;
  p -> cw++;
  stack_free(s);
  return(true);
}

bool Do_Set(Program *p){
  while(strcmp(p -> str[p -> cw], "SET") != 0){
    p -> cw--;
  }
  p -> cw++; /*add one so that were pointing at the first\
               var in set*/
  Set_Var(p);
  p -> cw++; /*points to start of polish*/
  if(!Do_Polish(p)){
    return(false);
  }
  p -> var[p -> var_idx] = p -> dist_ang;
  return(true);
}

void Init_Prog(char *arg, Program *p){
  FILE *fp;
  char a[MAXEXPR];
  /*opening file*/
  if(!(fp = fopen(arg, "r"))){
    fprintf(stderr, "Cannot open %s\n", arg);
    exit(1);
  }
  p -> cw = 0;
  p -> size = 0;
  p -> x = MIDWIDTH;
  p -> y = MIDHEIGHT;
  p -> angle = 270;
  /*the code below finds the size of the file*/
  while(fscanf(fp, "%s", a) == 1){
    p -> size++;
  };
  /*making space for the file*/
  /*buff is added so that the End_Clear check wont go out\
  of bounds*/
  p -> str = (char**)n2dcalloc(p -> size + BUFF,\
  MAXEXPR, sizeof(char*));
  fclose(fp);
  /*we close and open again to make sure were at the start*/
}
