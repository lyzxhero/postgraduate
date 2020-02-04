# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/**
 * 
 * 表示给struct Node起一个别名 Node
 * PNode <==> struct Node
 */
typedef struct Node{
    char id[20];
    char name[20];
    short age;
    char gender[4];
    char classNum[10];
    char health[8];
    struct Node * prevNode;
    struct Node * nextNode;
} Node,*PNode;

PNode initLinkedList(void);
void showLinkedList(PNode);
PNode createNode(char[20],short,char[2],char[10],char[8]);
short getLength(PNode);
short isEmpty(PNode);
short append(PNode,PNode);
PNode findTarget(PNode,int);
short insert(PNode,int,PNode);
short insertFirst(PNode,PNode);
short delete(PNode,int);
short deleteEnd(PNode);
void  showNode(PNode);


int main(void){
    PNode head = initLinkedList();
    PNode item1 = createNode("李耀辉",22,"男","1222班","健康");
    strcpy(item1->id,"1");
    insertFirst(head,item1);
    
    PNode item2 = createNode("肖露",18,"女","1222班","健康");
    strcpy(item2->id,"2");
    insert(head,0,item2);

    PNode item3 = createNode("李大宝",15,"男","1班","健康");
    strcpy(item3->id,"3");
    insert(head,1,item3);   
    

    PNode item4 = createNode("肖二宝",14,"女","2班","健康");
    strcpy(item4->id,"4");
    insert(head,2,item4);  


    PNode item5 = createNode("李三宝",13,"女","3班","健康");
    strcpy(item5->id,"5");
    insertFirst(head,item5); 

    PNode item6 = createNode("李四宝",12,"女","4班","健康");
    strcpy(item6->id,"6");
    insert(head,1,item6);

    PNode item7 = createNode("李七宝",11,"男","7班","健康");
    strcpy(item7->id,"7");
    append(head,item7);

    PNode item8 = createNode("李八宝",10,"男","8班","健康");
    strcpy(item8->id,"8");
    append(head,item8);

    PNode item9 = createNode("李九宝",9,"男","9班","健康");
    strcpy(item9->id,"9");
    append(head,item9);

    showLinkedList(head);
    printf("----------------\n");

    deleteEnd(head);
    showLinkedList(head);
    
    return 0;
}


short append(PNode head,PNode item){
    return insert(head,getLength(head)-1,item);
}

short delete(PNode head,int index){
    PNode target = findTarget(head,index);
    if(NULL == target){
        printf("参数异常!\n");
    }

    PNode targetPrevNode = target->prevNode;
    PNode targetNextNode = target->nextNode;
    
    targetPrevNode->nextNode = targetNextNode;
    if(NULL != targetNextNode){
        targetNextNode->prevNode = targetPrevNode;
    }
    
    target->prevNode = NULL;
    target->nextNode = NULL;

    free(target);

    return 1;
}

short deleteEnd(PNode head){
    return delete(head,getLength(head)-1);
}

short insertFirst(PNode head,PNode item){
    if(NULL == head){
        printf("次链表为空!\n");
        return 0;
    }

    PNode tempNextNode = head->nextNode;

    head->nextNode = item;
    item->prevNode = head;

    if(NULL != tempNextNode){
        item->nextNode = tempNextNode;
        tempNextNode->prevNode = item;
    }

    return 1;
};

PNode findTarget(PNode head,int index){
    PNode target = head->nextNode;
    if(NULL == target){
        printf("[findTarget]中head为空链表");
        return NULL;
    }

    if(index < 0 || index > getLength(head)){
        printf("[findTarget]index=%d错误",index);
        return NULL;
    }

    int targetIndex = 0;
    while(NULL != target){
        if(targetIndex == index){
            return target;
        }
        targetIndex++;
        target = target->nextNode;
    }

    return target;
}

short getLength(PNode head){
    int len = 0;
    if(NULL == head->nextNode){
        return len;
    }

    PNode temp = head->nextNode;
    while(NULL != temp){
        len++;
        temp = temp->nextNode;
    }
    return len;
}

//在index之前插入item
short insert(PNode head,int index,PNode item){
    if(NULL == head){
        printf("头结点为空!\n");
        return 0;
    }

    if(NULL == head->nextNode && index == 0){
        return insertFirst(head,item);
    }
    
    PNode targetNode = findTarget(head,index);

    PNode tempNextNode = targetNode->nextNode;
    PNode tempPrevNode = targetNode->prevNode;

    targetNode->nextNode = item;
    item->prevNode = targetNode;
    if(NULL != tempNextNode){
        item->nextNode = tempNextNode;
        tempNextNode->prevNode = item;
    }

    tempPrevNode->nextNode = targetNode;

    return 0;
}


void showLinkedList(PNode head){
    PNode temp = head->nextNode;
    if(NULL == temp){
        printf("该链表为空链表!");
        return ;
    }

    while(NULL != temp){
        printf("%s<-",temp->prevNode->id);
        printf("(((id=%s",temp->id);
        printf(" [%s] ",temp->name);
        printf(" [%d] ",temp->age);
        printf(" [%s] ",temp->gender);
        printf(" [%s] ",temp->classNum);
        printf(" [%s])))",temp->health);
        if(NULL != temp->nextNode){
            printf("->%s\n",temp->nextNode->id);
        }else{
            printf("->(null)\n");
        }
        temp = temp->nextNode;
    }
}

PNode createNode(char name[20],short age,char gender[4],char classNum[10],char health[8]){
    PNode node = (PNode)malloc(sizeof(Node));
    if(NULL == node){
        printf("创建节点时申请空间失败!");
        return NULL;
    }
    strcpy(node->name,name);
    node->age = age;
    strcpy(node->gender,gender);
    strcpy(node->classNum,classNum);
    strcpy(node->health,health);
    
    return node;
}


PNode initLinkedList(void){
    PNode head = (PNode)malloc(sizeof(Node));
    strcpy(head->id,"0");
    strcpy(head->name,"头指针");
    return head;
}


void  showNode(PNode pnode){
    printf("name=%s , ",pnode->name);
    printf("age=%d , ",pnode->age);
    printf("gender=%s , ",pnode->gender);
    printf("classNum=%s , ",pnode->classNum);
    printf("health=%s\n",pnode->health);
}