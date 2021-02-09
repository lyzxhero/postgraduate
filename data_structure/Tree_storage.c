# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Node{
    int number;
    struct Node * leftChild;
    struct Node * rightSibling;
}Node,*PNode;
PNode initNode(int number);


/**
 *                        0
 *               /        |      \
 *              10        9       1
 *           /     \    /   \    /  \
 *          11     12  8    99  2    3
 *         /  \        
 *        4   21 
 **/ 
int main(void){
    PNode node0 = initNode(0);

    PNode node10 = initNode(10);
    PNode node9 = initNode(9);
    PNode node1 = initNode(1);

    node0->leftChild = node10;
    node10->rightSibling=node9;
    node9->rightSibling=node1;

    PNode node11 = initNode(11);
    PNode node12 = initNode(12);

    node10->leftChild=node11;
    node11->rightSibling=node12;

    PNode node8 = initNode(8);
    PNode node99 = initNode(99);
    node9->leftChild=node8;
    node8->rightSibling=node99;

    PNode node2 = initNode(2);
    PNode node3 = initNode(3);

    node1->leftChild=node2;
    node2->rightSibling=node3;

    PNode node4 = initNode(4);
    PNode node21 = initNode(21);

    node11->leftChild=node4;
    node4->rightSibling=node21;

}

PNode initNode(int number){
    PNode node = (PNode)malloc(sizeof(Node));
    node->number = number;
    node->leftChild=NULL;
    node->rightSibling=NULL;
    return node;
}