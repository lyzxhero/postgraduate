# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Element{
    struct Node * node;
    struct Element * prevElement;
    struct Element * nextElement;
}Element,*PElement;

typedef struct LinkedQueue{
       PElement head;
       PElement tail;
       int size;
}LinkedQueue,*PLinkedQueue;

typedef struct Node{
    int number;
    struct Node * leftNode;
    struct Node * rightNode;
}Node,*PNode;




PNode initNode(int number);
PElement initElement(PNode node);
PLinkedQueue initLinkedQueue();
void inQueue(PLinkedQueue pQueue,PElement pEle);
void showElement(PElement pEle);
char checkQueue(PLinkedQueue pQueue);
PElement outQueue(PLinkedQueue pQueue);
void levelOrder(PNode root);



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
   levelOrder(root);

}

void levelOrder(PNode root){
    PLinkedQueue pQueue = initLinkedQueue();
    inQueue(pQueue,initElement(root));

    while(0 != pQueue->size){
        PElement pEle = outQueue(pQueue);
        showElement(pEle);
        if(NULL != pEle->node->leftNode){
            inQueue(pQueue,initElement(pEle->node->leftNode));
        }
        if(NULL != pEle->node->rightNode){
            inQueue(pQueue,initElement(pEle->node->rightNode));
        }
    }
}


PNode initNode(int number){
    PNode node = (PNode)malloc(sizeof(Node));
    node->number=number;
    node->leftNode=NULL;
    node->rightNode=NULL;
    return node;
}


PElement initElement(PNode node){
    PElement ele = (PElement)malloc(sizeof(Element));
    ele->node=node;
    ele->nextElement=NULL;
    ele->prevElement=NULL;
    return ele;
}

PLinkedQueue initLinkedQueue(){
    PLinkedQueue pQueue = (PLinkedQueue)malloc(sizeof(LinkedQueue));
    
    int seq = -1;
    PElement head = initElement(initNode(-1));
    pQueue->head=head;
    pQueue->tail=head;
    pQueue->size=0;
    return pQueue;
}

void inQueue(PLinkedQueue pQueue,PElement pEle){
    if(0 == pQueue->size){
        free(pQueue->head);
        pQueue->head=pEle;
        pQueue->tail=pEle;
        pQueue->size = pQueue->size+1;
        return;
    }

    pQueue->head->prevElement=pEle;
    pEle->nextElement=pQueue->head;
    pQueue->head = pEle;
    pQueue->size = pQueue->size+1;
    return;
}

void showElement(PElement pEle){
    printf(" %d ",pEle->node->number);
}

char checkQueue(PLinkedQueue pQueue){
    if(NULL == pQueue || 0 == pQueue->size){
        return 'F';
    }
    return 'M';
}

void showQueue(PLinkedQueue pQueue){
    char checkResult = checkQueue(pQueue);
    if('F' == checkResult){
        printf("队列为空!不给展示!");
        return;
    }

    PElement tempEle = pQueue->head;

    int i = 0;
    while(i < pQueue->size){
        showElement(tempEle);
        tempEle = tempEle->nextElement;
        i++;
    }
}

PElement outQueue(PLinkedQueue pQueue){
    char checkResult = checkQueue(pQueue);
    if('F' == checkResult){
        printf("队列为空，没法儿出队列!");
        return NULL;
    }

    PElement pEle = pQueue->tail;
    if(1 == pQueue->size){
        pQueue->size = 0;
        PElement pTempHead = initElement(initNode(-1));
        pQueue->tail=pTempHead;
        pQueue->head=pTempHead;
        return pEle;
    }

    pQueue->tail = pQueue->tail->prevElement;
    pQueue->size= pQueue->size-1;
    pEle->prevElement=NULL;

    return pEle;
}