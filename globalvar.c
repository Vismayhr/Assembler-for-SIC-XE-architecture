# define type2 2
# define type3 3
# define MAX_SIZE 23    //Number of keywords stored in the hashtable

void RemoveMulSpaces();
void ConvertToLowerCase();
void InsertWithinRange(char *str,int i, int j,char *str2);
void InsertIntoErrorBuff(char *str);


struct labl{
char name[20];
unsigned int addr; 		 		
struct labl *link;
};

struct labl *labelIndex[10];

struct var{
char name[20];
char val[4];									
unsigned int addr;		 
struct var *link;
};

struct var *varIndex[10];

struct node{
char name[10];
char type[10];
char opcode[3];
int param;      //number of parameters expected
};


struct node cmdTable[] = {"addr","type2","90",2,
                            "clear","type2","B4",1,
                            "compr","type2","A0",2,
                            "divr","type2","9C",2,
                            "mulr","type2","98",2,
                            "shiftl","type2","A4",2,
                            "shiftr","type2","A8",2,		
                            "subr","type2","94",2,
                            "add","type3","18",1,
                            "and","type3","40",1,
                            "j","type3","3C",1,
                            "jeq","type3","30",1,
                            "jgt","type3","34",1,
                            "jlt","type3","38",1,
                            "lda","type3","00",1,
                            "ldch","type3","50",1,
                            "ldx","type3","04",1,
                            "rd","type3","D8",1,
                            "sta","type3","06",1,
                            "sub","type3","1C",1,
                            "wd","type3","DC",1};




struct var *globalVarStruct;
struct var *SearchVarStruct;
struct labl *globalLabelStruct;
struct labl *SearchLabelStruct;

FILE *fp;
//FILE *oc;
char buff1[5000];
char buff2[5000];
char buff3[5000];
//char objCode[5000];
char errorBuff[5000];
//char varLabErrorBuff[5000];
int endIndex;
int singlesize=0; //size of the buffer after removing multiple spaces. passed to buff2.
int buff1Index = 0,buff2Index=0,errorBuffIndex=0; //varLabErrorBuffIndex=0;
unsigned int memAddr = 0x1000;
int lineCount = 2;
char obj[7];						//stores the obj code for each line in binary


//char str1[20],str2[20],str3[20];



//Error messages:

char missingStart[40] = "START keyword is not mentioned.";
char missingEnd[40] = "END keyword is not mentioned.";
char unexpectedNewLine[50] = "Unexpected new line in code.";
char regError[40] = "Wrong usage of registers.";
char missingComma[40] = "The ',' operator is missing.";
char missingVar[40] = "Variable not declared";
char missingLabel[40] = "Label not declared"; 
char invalidKeyword[40] = "Not a recognised instruction or keyword";


//char lessStats[50] = "Too few statements in line: ";
//char excessStats[50] = "Too many statements in line: ";


