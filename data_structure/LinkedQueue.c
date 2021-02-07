# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Element{
    int id;
    char name[20];
    struct Element * prevElement;
    struct Element * nextElement;
}Element,*PElement;

typedef struct LinkedQueue{
       PElement head;
       PElement tail;
       int size;
}LinkedQueue,*PLinkedQueue;

PElement initElement(int * id,char name[20]);
void showElement(PElement pEle);
PLinkedQueue initLinkedQueue();
void inQueue(PLinkedQueue pQueue,PElement pEle);
void showElement(PElement pEle);
char checkQueue(PLinkedQueue pQueue);
void showQueue(PLinkedQueue pQueue);
PElement outQueue(PLinkedQueue pQueue);


int main(void){
    PLinkedQueue pQueue = initLinkedQueue();

    int seq = 1;
    PElement pele1 = initElement(&seq,"one");
    inQueue(pQueue,pele1);

    // PElement pele2 = initElement(&seq,"two");
    // inQueue(pQueue,pele2);

    // PElement pele3 = initElement(&seq,"three");
    // inQueue(pQueue,pele3);

    PElement pele4 = initElement(&seq,"four");
    inQueue(pQueue,pele4);

    PElement pele5 = initElement(&seq,"five");
    inQueue(pQueue,pele5);

    showQueue(pQueue);
    printf("\n");
    printf("\n");

    outQueue(pQueue);
    showQueue(pQueue);

}

PElement initElement(int * id,char name[20]){
    PElement ele = (PElement)malloc(sizeof(Element));
    if(NULL == id){
        ele->id = -1;
    }else{
        ele->id=*id;
        *id= *id +1;
    }

    strcpy(ele->name,name);
    ele->nextElement=NULL;
    ele->prevElement=NULL;
    return ele;
}

PLinkedQueue initLinkedQueue(){
    PLinkedQueue pQueue = (PLinkedQueue)malloc(sizeof(LinkedQueue));
    
    int seq = -1;
    PElement head = initElement(&seq,"head");
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
    printf("id=%d,name=%s\n",pEle->id,pEle->name);
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
        PElement pTempHead = initElement(NULL,"head");
        pQueue->tail=pTempHead;
        pQueue->head=pTempHead;
        return pEle;
    }

    pQueue->tail = pQueue->tail->prevElement;
    pQueue->size= pQueue->size-1;
    pEle->prevElement=NULL;

    return pEle;
}