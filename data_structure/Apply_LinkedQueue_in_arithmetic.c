# include <stdio.h>
# include <string.h>
# include <stdlib.h>


/**
 * 
 * @author hero.li
 * @date 2021-01-06
 * 作用:
 *    1、将中置表达式转换为后置表达式
 *    2、得出后置表达式的计算结果
 * 
 **/

typedef struct Element{
    int isNumber;
    int number;
    int isOperator;
    //可能是操作符也可能是括号
    char context;
    struct Element * prevElement;
    struct Element * nextElement;
}Element,*PElement;

typedef struct LinkedStack{
       PElement top;
       PElement bottom;
       int size;
}LinkedStack,*PLinkedStack;

typedef enum OperatorType{
    SmallLeftBracket = 100,
    SmallRightBracket = 1000,   
    MiddleLeftBracket = 200,
    MiddleRightBracket = 2000,
    BigLeftBracket = 300,
    BigRightBracket = 3000,
    PlusOrSubstract = 2,
    MultipleOrDivide = 3,
    Number=4,
    End=0
}OperatorType;

PElement initElement(int isNumber,int number,int isOperator,char context);
void showElement(PElement pEle);
PLinkedStack initLinkedStack();
PLinkedStack pushStack(PLinkedStack pStack,PElement ele);
void showStack(PLinkedStack pStack);
void addArr(char arr[],char targetItem);
char checkStack(PLinkedStack pStack);
PElement pop(PLinkedStack pStack);
PElement seeTopElement(PLinkedStack pStack);
OperatorType getOperatorType(char item);
void expressConvert(PLinkedStack pStack,char express[]);
void copyValueToArr(char originArr[],char targetArr[]);
void showArr(char arr[]);
void fillCharArray(char arr[]);
void fillCharArrayPartly(char arr[],int vaildLength);
int getArrayVaildLength(char arr[]);



int main(void){

    // char exp[28] =  {'(','(','1','5','/','(','7','-','(','1','+','1',')',')',')','*','3',')','-','(','2','+','(','1','+','1',')',')'};

    int vaildLen = 9;
    char exp[100] = {'5','+','4','*','3','+','2','*','4'};
    fillCharArrayPartly(exp,9);
    PLinkedStack pStack = initLinkedStack();
    expressConvert(pStack,exp);
    showArr(exp);
}

/**
 * 把中置表达式转换为后置表达式
 * PLinkedStack pStack 链表
 * char express[30] 表达式字符数组
 * int vaildLen 数组的有效长度
 *    eg:
 *       char exp1[30] = {'1','+','2'}此数组的有效长度为3
 *       char exp2[30] = {'2','+','3','-','7'}此数组的有效长度为5
 * 此方法能解析中置表达式的最大长度默认为100
 * 
 **/ 
void expressConvert(PLinkedStack pStack,char express[]){

    char tempExp[100];
    fillCharArray(tempExp);
    int vaildLen = getArrayVaildLength(express);

    for (int i = 0; i < vaildLen; i++){
        char item = express[i];

        enum OperatorType type = getOperatorType(item);
        printf("操作类型是:%d,item=%c\n",type,item);
        if(Number == type){
            //第一个数字的情况
            if(i == 0){
                printf("    i=%d直接入栈\n",i);
                addArr(tempExp,item);
                continue;
            }


            //中间数字的情况
            if(0 != i && i != vaildLen - 1){
                char nextItem = express[i+1];
                OperatorType nextType = getOperatorType(nextItem);

                char prevItem = seeTopElement(pStack)->context;
                OperatorType prevType = getOperatorType(prevItem);

                printf("    i=%d,前一个操作符是%c,下一个操作符是%c\n",i,prevItem,nextItem);
                addArr(tempExp,item);

                if(nextType <= prevType){
                    char operator = pop(pStack)->context;
                    addArr(tempExp,operator);
                }
                continue;
            }

            //最后一个数字的情况
            if(i == vaildLen - 1){
                printf("    第一个数字的情况:i=%d,pStack->size=%d\n",i,pStack->size);
                addArr(tempExp,item);
                if(0 != pStack->size){
                    for (int i = 0; i < pStack->size; i++){
                        addArr(tempExp,pop(pStack)->context);
                    }
                }
                continue;
            }

        }

        // //如果是操作符 要么就入栈 要么就根据条件判断
        if(PlusOrSubstract == type || MultipleOrDivide == type){
            printf("    操作符%c ",item);
            if(0 == pStack->size){
                printf(" 栈为空入栈 \n");
                pushStack(pStack,initElement(0,0,1,item));
                continue;
            }else{
                char prevOperator = seeTopElement(pStack)->context;
                OperatorType prevType = getOperatorType(prevOperator);
                printf("  前一个操作符是%c ",prevOperator);
                if(type > prevType){
                    printf(" 由于前一个操作符是%c 所以把%c入栈\n",prevOperator,item);
                    pushStack(pStack,initElement(0,0,1,item));
                }else{
                    char operator = pop(pStack)->context;
                    addArr(tempExp,operator);
                }
            }
        }
    }

    copyValueToArr(tempExp,express);
    return ;
}


int getArrayVaildLength(char arr[]){
    for (int i = 0; i < 100; i++){
        if('A' == arr[i]){
            return i;
        }
    }
    return 100;
}


void showArr(char arr[]){
    int vaildLength = getArrayVaildLength(arr);
    for (int i = 0; i < vaildLength; i++){
        printf(" %c ",arr[i]);
    }
}

void copyValueToArr(char originArr[],char targetArr[]){
    int originLength = getArrayVaildLength(originArr);
    for (int i = 0; i < 100; i++){
        if(i < originLength){
            targetArr[i] = originArr[i];
        }else{
            targetArr[i] = 'A';
        }
    }
}

void fillCharArrayPartly(char arr[],int vaildLength){
    int len = 100;
    for (int i = 0; i < len; i++){
        if(i >= vaildLength){
            arr[i] = 'A';
        }
    }
}

void fillCharArray(char arr[]){
    int len = 100;
    for (int i = 0; i < len; i++){
            arr[i]='A';
    }
}

/**
 * 添加字符到字符数组中
 * 添加的位置是从头到尾数第一个为A的位置
 * 
 * 
 * 
 * 
 **/ 
void addArr(char arr[],char targetItem){
    int len = 100;
    for(int i = 0; i < len; i++){
        if('A' == arr[i]){
            arr[i]=targetItem;
            return;
        }
    }
}


/**
 * 获取炒作类型
 * 100  表示(
 * 1000 表示)
 * 200  表示[
 * 2000 表示]
 * 300  表示{
 * 3000 表示}
 * 2 表示+或者-
 * 3 表示*或者/
 * 4 表示操作数
 * 
 **/
OperatorType getOperatorType(char item){
    if('(' == item ){
        return SmallLeftBracket;
    }

    if(')' == item ){
        return SmallRightBracket;
    }
    
    if('[' == item ){
        return MiddleLeftBracket;
    }

    if(']' == item ){
        return MiddleRightBracket;
    }

    if('{' == item ){
        return BigLeftBracket;
    }

    if('}' == item ){
        return BigRightBracket;
    }

    if('+' == item || '-' == item){
        return PlusOrSubstract;
    }

    if('*' == item || '/' == item){
        return MultipleOrDivide;
    }

    if('A' == item){
        return End;
    }

    return Number;
}

// enum OperatorType charToEnum(char item){
//     if(){

//     }
// }

void showStack(PLinkedStack pStack){
    if(NULL == pStack){
        printf("此栈为空!无法show");
        return;
    }

    if(pStack->size == 0){
        printf("此栈为一个空栈！也无法show!");
        return;
    }

    PElement tempElement = pStack->top;

    while(NULL != tempElement->prevElement){
        showElement(tempElement);
        tempElement = tempElement->prevElement;
    }
}


/**
 *  初始化一个元素
 *  isNumber和isOperator:1表示是
 * 
 **/ 
PElement initElement(int isNumber,int number,int isOperator,char context){
    PElement ele = (PElement)malloc(sizeof(Element));
    ele->isNumber=isNumber;
    ele->number=number;
    ele->isOperator=isOperator;
    ele->context=context;
    ele->nextElement=NULL;
    ele->prevElement=NULL;
    return ele;
}

void showElement(PElement pEle){
    if(1 == pEle->isNumber){
        printf(" %d ",pEle->number);
        return;
    }

    if(1 == pEle->isOperator){
        printf(" %c ",pEle->context);
        return;
    }
}

PLinkedStack initLinkedStack(){
    PLinkedStack pStack = (PLinkedStack)malloc(sizeof(LinkedStack));

    int seq = -1;
    PElement pHead = initElement(0,0,0,' ');

    pStack->top = pHead;
    pStack->bottom = pHead;
    pStack->size = 0;
    pHead->nextElement=NULL;
    
    return pStack;
}

PLinkedStack pushStack(PLinkedStack pStack,PElement ele){
    pStack->top->nextElement=ele;
    ele->prevElement=pStack->top;

    pStack->top=ele;
    ele->nextElement=NULL;
    pStack->size++;

    return pStack;
}

char checkStack(PLinkedStack pStack){
    if(NULL == pStack){
        printf("这是一个空栈!不给展示！");
        return 'F';
    }
    return 'M';
}

PElement pop(PLinkedStack pStack){
    char checkResult = checkStack(pStack);
    if('F' == checkResult){
        return NULL;
    }

    PElement pele = pStack->top;
    pStack->top=pele->prevElement;

    pele->prevElement->nextElement=NULL;
    pele->prevElement=NULL;

    return pele;
}


PElement seeTopElement(PLinkedStack pStack){
    char checkResult = checkStack(pStack);
    if('F' == checkResult){
        return NULL;
    }

    PElement pele = pStack->top;
    return pele;
}