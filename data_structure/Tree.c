# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Node{
    int number;
    struct Node * leftNode;
    struct Node * rightNode;
}Node,*PNode;

typedef struct Element{
    PNode pNode;
    struct Element * nextElement;
    struct Element * prevElement;
}Element,*PElement;

PNode initNode(int number);
void preOrder(PNode node);
void showNode(PNode node);
void inOrder(PNode node);
void postOrder(PNode node);

typedef struct LinkedStack{
       PElement top;
       PElement bottom;
       int size;
}LinkedStack,*PLinkedStack;
PLinkedStack initLinkedStack();
PElement initElement(PNode node);
PLinkedStack pushStack(PLinkedStack pStack,PElement ele);
char checkStack(PLinkedStack pStack);
PElement pop(PLinkedStack pStack);
void inOrderNonRecursion(PNode root);



/**
 *                    0
 *               /        \
 *              10        9       
 *           /     \    /   \
 *          11     12  8    99
 *         /  \        
 *        4   21  
 **/ 
int main(void){
    PNode root = initNode(0);
    PNode node10 = initNode(10);
    PNode node9 = initNode(9);
    root->leftNode = node10;
    root->rightNode = node9;

    PNode node11 = initNode(11);
    PNode node12 = initNode(12);
    node10->leftNode = node11;
    node10->rightNode = node12;

    PNode node8 = initNode(8);
    PNode node99 = initNode(99);
    node9->leftNode = node8;
    node9->rightNode = node99;

    PNode node4 = initNode(4);
    PNode node21 = initNode(21);
    node11->leftNode = node4;
    node11->rightNode = node21;

    // preOrder(root);
    // inOrder(root);  //4  11  21  10  12  0  8  9  99
    // postOrder(root);
    inOrderNonRecursion(root); //4  11  21  10  12  0  8  9  99  4  11  10  0
}

void preOrder(PNode node){
    if(NULL != node){
        showNode(node);
        preOrder(node->leftNode);
        preOrder(node->rightNode);
    }
}


void inOrder(PNode node){
    if(NULL != node){
        inOrder(node->leftNode);
        showNode(node);
        inOrder(node->rightNode);
    }
}


void postOrder(PNode node){
    if(NULL != node){
        postOrder(node->leftNode);
        postOrder(node->rightNode);
        showNode(node);
    }
}


PNode initNode(int number){
    PNode node = (PNode)malloc(sizeof(Node));
    node->number=number;
    node->leftNode=NULL;
    node->rightNode=NULL;
    return node;
}

void showNode(PNode node){
    printf(" %d ",node->number);
}


/**
 * 中序遍历的非递归遍历形式(未完)//todo
 * 
 **/
void inOrderNonRecursion(PNode root){
    PLinkedStack pStack = initLinkedStack();
    PNode tempNode = root;
    while(NULL != tempNode || 0 != pStack->size){
        if(tempNode){
            pushStack(pStack,initElement(initNode(tempNode->number)));
            tempNode= tempNode->leftNode;
        }else{
            PElement pEle = pop(pStack);
            showNode(pEle->pNode);
            tempNode = pEle->pNode->rightNode;
        }
    }
}

PLinkedStack initLinkedStack(){
    PLinkedStack pStack = (PLinkedStack)malloc(sizeof(LinkedStack));
    PElement pHead = initElement(initNode(0));
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
    pStack->size = pStack->size + 1;
    return pStack;
}

PElement initElement(PNode node){
    PElement ele = (PElement)malloc(sizeof(Element));
    ele->pNode=node;
    ele->nextElement=NULL;
    ele->prevElement=NULL;
    return ele;
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