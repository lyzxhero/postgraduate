# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Element{
    int id;
    char name[20];
    struct Element * prevElement;
    struct Element * nextElement;
}Element,*PElement;

typedef struct LinkedStack{
       PElement top;
       PElement bottom;
       int size;
}LinkedStack,*PLinkedStack;

PElement initElement(int * id,char name[20]);
void showElement(PElement pEle);
PLinkedStack initLinkedStack();
PLinkedStack pushStack(PLinkedStack pStack,PElement ele);
void showStack(PLinkedStack pStack);
char checkStack(PLinkedStack pStack);
PElement pop(PLinkedStack pStack);


int main(void){
    int seq = 1;

    PLinkedStack pStack = initLinkedStack();
    PElement ele1  = initElement(&seq,"李耀辉");
    pushStack(pStack,ele1);
    PElement ele2  = initElement(&seq,"唐昊");
    pushStack(pStack,ele2);

    PElement ele3  = initElement(&seq,"蓝银皇");
    pushStack(pStack,ele3);

    PElement ele4  = initElement(&seq,"昊天锤");
    pushStack(pStack,ele4);


    PElement pele = pop(pStack);
    showStack(pStack);
    printf("\n");
    showElement(pele);
}

PElement initElement(int * id,char name[20]){
    PElement ele = (PElement)malloc(sizeof(Element));
    ele->id=*id;
    *id=*id+1;
    strcpy(ele->name,name);
    ele->nextElement=NULL;
    ele->prevElement=NULL;
    return ele;
}

void showElement(PElement pEle){
    printf("id=%d,name=%s\n",pEle->id,pEle->name);
}

PLinkedStack initLinkedStack(){
    PLinkedStack pStack = (PLinkedStack)malloc(sizeof(LinkedStack));

    int seq = -1;
    PElement pHead = initElement(&seq,"栈头");

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

    while(-1 != tempElement->id){
        printf("id=[%d],name=[%s]\n",tempElement->id,tempElement->name);
        tempElement = tempElement->prevElement;
    }
}

char checkStack(PLinkedStack pStack){
    if(NULL == pStack || -1 == pStack->top->id){
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