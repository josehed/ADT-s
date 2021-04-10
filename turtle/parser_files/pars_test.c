#include "specific.h"
#include "pars_functions.h"

void test(void){

  Program* a = calloc(1, sizeof(Program));
  a -> cw = 0;
  a -> size = TESTARR;
  /*buff is added so that the End_Clear check wont go out\
  of bounds*/
  a -> str = (char**)n2dcalloc(a -> size + BUFF, MAXEXPR, sizeof(char*));
  /*testing Valid_Op*/
  strcpy(a -> str[0], "+");
  a -> cw = 0;
  assert(Valid_Op(a) == true);
  strcpy(a -> str[1], "-");
  a -> cw = 1;
  assert(Valid_Op(a) == true);
  strcpy(a -> str[2], "*");
  a -> cw = 2;
  assert(Valid_Op(a) == true);
  strcpy(a -> str[3], "/");
  a -> cw = 3;
  assert(Valid_Op(a) == true);
  strcpy(a -> str[4], "-d");
  a -> cw = 4;
  assert(Valid_Op(a) == false);
  strcpy(a -> str[5], "3");
  a -> cw = 5;
  assert(Valid_Op(a) == false);
  strcpy(a -> str[6], "]+");
  a -> cw = 6;
  assert(Valid_Op(a) == false);
  strcpy(a -> str[7], "++");
  a -> cw = 7;
  assert(Valid_Op(a) == false);
  strcpy(a -> str[8], "-+");
  a -> cw = 8;
  assert(Valid_Op(a) == false);
  strcpy(a -> str[9], "=");
  a -> cw = 9;
  assert(Valid_Op(a) == false);
  strcpy(a -> str[10], " ");
  a -> cw = 10;
  assert(Valid_Op(a) == false);

  /*testing Valid_Var*/
  strcpy(a -> str[0], "A");
  a -> cw = 0;
  assert(Valid_Var(a) == true);
  strcpy(a -> str[1], "Z");
  a -> cw = 1;
  assert(Valid_Var(a) == true);
  strcpy(a -> str[2], "D");
  a -> cw = 2;
  assert(Valid_Var(a) == true);
  strcpy(a -> str[3], "X");
  a -> cw = 3;
  assert(Valid_Var(a) == true);
  strcpy(a -> str[4], "a");
  a -> cw = 4;
  assert(Valid_Var(a) == false);
  strcpy(a -> str[5], "z");
  a -> cw = 5;
  assert(Valid_Var(a) == false);
  strcpy(a -> str[6], "]");
  a -> cw = 6;
  assert(Valid_Var(a) == false);
  strcpy(a -> str[7], "~");
  a -> cw = 7;
  assert(Valid_Var(a) == false);
  strcpy(a -> str[8], "-A");
  a -> cw = 8;
  assert(Valid_Var(a) == false);
  strcpy(a -> str[9], ".B");
  a -> cw = 9;
  assert(Valid_Var(a) == false);
  strcpy(a -> str[10], "C*");
  a -> cw = 10;
  assert(Valid_Var(a) == false);


  /*testing Valid_Num*/
  strcpy(a -> str[0], "6");
  a -> cw = 0;
  assert(Valid_Num(a) == true);
  strcpy(a -> str[1], "5.5");
  a -> cw = 1;
  assert(Valid_Num(a) == true);
  strcpy(a -> str[2], "0.5");
  a -> cw = 2;
  assert(Valid_Num(a) == true);
  strcpy(a -> str[3], "58534");
  a -> cw = 3;
  assert(Valid_Num(a) == true);
  strcpy(a -> str[4], "-547");
  a -> cw = 4;
  assert(Valid_Num(a) == true);
  strcpy(a -> str[5], "f");
  a -> cw = 5;
  assert(Valid_Num(a) == false);
  strcpy(a -> str[6], ".4");
  a -> cw = 6;
  assert(Valid_Num(a) == false);
  strcpy(a -> str[7], "]");
  a -> cw = 7;
  assert(Valid_Num(a) == false);
  strcpy(a -> str[8], "4p");
  a -> cw = 8;
  assert(Valid_Num(a) == false);
  strcpy(a -> str[9], "3.2422.2");
  a -> cw = 9;
  assert(Valid_Num(a) == false);
  strcpy(a -> str[9], "3.2.2");
  a -> cw = 9;
  assert(Valid_Num(a) == false);

  /*testing Valid_Varnum*/
  strcpy(a -> str[0], "6");
  a -> cw = 0;
  assert(Valid_Varnum(a) == true);
  strcpy(a -> str[1], "A");
  a -> cw = 1;
  assert(Valid_Varnum(a) == true);
  strcpy(a -> str[2], "0.5");
  a -> cw = 2;
  assert(Valid_Varnum(a) == true);
  strcpy(a -> str[3], "58534");
  a -> cw = 3;
  assert(Valid_Varnum(a) == true);
  strcpy(a -> str[4], "Z");
  a -> cw = 4;
  assert(Valid_Varnum(a) == true);
  strcpy(a -> str[5], "f");
  a -> cw = 5;
  assert(Valid_Varnum(a) == false);
  strcpy(a -> str[6], ".4");
  a -> cw = 6;
  assert(Valid_Varnum(a) == false);
  strcpy(a -> str[7], "]");
  a -> cw = 7;
  assert(Valid_Varnum(a) == false);
  strcpy(a -> str[8], "4A");
  a -> cw = 8;
  assert(Valid_Varnum(a) == false);
  strcpy(a -> str[9], "A7");
  a -> cw = 9;
  assert(Valid_Varnum(a) == false);

/*testing Valid_Polish*/
/*test simple polish*/
strcpy(a -> str[0], "A");
strcpy(a -> str[1], "543");
strcpy(a -> str[2], "/");
strcpy(a -> str[3], ";");
a -> cw = 0;
assert(Valid_Polish(a) == true);

/*bad polish but should pass as follows grammar*/
strcpy(a -> str[0], "B");
strcpy(a -> str[1], "*");
strcpy(a -> str[2], "0.7");
strcpy(a -> str[3], "5");
strcpy(a -> str[4], "U");
strcpy(a -> str[5], ";");

a -> cw = 0;
assert(Valid_Polish(a) == true);

strcpy(a -> str[0], "B");
strcpy(a -> str[1], "B");
strcpy(a -> str[2], "0.7");
strcpy(a -> str[3], "*");
strcpy(a -> str[4], "+");
strcpy(a -> str[5], ";");

a -> cw = 0;
assert(Valid_Polish(a) == true);

/*testing for bad var*/
strcpy(a -> str[0], "a");
strcpy(a -> str[1], "5");
strcpy(a -> str[2], "/");
strcpy(a -> str[3], ";");

a -> cw = 0;
assert(Valid_Polish(a) == false);

/*testing for bad var*/
strcpy(a -> str[0], "6");
strcpy(a -> str[1], "AA");
strcpy(a -> str[2], "/");
strcpy(a -> str[3], ";");

a -> cw = 0;
assert(Valid_Polish(a) == false);

/*testing for bad num*/
strcpy(a -> str[0], "A");
strcpy(a -> str[1], ".5");
strcpy(a -> str[2], "/");
strcpy(a -> str[3], ";");

a -> cw = 0;
assert(Valid_Polish(a) == false);

/*testing for no closing semi colon*/
strcpy(a -> str[0], "B");
strcpy(a -> str[1], "*");
strcpy(a -> str[2], "0.7");
strcpy(a -> str[3], "5");
strcpy(a -> str[4], "U");
strcpy(a -> str[5], "FD");

a -> cw = 0;
assert(Valid_Polish(a) == false);

/*testing for bad char*/
strcpy(a -> str[0], "B");
strcpy(a -> str[1], "*");
strcpy(a -> str[2], "0.7");
strcpy(a -> str[3], "[");
strcpy(a -> str[4], ";");

a -> cw = 0;
assert(Valid_Polish(a) == false);

/*testing set*/
/*example of a good set*/
strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "5");
strcpy(a -> str[4], "6");
strcpy(a -> str[5], "+");
strcpy(a -> str[6], ";");

a -> cw = 0;
assert(Valid_Set(a) == true);

/*example of a good set*/
strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "Z");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "B");
strcpy(a -> str[4], "6");
strcpy(a -> str[5], "+");
strcpy(a -> str[6], ";");

a -> cw = 0;
assert(Valid_Set(a) == true);

/*example of a bad set = not :=*/
strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "=");
strcpy(a -> str[3], "5");
strcpy(a -> str[4], "6");
strcpy(a -> str[5], "+");
strcpy(a -> str[6], ";");

a -> cw = 0;
assert(Valid_Set(a) == false);

/*example of a bad set little a*/
strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "a");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "5");
strcpy(a -> str[4], "6");
strcpy(a -> str[5], "+");
strcpy(a -> str[6], ";");

a -> cw = 0;
assert(Valid_Set(a) == false);

/*example of a bad set no closing ; to polish*/
strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "5");
strcpy(a -> str[4], "6");
strcpy(a -> str[5], "+");
strcpy(a -> str[6], "5");

a -> cw = 0;
assert(Valid_Set(a) == false);

/*testing Valid_Fd*/
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "A");
a -> cw = 0;
assert(Valid_Fd(a) == true);
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "5");
a -> cw = 0;
assert(Valid_Fd(a) == true);
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "-5");
a -> cw = 0;
assert(Valid_Fd(a) == true);
strcpy(a -> str[0], "Fd");
strcpy(a -> str[1], "4");
a -> cw = 0;
assert(Valid_Fd(a) == false);
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "-B");
a -> cw = 0;
assert(Valid_Fd(a) == false);
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "a");
a -> cw = 0;
assert(Valid_Fd(a) == false);
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], ".5");
a -> cw = 0;
assert(Valid_Fd(a) == false);

/*testing Valid_Lt*/
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "A");
a -> cw = 0;
assert(Valid_Lt(a) == true);
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "5");
a -> cw = 0;
assert(Valid_Lt(a) == true);
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "-5");
a -> cw = 0;
assert(Valid_Lt(a) == true);
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "-A");
a -> cw = 0;
assert(Valid_Lt(a) == false);
strcpy(a -> str[0], "Lt");
strcpy(a -> str[1], "4");
a -> cw = 0;
assert(Valid_Lt(a) == false);
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "a");
a -> cw = 0;
assert(Valid_Lt(a) == false);
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], ".5");
a -> cw = 0;
assert(Valid_Lt(a) == false);

/*testing Valid_Rt*/
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "A");
a -> cw = 0;
assert(Valid_Rt(a) == true);
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "5");
a -> cw = 0;
assert(Valid_Rt(a) == true);
strcpy(a -> str[0], "Rt");
strcpy(a -> str[1], "4");
a -> cw = 0;
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "-5");
a -> cw = 0;
assert(Valid_Rt(a) == true);
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "-S");
a -> cw = 0;
assert(Valid_Rt(a) == false);
assert(Valid_Rt(a) == false);
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "a");
a -> cw = 0;
assert(Valid_Rt(a) == false);
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], ".5");
a -> cw = 0;
assert(Valid_Rt(a) == false);

/*testing Valid_Do*/
strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "1");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "7");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "}");
a -> cw = 0;
assert(Valid_Do(a) == true);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "A");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "B");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "}");
a -> cw = 0;
assert(Valid_Do(a) == true);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "5");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "-9");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "}");
a -> cw = 0;
assert(Valid_Do(a) == true);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "B");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "0.06");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "B");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "}");
a -> cw = 0;
assert(Valid_Do(a) == true);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "1");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "A");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "B");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "}");
a -> cw = 0;
assert(Valid_Do(a) == false);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "B");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "a");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "B");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "}");
a -> cw = 0;
assert(Valid_Do(a) == false);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "B");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "A");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "B");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "!");
a -> cw = 0;
assert(Valid_Do(a) == false);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "B");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "A");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], ".06");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "}");
a -> cw = 0;
assert(Valid_Do(a) == false);

/*testing Valid_Instruct*/
/*limited testing as you are just testing the smaller\
functions but wanted to make sure it all ran*/
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "B");
a -> cw = 0;
assert(Valid_Instruct(a) == true);

strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "0");
a -> cw = 0;
assert(Valid_Instruct(a) == true);

strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "9");
a -> cw = 0;
assert(Valid_Instruct(a) == true);

strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "Z");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "B");
strcpy(a -> str[4], "6");
strcpy(a -> str[5], "+");
strcpy(a -> str[6], ";");

a -> cw = 0;
assert(Valid_Instruct(a) == true);

strcpy(a -> str[0], "FD");
strcpy(a -> str[1], ".908");

a -> cw = 0;
assert(Valid_Instruct(a) == false);

strcpy(a -> str[4], "rT");
strcpy(a -> str[5], "0.06");
a -> cw = 0;
assert(Valid_Instruct(a) == false);

strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "Z");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "B");
strcpy(a -> str[4], "6");
strcpy(a -> str[5], "+");
strcpy(a -> str[6], "}");

a -> cw = 0;
assert(Valid_Instruct(a) == false);


/*testing for instruct list*/
/*testing short pre programed ttl files*/
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "LT");
strcpy(a -> str[3], "786");
strcpy(a -> str[4], "}");

a -> cw = 0;
assert(Valid_Instructlst(a) == true);

strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "S");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "786");
strcpy(a -> str[4], ";");
strcpy(a -> str[5], "FD");
strcpy(a -> str[6], "A");
strcpy(a -> str[7], "LT");
strcpy(a -> str[8], "786");
strcpy(a -> str[9], "}");

a -> cw = 0;
assert(Valid_Instructlst(a) == true);

strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "S");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "786");
strcpy(a -> str[4], ";");
strcpy(a -> str[5], "FD");
strcpy(a -> str[6], "A");
strcpy(a -> str[7], "LT");
strcpy(a -> str[8], "786");
strcpy(a -> str[9], "}");

a -> cw = 0;
assert(Valid_Instructlst(a) == true);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "G");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "786");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "4");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "LT");
strcpy(a -> str[8], "786");
strcpy(a -> str[9], "}");
strcpy(a -> str[10], "}");
/*this extra closing bracket is here as it is needed to\
finish list, the starting bracket for this is checked for \
in main hence why its not in this test*/

a -> cw = 0;
assert(Valid_Instructlst(a) == true);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "G");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "786");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "4");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "LT");
strcpy(a -> str[8], "786");
strcpy(a -> str[9], "}");
strcpy(a -> str[10], "!");

a -> cw = 0;
assert(Valid_Instructlst(a) == false);

/*testing End_Clear*/
/*this is mainly tested in the Par_Main testing*/

strcpy(a -> str[0], "");
a -> cw = 0;
assert(End_Clear(a) == true);
strcpy(a -> str[0], " ");
a -> cw = 0;
assert(End_Clear(a) == false);


/*testing for Par_main->*/
/*the only real testing we need to do here is to check that\
the functions takes and parseres parses a simple function\
as the rest is tested above and black box testing will\
cover the rest. the empty "" are on the end of each file\
so that they program can test if theres anything after the\
closing brackets*/

strcpy(a -> str[0], "{");
strcpy(a -> str[1], "LT");
strcpy(a -> str[2], "45");
strcpy(a -> str[3], "}");
strcpy(a -> str[4], "");
a -> cw = 0;
assert(Par_Main(a) == true);

strcpy(a -> str[0], "{");
strcpy(a -> str[1], "DO");
strcpy(a -> str[2], "G");
strcpy(a -> str[3], "FROM");
strcpy(a -> str[4], "6");
strcpy(a -> str[5], "TO");
strcpy(a -> str[6], "18");
strcpy(a -> str[7], "{");
strcpy(a -> str[8], "}");
strcpy(a -> str[9], "}");
strcpy(a -> str[10], "");
a -> cw = 0;
assert(Par_Main(a) == true);

strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "45");
strcpy(a -> str[2], "}");
strcpy(a -> str[3], "");

a -> cw = 0;
assert(Par_Main(a) == false);

strcpy(a -> str[0], "{");
strcpy(a -> str[1], "DO");
strcpy(a -> str[2], "G");
strcpy(a -> str[3], "FROM");
strcpy(a -> str[4], "6");
strcpy(a -> str[5], "TO");
strcpy(a -> str[6], "18");
strcpy(a -> str[7], "{");
strcpy(a -> str[8], "LT");
strcpy(a -> str[8], "5");
strcpy(a -> str[9], "");
a -> cw = 0;
assert(Par_Main(a) == false);

strcpy(a -> str[0], "{");
strcpy(a -> str[1], "DO");
strcpy(a -> str[2], "G");
strcpy(a -> str[3], "FROM");
strcpy(a -> str[4], "6");
strcpy(a -> str[5], "TO");
strcpy(a -> str[6], "18");
strcpy(a -> str[7], "{");
strcpy(a -> str[8], "}");
strcpy(a -> str[9], "}");
strcpy(a -> str[9], "");
a -> cw = 0;
assert(Par_Main(a) == false);

n2dfree((void**)a -> str, a -> size + BUFF);
free(a);
}
