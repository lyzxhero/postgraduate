# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct {
    int nodes[7];
    int edges[7][7];
    int vaildNodeNum;
}MatrixGraph,*PMatrixGraph;

PMatrixGraph matrixExpress();
void showGraphMatrixGraph(PMatrixGraph pMatrixGraph);

/**
 * 
 * 用邻接矩阵表示法表示的图的广度优先搜索
 * GraphBreadthFirstSearch
 * 
 **/ 
int main(void){
    PMatrixGraph pMatrixGraph = matrixExpress();
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
PMatrixGraph matrixExpress(){

    PMatrixGraph pMatrixGraph = (PMatrixGraph)malloc(sizeof(MatrixGraph));
    int nodes[7] = {0,1,2,3,4,5,6};

    int len = 7;
    for (int i = 0; i < len; i++){
        pMatrixGraph->nodes[i] = nodes[i];
    }

    int edges[7][7] = {{0,1,1,0,0,0,0},
                       {1,0,0,1,4,0,0},
                       {1,0,0,0,0,1,0},
                       {0,1,0,0,1,0,1},
                       {0,1,0,1,0,0,0},
                       {0,0,1,0,0,0,0},
                       {0,0,0,1,0,0,0}
                       };
    
    for(int i = 0; i < len; i++){
       for (int j = 0; j < len; j++){
           pMatrixGraph->edges[i][j] = edges[i][j];
       }
    }

    pMatrixGraph->vaildNodeNum = 7;
    showGraphMatrixGraph(pMatrixGraph);
    return pMatrixGraph;
}

void showGraphMatrixGraph(PMatrixGraph pMatrixGraph){
    int vaildNodeNum = pMatrixGraph->vaildNodeNum;
    for (int i = 0; i < vaildNodeNum; i++){
        if(i == 0){
            printf(" \\  [%d] ",pMatrixGraph->nodes[i]);
            continue;
        }
        printf(" [%d] ",pMatrixGraph->nodes[i]);
    }
    printf("\n");
    
    for (int i = 0; i < vaildNodeNum; i++){
        printf("[%d] ",pMatrixGraph->nodes[i]);
        for (int j = 0; j < vaildNodeNum; j++){
            if(j == 0 ){
                printf(" %d  ",pMatrixGraph->edges[i][j]);
            }else{
                printf("  %d  ",pMatrixGraph->edges[i][j]);
            }
            
        }
        printf("\n");
    }
}
