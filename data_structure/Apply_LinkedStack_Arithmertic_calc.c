# include <stdio.h>
# include <string.h>
# include <stdlib.h>


/**
 * 
 * @author hero.li
 * @date 2021-01-07
 * 作用:
 *   得出后置表达式的计算结果
 * 
 **/

typedef struct Element{
    int number;
    struct Element * prevElement;
    struct Element * nextElement;
}Element,*PElement;

typedef struct LinkedStack{
       PElement top;
       PElement bottom;
       int size;
}LinkedStack,*PLinkedStack;

PElement initElement(int number);
void showElement(PElement pEle);
PLinkedStack initLinkedStack();
PLinkedStack pushStack(PLinkedStack pStack,PElement ele);
void showStack(PLinkedStack pStack);
char checkStack(PLinkedStack pStack);
PElement pop(PLinkedStack pStack);
PElement seeTopElement(PLinkedStack pStack);
int calcExp(PLinkedStack pStack,char exp[],int expLength);


int main(void){
    char exp[9] =  {'5','4','3','*','2','4','*','+','+'};
    PLinkedStack pStack = initLinkedStack();
    int result = calcExp(pStack,exp,9);
    printf("result=%d\n",result);
}


int calcExp(PLinkedStack pStack,char exp[],int expLength){
    for (int i = 0; i < expLength; i++){
        char item = exp[i];
        printf("item=%c\n",item);
        if('+' != item && '-' != item && '*' != item && '/' != item){
            int intItem = atoi(&item);
            pushStack(pStack,initElement(intItem));
            printf("        %d入栈,size=%d\n",intItem,pStack->size);
            continue;
        }

        int secondVal = pop(pStack)->number;
        int firstVal  = pop(pStack)->number;
        int result = 0;
        if('+' == item){
            result = firstVal+secondVal;
        }

        if('-' == item){
            result = firstVal - secondVal;
        }

        if('*' == item){
            result = firstVal * secondVal;
        }

        if('/' == item){
            result = firstVal/secondVal;
        }

        printf("firstVal=%d secondVal=%d,result=%d\n",firstVal,secondVal,result);
        pushStack(pStack,initElement(result));
    }

    return pop(pStack)->number;
}

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
 **/ 
PElement initElement(int number){
    PElement ele = (PElement)malloc(sizeof(Element));
    ele->number=number;
    ele->nextElement=NULL;
    ele->prevElement=NULL;
    return ele;
}

void showElement(PElement pEle){
        printf(" %d ",pEle->number);
}

PLinkedStack initLinkedStack(){
    PLinkedStack pStack = (PLinkedStack)malloc(sizeof(LinkedStack));

    int seq = -1;
    PElement pHead = initElement(0);

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
    pStack->size = pStack->size + 1;
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

    pStack->size = pStack->size - 1;

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