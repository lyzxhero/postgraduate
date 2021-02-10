# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Node{
    int number;
    char remark[10];
    struct Node * leftChild;
    struct Node * rightSibling;
}Node,*PNode;

PNode initNode(int number,char remark[10]);
void find(PNode node,int targetNumber);
void showNode(PNode node);
PNode findNonRecursion(PNode node,int targetNumber);
int insert(PNode node,int targetNumber);



/**
 *                   30
 *               /        \
 *              20         40
 *           /     \      /  \
 *          11     24    33   49
 *         /  \        
 *        4   15
 **/
int main(void){
    PNode node30 = initNode(30,"30th");
    PNode node20 = initNode(20,"20th");
    PNode node40 = initNode(40,"40th");

    node30->leftChild = node20;
    node30->rightSibling=node40;

    PNode node11 = initNode(11,"11th");
    PNode node24 = initNode(24,"24th");

    node20->leftChild = node11;
    node20->rightSibling = node24;

    PNode node4 = initNode(4,"4th");
    PNode node15 = initNode(15,"15th");

    node11->leftChild = node4;
    node11->rightSibling = node15;

    PNode node33 = initNode(33,"33th");
    PNode node49 = initNode(49,"49th");

    node40->leftChild = node33;
    node40->rightSibling = node49;

    // find(node30,16);
    // PNode node = findNonRecursion(node30,4);
    // if(NULL == node){
    //     printf("查找失败!");
    // }else{
    //     printf("result = %d  %s \n",node->number,node->remark);
    // }

    insert(node30,9);
    find(node30,9);
}

int insert(PNode node,int targetNumber){
    int number = node->number;
    if(number == targetNumber){
        return 0;
    }

    PNode nextNode = targetNumber > number ? node->rightSibling : node->leftChild;
    if(NULL == nextNode){
        PNode targetNode = (PNode)malloc(sizeof(Node));
        targetNode->number=targetNumber;
        char remark[10] = {'n','e','w'};
        strcpy(targetNode->remark,remark);
        if(targetNumber > number){
            node->rightSibling = targetNode;
        }else{
            node->leftChild = targetNode;
        }
        return 1;
    }

    return insert(nextNode,targetNumber);

}

PNode findNonRecursion(PNode node,int targetNumber){
    if(NULL == node){
        return NULL;
    }
    if(targetNumber == node->number){
        return node;
    }

    PNode tempNode = node;
    
    while(NULL != tempNode){
        int number = tempNode->number;
        if(number == targetNumber){
            return tempNode;
        }
        tempNode = targetNumber > number ? tempNode->rightSibling : tempNode->leftChild;
    }

    return NULL;

}

void find(PNode node,int targetNumber){
    if(NULL == node ){
        printf("查找失败!,整个树中没有这一项!");
        return;
    }

    int number = node->number;
    if(targetNumber == number){
        printf("目标(%d)已找到其对应的字符串为%s",node->number,node->remark);
        return;
    }

    PNode targetNode = targetNumber > number ? node->rightSibling : node->leftChild;
    find(targetNode,targetNumber);
    return;
}

void showNode(PNode node){
    printf(" %d(%s) ",node->number,node->remark);
}

PNode initNode(int number,char remark[10]){
    PNode node = (PNode)malloc(sizeof(Node));
    node->number = number;
    strcpy(node->remark,remark);
    node->leftChild=NULL;
    node->rightSibling=NULL;
    return node;
}
