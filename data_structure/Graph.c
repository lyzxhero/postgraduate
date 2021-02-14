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

typedef struct {
    PNode nodes[5];
    int edges[5][5];
}Graph,*PGraph;
void matrixExpress();
PNode initNode(char tag);
PEdge initEdge(int vertexIndex);
void tableExpress();

 
int main(void){
   tableExpress();
}

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

void showNodeArray(PNode pNodes[],int len){
    for(int i = 0; i < len; i++){
         
    }
}
/**
 * 
 * 对上图的邻接矩阵表示法
 * 用一维数组表示各个定点
 * 用二维数组表示各个定点之间的关系即边
 *      A
 *   /     \
 *  B       C
 *  |       |
 *  D ----- E
 **/ 
void matrixExpress(){
    PNode pNodes[5]={initNode('A'),initNode('B'),initNode('C'),initNode('D'),initNode('E')};
    int edges[5][5] = {{0,1,1,0,0},
                       {1,0,0,1,0},
                       {1,0,0,0,1},
                       {0,1,0,0,1},
                       {0,0,1,1,0}
                       };

    for (int i = 0; i < 5; i++){
        if(i == 0){
            printf(" \\ %c ",pNodes[i]->tag);
            continue;
        }
        printf(" %c ",pNodes[i]->tag);
    }
    printf("\n");
    
    for (int i = 0; i < 5; i++){
        printf("%c ",pNodes[i]->tag);
        for (int j = 0; j < 5; j++){
            printf(" %d ",edges[i][j]);
        }
        printf("\n");
    }
}

PNode initNode(char tag){
    PNode item = (PNode)malloc(sizeof(Node));
    item->tag = tag;
    return item;
}