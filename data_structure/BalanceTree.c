# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Node{
    int number;
    char remark[10];
    struct Node * leftChild;
    struct Node * rightChild;
    struct Node * parent;
}Node,*PNode;


/**
 *                   30
 *               /        \
 *              20         40
 *           /     \      /  \
 *          11     24    33   49
 *         /  \      \       /
 *        4   15     28     44
 * 
 **/
int main(void){
        PNode node30 = initNode(30,"30th");
    PNode node20 = initNode(20,"20th");
    PNode node40 = initNode(40,"40th");
        node30->leftChild = node20;
        node30->rightChild=node40;
        node20->parent = node30;
        node40->parent = node30;


    PNode node11 = initNode(11,"11th");
    PNode node24 = initNode(24,"24th");
        node20->leftChild = node11;
        node20->rightChild = node24;
        node11->parent = node20;
        node24->parent = node20;


    PNode node4 = initNode(4,"4th");
    PNode node15 = initNode(15,"15th");
        node11->leftChild = node4;
        node11->rightChild = node15;
        node4->parent = node11;
        node15->parent=node11;

    PNode node33 = initNode(33,"33th");
    PNode node49 = initNode(49,"49th");
        node40->leftChild = node33;
        node40->rightChild = node49;
        node33->parent = node40;
        node49->parent = node40;
    
    PNode node28 = initNode(28,"28th");
        node24->rightChild = node28;
        node28->parent = node24;

    PNode node44 = initNode(44,"44th");
        node49->leftChild = node44;
        node44->parent=node49;


}

int isBalance(){
    
}