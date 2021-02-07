# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/**
 * 
 * @author hero.li
 * @date 2021-01-06
 * 作用:栈在括号匹配中的应用
 * 基本思路:
 *     对char[]中的字符item循环逐个检查，如果item=左括号eg:(、[、｛等则入栈
 *     若item=右括号eg:)、]、}等则把栈定的字符TailItem拿出来
 *     如果刚好能凑成一对则进行下一项，若不能则返回false
 *     完成整个for循环，若没有返回则该字符数组匹配成功
 *
 * */
typedef struct Element{
    int id;
    char name;
    struct Element * prevElement;
    struct Element * nextElement;
}Element,*PElement;

typedef struct LinkedStack{
       PElement top;
       PElement bottom;
       int size;
}LinkedStack,*PLinkedStack;

PElement initElement(int * id,char name);
void showElement(PElement pEle);
PLinkedStack initLinkedStack();
PLinkedStack pushStack(PLinkedStack pStack,PElement ele);
void showStack(PLinkedStack pStack);
char checkStack(PLinkedStack pStack);
PElement pop(PLinkedStack pStack);
int bracketsChecker(PLinkedStack pStack,char bracketsArr[],int len);


int main(void){
    int seq = 1;
    PLinkedStack pStack = initLinkedStack();
    char bracketsArr[] = {'(','(','(',')',')','[','{','(',']','}',']',')'};

    int result = bracketsChecker(pStack,bracketsArr,12);
    printf("result=%s\n",result == 1 ? "匹配成功":"匹配失败");
}


//1代表匹配 否则代表失败
int bracketsChecker(PLinkedStack pStack,char bracketsArr[],int len){
    if(len % 2 != 0){
        return 0;
    }

    for(int i=0;i<len;i++){
        char item = bracketsArr[i];
        if(item == '(' || item == '[' || item =='{'){
            int seq = 1;
            pushStack(pStack,initElement(&seq,item));
        }else{
            if(0 == pStack->size){
                return 0;
            }
            
            PElement tailEle = pop(pStack);
            char tailItem = tailEle->name;
            if(
                (item == ')' && tailItem != '(') || 
                (item == ']' && tailItem != '[') ||
                (item == '}' && tailItem != '{')
              ){
                return 0;
            }
        }
    }
    return 1;
}



PElement initElement(int * id,char name){
    PElement ele = (PElement)malloc(sizeof(Element));
    if(NULL == id){
        ele->id=-1;
    }else{
        ele->id=*id;
        *id=(*id+1);
    }
    
    ele->name=name;
    ele->nextElement=NULL;
    ele->prevElement=NULL;
    return ele;
}

void showElement(PElement pEle){
    printf("id=%d,name=%c\n",pEle->id,pEle->name);
}

PLinkedStack initLinkedStack(){
    PLinkedStack pStack = (PLinkedStack)malloc(sizeof(LinkedStack));
    PElement pHead = initElement(NULL,'N');
    pStack->top = pHead;
    pStack->bottom = pHead;
    pStack->size = 0;
    pHead->nextElement=NULL;
    pHead->prevElement=NULL;
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
        printf("id=[%d],name=[%c]\n",tempElement->id,tempElement->name);
        // if(NULL != tempElement){
            tempElement = tempElement->prevElement;
        // }
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
    pStack->size = pStack->size-1;

    return pele;
}