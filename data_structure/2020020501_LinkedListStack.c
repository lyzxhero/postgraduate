# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Element{
    short id;
    char content[32];
    struct Element * nextNode;
}Element,* PElement;


/**
 * 以链表的形式存储元素
 * bottom指向一个没有意义的栈底元素
 * top指向栈顶元素
 * size代表栈的长度
 * */
typedef struct LinkedStack{
    PElement top;
    PElement bottom;
    short size;
}LinkedStack,* PLinkedStack;

PLinkedStack initStack(void);
PElement initElement(void);
PElement createElement(short,char[32]);
short push(PLinkedStack,PElement);
PElement pop(PLinkedStack);
short treverseStack(PLinkedStack);
short size(PLinkedStack);

int main(void){
    PLinkedStack stack = initStack();

    PElement item1 = createElement(1,"李耀辉");
    push(stack,item1);

    PElement item2 = createElement(2,"肖露");
    push(stack,item2);

    PElement item3 = createElement(3,"李大宝");
    push(stack,item3);
    treverseStack(stack);

    PElement item = pop(stack);
    printf("[%d,%s]\n",item->id,item->content);
    printf("=======================\n");

    treverseStack(stack);

    printf("size=%d",size(stack));
    return 1;
};

/**
 * 需要销毁item吗？
 * 
 * */
PElement pop(PLinkedStack stack){
    PElement item = stack->top;
    stack->top = stack->top->nextNode;
    stack->size--;
    return item;
};

PElement initElement(void){
    PElement ele = (PElement)malloc(sizeof(Element));
    ele->id = -1;
    strcpy(ele->content,"无意义空节点");
    return ele;
}

PLinkedStack initStack(void){
    PLinkedStack stack = (PLinkedStack)malloc(sizeof(LinkedStack));
    stack->size = 0;
    PElement ele = initElement();
    stack->top = ele;
    stack->bottom = ele;
    return stack;
}

/**
 * 把新元素连接到链表的第一个元素头上
 * 然后top指针指向该新元素
 * 总长度加1
 * */
short push(PLinkedStack pstack,PElement item){
    item->nextNode = pstack->top;
    pstack->top = item;
    pstack->size++;
    return 1;
}

short size(PLinkedStack pstack){
    return pstack->size;
}

short treverseStack(PLinkedStack pstack){
    PElement bottom = pstack->bottom;
    PElement tempTop = pstack->top;

    while(tempTop != bottom){
        printf("[%d,",tempTop->id);
        printf("%s]\n",tempTop->content);
        tempTop = tempTop->nextNode;
    }
    return 1;
}

PElement createElement(short id,char content[32]){
    PElement ele = initElement();
    ele->id = id;
    strcpy(ele->content,content);
    return ele;
}