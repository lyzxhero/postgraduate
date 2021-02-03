# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/**
 * create by hero.li
 * date 2021-02-03 
 * 链表的常用操作
 **/
 
struct Node
{
    int id;
    char name[20];
    char gender;
    float score;
    struct Node * prevNode;
    struct Node * nextNode;
};

struct Node * structNode(int * id,char name[20],char gender,float score);
struct Node * initNodeHead();
void showNode(struct Node * node);
void showLinkedList(struct Node * head);
int getLinkedListLength(struct Node * pHead);
void insertNode(struct Node * pHead,int index,struct Node * node);
struct Node * findNode(struct Node * pHead,int index);
void add(struct Node * pHead,struct Node * node);


int main(void){
    int initId = 0;
    struct Node * head = initNodeHead();

    struct Node * node1 = structNode(&initId,"李耀辉",'M',99.3f);
    head->nextNode = node1;
    node1->prevNode = head;
    
    struct Node * node2 = structNode(&initId,"李",'M',90.3f);
    node1->nextNode = node2;
    node2->prevNode = node1;
    
    struct Node * node3 = structNode(&initId,"张",'M',90.3f);
    node2->nextNode = node3;
    node3->prevNode = node2;
    
    showLinkedList(head);

    struct Node * node4 = structNode(&initId,"王",'F',90.2f);
    insertNode(head,2,node4);
    showLinkedList(head);
    printf("\n");

    struct Node * node5 = structNode(&initId,"赵",'M',910.2f);
    add(head,node5);
    showLinkedList(head);

}

struct Node * initNodeHead(){
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    head->id = 0;
    strcpy(head->name,"头指针");
    head->prevNode=NULL;
    head->nextNode=NULL;
    return head;
};


struct Node * structNode(int * id,char name[20],char gender,float score){
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(node->name,name);
    node->id = *id;
    *id = *id +1;
    node->gender = gender;
    node->score = score;
    node->nextNode = NULL;
    return node;
}

void showNode(struct Node * node){
    // int nextNodeId = NULL != node->nextNode ? node->nextNode->id : 0 ;
     int nextNodeId = 0;
    printf("id=[%d],name=[%s],gender=[%c],score=[%f],nextNodeId=[%d]\n",node->id,node->name,node->gender,node->score,nextNodeId);
}

void showLinkedList(struct Node * head){
    if(NULL == head){
        printf("this linkedList's head is null !");
        return;
    }

    struct Node * tempNode = head;
    while(NULL != tempNode->nextNode){
        tempNode = tempNode->nextNode;
        showNode(tempNode);
    }
    return;
}

int getLinkedListLength(struct Node * pHead){
    int len = 0;
    
    struct Node * tempItem = pHead; 
    while(NULL != tempItem->nextNode){
        len++;
        tempItem = tempItem->nextNode;
    }

    return len;
}

void insertNode(struct Node * pHead,int index,struct Node * node){
    if(NULL == pHead || NULL == pHead->nextNode){
        printf("头结点为空/只有头结点");
        return;
    }

    int len = getLinkedListLength(pHead);
    if(index > len ){
        printf("总共就%d个元素，你想在第%d个之后插入元素，不好意思插不了!!!!",len,index);
        return;
    }

    struct Node * targetNode = findNode(pHead,index);
    struct Node * tempNode = targetNode->nextNode;
    targetNode->nextNode = node;
    node->prevNode = targetNode;
    if(index == len ){
        return ;
    }

    
    tempNode->prevNode = node;
    node->nextNode = tempNode;
    return;
}

void add(struct Node * pHead,struct Node * node){
    int index = getLinkedListLength(pHead);
    insertNode(pHead,index,node);
}

struct Node * findNode(struct Node * pHead,int index){
        int targetIndex = 0;
        struct Node * tempItem  = pHead;
        while(NULL != tempItem->nextNode){
            targetIndex++;
            if(index == targetIndex){
                return tempItem->nextNode;
            }
            tempItem = tempItem->nextNode;
        }

        return NULL;
}