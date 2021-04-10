
/*some testing from the parser has been carried over and\
the pure interptiter testing starts line 324*/

#include "specific.h"
#include "interp_functions.h"

void test(void){

  Program* a = calloc(1, sizeof(Program));
  a -> cw = 0;
  a -> size = TESTARR;
  a -> x = 0;
  a -> y = 0;
  a -> angle = 0;
  /*buff is added so that the End_Clear check wont go out\
  of bounds*/
  a -> str = (char**)n2dcalloc(a -> size + BUFF, MAXEXPR, sizeof(char*));
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
a -> var_set[1] = true;
a -> var[1] = 10;
strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "5");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "B");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "}");
a -> cw = 0;
assert(Valid_Do(a) == true);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "-5");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "9");
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
a -> var_set[1] = true;
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
strcpy(a -> str[1], "Y");
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
strcpy(a -> str[1], "Y");
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
strcpy(a -> str[1], "A");
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
strcpy(a -> str[1], "A");
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
strcpy(a -> str[3], "1");
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
strcpy(a -> str[3], "3");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "4");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "LT");
strcpy(a -> str[8], "786");
strcpy(a -> str[9], "}");
strcpy(a -> str[10], "!");
/*missing end bracket*/
a -> cw = 0;
assert(Valid_Instructlst(a) == false);

strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "G");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "8");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "4");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "LT");
strcpy(a -> str[8], "786");
strcpy(a -> str[9], "}");
strcpy(a -> str[10], "}");
/*firts number bigger than second*/
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
/*


interpriter testing starts here


*/
a -> var_set[0] = false; /*setting A back to false*/
a -> var[1] = 7.99183; /*setting var B to 7.99183*/
a -> var_set[1] = true; /*shows var is valid*/
/*test Extract_Num*/
strcpy(a -> str[0], "B");
a -> cw = 1;
Extract_Num(a);
assert(fabs(a -> dist_ang - 7.99183) < 0.000001);
/*checking that the set functions works*/
a -> var_set[1] = false;
strcpy(a -> str[0], "B");
a -> cw = 1;
assert(!Extract_Num(a));

strcpy(a -> str[0], "10");
a -> cw = 1;
Extract_Num(a);
assert(fabs(a -> dist_ang - 10) < 0.000001);

strcpy(a -> str[0], "-10");
a -> cw = 1;
Extract_Num(a);
assert(fabs(a -> dist_ang - -10) < 0.000001);

strcpy(a -> str[0], "-0.94");
a -> cw = 1;
Extract_Num(a);
assert(fabs(a -> dist_ang - -0.94) < 0.000001);

/*test Do_Move*/
a -> x = 0;
a -> y = 0;
a -> angle = 45;
a -> var[0] = 5; /*setting var A to 5*/
a -> var_set[0] = true; /*shows var is valid*/
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "A");
a -> cw = 2;
Do_Move(a);
assert(fabs(a -> x - 3.535534) < 0.000001);
assert(fabs(a -> y - 3.535534) < 0.000001);

a -> x = 0;
a -> y = 0;
a -> angle = 45;
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "10");
a -> cw = 2;
Do_Move(a);
assert(fabs(a -> x - 7.071068) < 0.000001);
assert(fabs(a -> y - 7.071068) < 0.000001);

a -> x = 3.535534;
a -> y = 3.535534;
a -> angle = 225;
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "5");
a -> cw = 2;
Do_Move(a);
assert(fabs(a -> x - 0) < 0.000001);
assert(fabs(a -> y - 0) < 0.000001);

/*testing Turn_left*/
a -> angle = 0;
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "-180");
a -> cw = 2;
Turn_Left(a);
assert(fabs(a -> angle - 180) < 0.000001);

a -> angle = 0;
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "-60.75");
a -> cw = 2;
Turn_Left(a);
assert(fabs(a -> angle - 60.75) < 0.000001);

a -> angle = 0;
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "-400");
a -> cw = 2;
Turn_Left(a);
assert(fabs(a -> angle - 40) < 0.000001);

a -> angle = 0;
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "400");
a -> cw = 2;
Turn_Left(a);
assert(fabs(a -> angle - 320) < 0.000001);

a -> angle = 0;
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "60.25");
a -> cw = 2;
Turn_Left(a);
assert(fabs(a -> angle - 299.75) < 0.000001);

strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "-180");
a -> cw = 2;
Turn_Left(a);
assert(fabs(a -> angle - 119.75) < 0.000001);

a -> var_set[6] = true;
a -> var[6] = 100;
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "G");
a -> cw = 2;
assert(Turn_Left(a));
assert(fabs(a -> angle - 19.75) < 0.000001);

a -> var_set[6] = false;
strcpy(a -> str[0], "LT");
strcpy(a -> str[1], "G");
a -> cw = 2;
assert(!Turn_Left(a));

/*testing Turn_Right*/
a -> angle = 0;
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "60.25");
a -> cw = 2;
Turn_Right(a);
assert(fabs(a -> angle - 60.25) < 0.000001);

a -> angle = 0;
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "-90");
a -> cw = 2;
Turn_Right(a);
assert(fabs(a -> angle - 270) < 0.000001);

a -> angle = 0;
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "420.25");
a -> cw = 2;
Turn_Right(a);
assert(fabs(a -> angle - 60.25) < 0.000001);

a -> angle = 0;
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "-450");
a -> cw = 2;
Turn_Right(a);
assert(fabs(a -> angle - 270) < 0.000001);

a -> angle = 0;
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "-90");
a -> cw = 2;
Turn_Right(a);
assert(fabs(a -> angle - 270) < 0.000001);

strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "180");
a -> cw = 2;
Turn_Right(a);
assert(fabs(a -> angle - 90) < 0.000001);

/*these next two are just checking to make sure they\
set var extract works*/
a -> var_set[2] = true;
a -> var[2] = 100;
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "C");
a -> cw = 2;
assert(Turn_Right(a));
assert(fabs(a -> angle - 190) < 0.000001);

a -> var_set[0] = false;
strcpy(a -> str[0], "RT");
strcpy(a -> str[1], "A");
a -> cw = 2;
assert(!Turn_Right(a));

/*test RT, LT and FD together*/
a -> x = 0;
a -> y = 0;
a -> angle = 0;
a -> var_set[0] = true;
a -> var[0] = 90;
strcpy(a -> str[0], "FD");
strcpy(a -> str[1], "10");
strcpy(a -> str[2], "LT");
strcpy(a -> str[3], "A");
strcpy(a -> str[4], "FD");
strcpy(a -> str[5], "10");
strcpy(a -> str[6], "RT");
strcpy(a -> str[7], "A");
strcpy(a -> str[8], "RT");
strcpy(a -> str[9], "A");
strcpy(a -> str[10], "FD");
strcpy(a -> str[11], "10");
strcpy(a -> str[12], "}");
a -> cw = 0;
assert(Valid_Instructlst(a));
assert(fabs(a -> x - 10) < 0.000001);
assert(fabs(a -> y - 0) < 0.000001);

/*testing Set_Var*/
a -> var_set[0] = false; /*A has been set so have to reset*/
assert(a -> var_set[25] == false);
assert(a -> var_set[0] == false);
strcpy(a -> str[0], "Z");
a -> cw = 0;
Set_Var(a);
assert(a -> var_set[25] == true);
strcpy(a -> str[0], "A");
a -> cw = 0;
Set_Var(a);
assert(a -> var_set[0] == true);

/*testing Do_Do though Valid_Do*/
a -> x = 0;
a -> y = 0;
a -> angle = 0;
a -> var_set[0] = false;
a -> var[0] = 0;
strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "1");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "4");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "FD");
strcpy(a -> str[8], "10");
strcpy(a -> str[9], "LT");
strcpy(a -> str[10], "90");
strcpy(a -> str[11], "}");
a -> cw = 0;
assert(Valid_Do(a));
assert(fabs(a -> x - 0) < 0.000001);
assert(fabs(a -> y - 0) < 0.000001);

a -> x = 0;
a -> y = 0;
a -> angle = 0;
a -> var_set[0] = false;
a -> var[0] = 0;
strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "1");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "4");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "FD");
strcpy(a -> str[8], "A");
strcpy(a -> str[9], "}");
a -> cw = 0;
assert(Valid_Do(a));
assert(fabs(a -> x - 10) < 0.000001);

a -> x = 0;
a -> y = 0;
a -> angle = 0;
a -> var_set[0] = false;
a -> var[0] = 0;
a -> var_set[2] = true;
a -> var[2] = 1;
strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "C");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "4");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "FD");
strcpy(a -> str[8], "A");
strcpy(a -> str[9], "}");
a -> cw = 0;
assert(Valid_Do(a));
assert(fabs(a -> x - 10) < 0.000001);
assert(fabs(a -> var[2] - 1) < 0.000001);

a -> x = 0;
a -> y = 0;
a -> angle = 0;
a -> var_set[0] = false;
a -> var[0] = 0;
a -> var_set[2] = true;
a -> var[2] = 1;
strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "C");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "-8");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "FD");
strcpy(a -> str[8], "A");
strcpy(a -> str[9], "}");
a -> cw = 0;
assert(!Valid_Do(a));
/*cant start at a larger number than the end*/

a -> x = 0;
a -> y = 0;
a -> angle = 0;
a -> var_set[0] = false;
a -> var[0] = 0;
a -> var_set[2] = true;
a -> var[2] = 1;
strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "C");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "4");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "DO");
strcpy(a -> str[8], "B");
strcpy(a -> str[9], "FROM");
strcpy(a -> str[10], "1");
strcpy(a -> str[11], "TO");
strcpy(a -> str[12], "2");
strcpy(a -> str[13], "{");
strcpy(a -> str[14], "FD");
strcpy(a -> str[15], "10");
strcpy(a -> str[16], "RT");
strcpy(a -> str[17], "90");
strcpy(a -> str[18], "}");
strcpy(a -> str[19], "}");
a -> cw = 0;
assert(Valid_Do(a));
/*lower tolerance as after this many moves accuracy is\
lowwered*/
assert(fabs(a -> x) < 0.00001);

a -> x = 0;
a -> y = 0;
a -> angle = 0;
a -> var_set[0] = false;
a -> var[0] = 0;
strcpy(a -> str[0], "DO");
strcpy(a -> str[1], "A");
strcpy(a -> str[2], "FROM");
strcpy(a -> str[3], "F");
strcpy(a -> str[4], "TO");
strcpy(a -> str[5], "4");
strcpy(a -> str[6], "{");
strcpy(a -> str[7], "FD");
strcpy(a -> str[8], "A");
strcpy(a -> str[9], "}");
a -> cw = 0;
assert(!Valid_Do(a));
/*f is uninilitilized here*/
/*testing polish*/
strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "Z");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "10");
strcpy(a -> str[4], "5");
strcpy(a -> str[5], "-");
strcpy(a -> str[6], "10");
strcpy(a -> str[7], "+");
strcpy(a -> str[8], "2");
strcpy(a -> str[9], "*");
strcpy(a -> str[10], "3");
strcpy(a -> str[11], "/");
strcpy(a -> str[12], ";");
a -> cw = 3; /*these point to 3 as this will normally be\
handled by the Do_set*/
assert(Do_Polish(a));
assert(fabs(a -> dist_ang) - 10 < 0.000001);

strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "E");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "19");
strcpy(a -> str[6], ";");
a -> cw = 3;
assert(Do_Polish(a));
assert(fabs(a -> dist_ang) - 19 < 0.00001);

strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "Z");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "10");
strcpy(a -> str[4], "0");
strcpy(a -> str[5], "/");
strcpy(a -> str[6], ";");
a -> cw = 3;
assert(!Do_Polish(a));
/*cant devide by 0*/
/*testing Do_Set*/
a -> var_set[0] = true;
a -> var[0] = 12;
strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "C");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "A");
strcpy(a -> str[4], "2");
strcpy(a -> str[5], "/");
strcpy(a -> str[6], ";");
a -> cw = 6;
assert(Do_Set(a));
assert(fabs(a -> var[2] - 6) < 0.00001);

strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "Z");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "1");
strcpy(a -> str[4], "2");
strcpy(a -> str[5], "+");
strcpy(a -> str[6], ";");
a -> cw = 6;
assert(Do_Set(a));
assert(fabs(a -> var[25] - 3) < 0.00001);

strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "Z");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "1");
strcpy(a -> str[4], "+");
strcpy(a -> str[5], "2");
strcpy(a -> str[6], ";");
a -> cw = 6;
assert(!Do_Set(a));

strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "Z");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "1");
strcpy(a -> str[4], "2");
strcpy(a -> str[5], "+");
strcpy(a -> str[6], "6");
strcpy(a -> str[7], ";");
a -> cw = 7;
assert(!Do_Set(a));

strcpy(a -> str[0], "SET");
strcpy(a -> str[1], "Z");
strcpy(a -> str[2], ":=");
strcpy(a -> str[3], "+");
strcpy(a -> str[4], "1");
strcpy(a -> str[5], "2");
strcpy(a -> str[6], ";");
a -> cw = 6;
assert(!Do_Set(a));

strcpy(a -> str[0], "{");
strcpy(a -> str[1], "SET");
strcpy(a -> str[2], "U");
strcpy(a -> str[3], ":=");
strcpy(a -> str[4], "10");
strcpy(a -> str[5], "9");
strcpy(a -> str[6], "-");
strcpy(a -> str[7], ";");
strcpy(a -> str[8], "DO");
strcpy(a -> str[9], "A");
strcpy(a -> str[10], "FROM");
strcpy(a -> str[11], "1");
strcpy(a -> str[12], "TO");
strcpy(a -> str[13], "4");
strcpy(a -> str[14], "{");
strcpy(a -> str[15], "FD");
strcpy(a -> str[16], "U");
strcpy(a -> str[17], "}");
strcpy(a -> str[18], "}");
strcpy(a -> str[19], "");
a -> cw = 0;
a -> x = 0;
a -> y = 0;
a -> angle = 0;
assert(Par_Main(a));
assert(fabs(a -> x) - 4 < 0.000001);
assert(fabs(a -> y) < 0.000001);
n2dfree((void**)a -> str, a -> size + BUFF);
free(a);
}
