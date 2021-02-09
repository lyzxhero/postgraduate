# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Node{
    int number;
    struct Node * leftNode;
    struct Node * rightNode;
}Node,*PNode;

PNode initNode(int number);
void preOrder(PNode node);
void showNode(PNode node);
void inOrder(PNode node);
void postOrder(PNode node);


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
    //inOrder(root);
    postOrder(root);
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