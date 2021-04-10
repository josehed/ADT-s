void test(void);
/*used to make all strings valid*/
bool Par_Main(Program *p);
/*checks to make sure operator is valid*/
bool Valid_Op(Program *p);
/*checks to make sure var is valid*/
bool Valid_Var(Program *p);
/*checks to make sure Varnum is valid*/
bool Valid_Varnum(Program *p);
/*checks for valid polish*/
bool Valid_Polish(Program *p);
/*checks to make sure number is valid*/
bool Valid_Num(Program *p);
/*check to make sure set is valid*/
bool Valid_Set(Program *p);
/*make sure the do is valid*/
bool Valid_Do(Program *p);

bool Valid_Fd(Program *p);

bool Valid_Lt(Program *p);

bool Valid_Rt(Program *p);

bool Valid_Instruct(Program *p);

bool Valid_Instructlst(Program *p);
/*checks to make sure theres nothing after the closing }*/
bool End_Clear(Program *p);
