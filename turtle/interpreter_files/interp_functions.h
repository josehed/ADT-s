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

bool Do_Move(Program *p);

bool Extract_Num(Program *p);

bool Turn_Left(Program *p);

bool Turn_Right(Program *p);

bool Do_Do(Program *p, double from, double to);

void Set_Var(Program *p);

bool Do_Polish(Program *p);

bool Do_Set(Program *p);

void Init_Prog(char *arg, Program *p);
