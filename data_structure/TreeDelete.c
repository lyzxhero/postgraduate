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

void showNode(PNode node);
int delete(PNode node,int targetNumber);
PNode initNode(int number,char remark[10]);
void postOrder(PNode node);


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


    printf("\n");
    postOrder(node30);
    printf("\n");


    delete(node30,20);
    printf("\n");
    postOrder(node30);
    printf("\n");

}

void postOrder(PNode node){
    if(NULL != node){
        postOrder(node->leftChild);
        postOrder(node->rightChild);
        showNode(node);
    }
}

/**
 * 树的删除比较复杂分为三种情况
 *   1、删除的是树的叶子节点
 *   2、要删除的节点有一个子节点
 *   3、要删除的节点有两个子节点
 * 
 * 
 **/ 
int delete(PNode node,int targetNumber){
    
    if(NULL == node){
        printf("删除失败!此树中没有[%d]节点!",targetNumber);
        return -1;
    }

    int number = node->number;
    if(targetNumber > number){
        return delete(node->rightChild,targetNumber);
    }

    if(targetNumber < number){
        return delete(node->leftChild,targetNumber);
    }


    PNode leftNode = node->leftChild;
    PNode rightNode = node->rightChild;

    //#1 删除的节点(targetNode)是叶子节点
    if(NULL == leftNode && NULL == rightNode){
        if(node->parent->leftChild == node){
            printf("左节点[%d]删除成功\n",node->number);
            node->parent->leftChild = NULL;
            node->parent = NULL;
        }else{
            node->parent->rightChild = NULL;
            node->parent = NULL;
            printf("右节点[%d]删除成功\n",node->number);
        }
    }

    //#2 删除的节点(targetNode)有一个节点，此时需要降node自己的子树给父节点
    //#2.1要删除的节点有一个右节点
    if(NULL == leftNode && NULL != rightNode){
        if(node->parent->leftChild == node){
            node->parent->leftChild = node->rightChild;
            node->rightChild->parent = node->parent;
        }else{
            node->parent->rightChild = node->rightChild;
            node->rightChild->parent = node->parent;
        }
    }

    //#2.2要删除的节点(targetNode)有一个左节点
    if(NULL != leftNode && NULL == rightNode){
        //要删除的节点是父节点的左节点
        if(node->parent->leftChild == node){
            node->parent->leftChild = node->leftChild;
            node->leftChild->parent = node->parent;
        }else{
            node->parent->rightChild = node->leftChild;
            node->leftChild->parent = node->parent;
        }
    }

    //#3 要删除的节点(targetNode)有两个子节点
    if(NULL != leftNode && NULL != rightNode){
        PNode rLeft = rightNode->leftChild;
        PNode rRight = rightNode->rightChild;
        
        //targetNode的右节点没有子节点 或 target的右节点只有右节点
        if( (NULL == rLeft && NULL == rRight) || (NULL == rLeft && NULL != rRight) ){
            leftNode->parent = rightNode;
            node->leftChild = NULL;

            rightNode->parent = node->parent;

            //node自身是父节点的左孩子
            if(node->parent->leftChild == node){
                node->parent->leftChild = rightNode;
            }else{
                node->parent->rightChild = rightNode;
            }

            rightNode->leftChild = leftNode;
            node->rightChild = NULL;
            node->parent = NULL;

        }

        //无法删除
        if(NULL != rLeft && NULL == rRight){
            return 2;
        }


        //无法删除
        if(NULL != rLeft && NULL != rRight){
            return 2;
        }
    }

    free(node);
    return 1;
}

void showNode(PNode node){
    printf(" %d(%s) ",node->number,node->remark);
}

PNode initNode(int number,char remark[10]){
    PNode node = (PNode)malloc(sizeof(Node));
    node->number = number;
    strcpy(node->remark,remark);
    node->leftChild=NULL;
    node->rightChild=NULL;
    return node;
}