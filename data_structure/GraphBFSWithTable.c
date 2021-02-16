# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/**
 * 邻接表法表示的图的基本操作
 * 
 **/ 
//邻接表法中的边表
typedef struct Edge{
    int vertexIndex;
    struct Edge * nextEdge;
}Edge,*PEdge;

typedef struct {
    int index;
    PEdge PEdge;
}Node,*PNode;

typedef struct {
    PNode pNodes[7];
    int len;
}GraphWithTable,*PGraphWithTable;

void showGraphWithTable(PGraphWithTable graph);



int main(void){
    printf("------------\n");
    // showGraphMatrixGraph(pMatrixGraph);
}

/**
 *              0
 *          /       \
 *         1         2
 *       /   \     /
 *      3 --- 4   5
 *     /
 *    6     
 * 
 * 为了简便起见,使用数字标识节点且和数组的下标完全相同
 * 
 **/ 
void linkedListExpress(PGraphWithTable graph){
    graph->len = 7;
    for (int i = 0; i < graph->len; i++){
        
    }
    
}

void showGraphWithTable(PGraphWithTable graph){
    printf("\n");
    for (int i = 0; i < graph->len; i++){
        printf("[%d]%d ",i,graph->pNodes[i]);
        
        PEdge tempEdge = graph->pNodes[i]->PEdge;
        while(tempEdge){
            printf(" ->[%d]%c",tempEdge->vertexIndex,getNames(tempEdge->vertexIndex));
            tempEdge = tempEdge->nextEdge;
        }
        printf("\n");
    }
}