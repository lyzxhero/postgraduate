# include <stdio.h>
# include <string.h>
# include <stdlib.h>

//邻接表法中的边表
typedef struct Edge{
    int vertexIndex;
    struct Edge * nextEdge;
}Edge,*PEdge;

typedef struct {
    char tag;
    PEdge PEdge;
}Node,*PNode;

PEdge initEdge(int vertexIndex);


/*
 * 邻接表法
 *       A
 *    /^   \_   
 *   B       C
 *  ^|       |
 *   |       |_
 *   D------->E
 *   0 A
 *   1 B
 *   2 C
 *   3 D
 *   4 E
 * 
 * 1、adjacent判断是否存在某条边
2、Neighbors判断某节点所有的边
3、insertVertex插入定点x
4、deleteVertex删除定点x
5、addEdge添加边
6、removeEdge
7、firstNeighbor
 **/
void tableExpress(){
    PNode A = initNode('A');
    PNode B = initNode('B');
    PNode C = initNode('C');
    PNode D = initNode('D');
    PNode E = initNode('E');
    PNode pNodes[5]={A,B,C,D,E};
    
    PEdge edge0_2 = initEdge(2);
    A->PEdge = edge0_2;

    PEdge edge1_0 = initEdge(0);
    B->PEdge = edge1_0;

    PEdge edge2_4 = initEdge(4);
    C->PEdge = edge2_4;

    PEdge edge3_1 = initEdge(1); 
    PEdge edge3_4 = initEdge(4);
    edge3_1->nextEdge = edge3_4;
    D->PEdge = edge3_1;

    for(int i = 0; i < 5; i++){
        printf(" %c ",pNodes[i]->tag);
        // PNode tempNode = pNodes[i];
        // PEdge tempEdge;
        // while(NULL != tempNode->PEdge){
        //     tempEdge = tempNode->PEdge;
        //     printf("->%d ",tempEdge->vertexIndex);
        // }
        printf("\n");
    }
}

PEdge initEdge(int vertexIndex){
    PEdge edge = (PEdge)malloc(sizeof(Node));
    edge->vertexIndex = vertexIndex;
    edge->nextEdge = NULL;
    return edge;
}