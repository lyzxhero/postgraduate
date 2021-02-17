# include <stdio.h>
# include <string.h>
# include <stdlib.h>


typedef struct {
    char tag;
    int index;
}Node,*PNode;

typedef struct {
    PNode nodes[9];
    int edges[9][9];
    int vaildNodeNum;
}MatrixGraph,*PMatrixGraph;

PMatrixGraph matrixExpress();
PNode initNode(char tag);
void showGraphMatrixGraph(PMatrixGraph pMatrixGraph);
int getIndex(char nodeName);
char getNames(int index);
void getInCounts(PMatrixGraph pMatrixGraph,int inCounts[]);
void topologySort(PMatrixGraph pMatrixGraph);

/**
 * 
 * 拓扑排序
 * 下图从左到右的顺序
 *       [B]  --->[D]---> [F] 
 *    /      \            ^|   \
 * [A]        \            |    [H] 
 *    \        \           |      \
 *     [C]---->[E] ------>[G]----->[I] 
 * 
 *  各个节点的入度
 *         A  B  C  D  E  F  G  H  I
 *         0  1  1  1  2  2  1  1  2
 **/ 
int main(void){
    PMatrixGraph pMatrixGraph = matrixExpress();
    printf("=================================\n");
    topologySort(pMatrixGraph);
}

void topologySort(PMatrixGraph pMatrixGraph){
    int len = 9;
    int inCounts[9];
    int vaildNumber = 0;
    int otherInCounts[9]={1,1,1,1,1,1,1,1,1,};
    getInCounts(pMatrixGraph,inCounts);
    for (int i = 0; i < len; i++){
        

        if(0 == inCounts[i]){
            printf(" [%c] ",getNames(i));
            
            otherInCounts[i] = -1;
            for(int j = 0; j < len; j++){
                pMatrixGraph->edges[i][j] = 0;
            }
            getInCounts(pMatrixGraph,inCounts);
            for(int j = 0;j<len;j++){
                inCounts[j] = otherInCounts[j] == -1 ? -1 : inCounts[j];
            }
        }else{
            // int sum = 0;
            // for(int j = 0;j<=i;j++ ){
            //     sum+= inCounts[j];
            // }
            // if(-(i+1) != sum){
                int tempArr[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
                int tempIndex = 8;
                for (int j = len - 1; j >=0; j--){
                    if(inCounts[j] != -1){
                        tempArr[tempIndex--] = inCounts[j];
                    }
                }
                for (int j = 0; j < len; j++){
                    inCounts[j] = tempArr[j];
                }
            // }
        }
    }
}

void getInCounts(PMatrixGraph pMatrixGraph,int inCounts[]){
    int len = pMatrixGraph->vaildNodeNum;

    for (int i = 0; i < len; i++){
        int count = 0;
        for (int j = 0; j < len; j++){
            if(pMatrixGraph->edges[j][i] == 1){
                  count++;  
            }            
        }
        inCounts[i] = count;
        count = 0;
    }

    // for (int i = 0; i < len; i++){
    //     printf(" %d ",inCounts[i]);
    // }
    // printf("\n");
    
}


PMatrixGraph matrixExpress(){
    PMatrixGraph pMatrixGraph = (PMatrixGraph)malloc(sizeof(MatrixGraph));
    int len = 9;
    PNode nodes[9]={initNode('A'),initNode('B'),initNode('C'),
                    initNode('D'),initNode('E'),initNode('F'),
                    initNode('G'),initNode('H'),initNode('I')};
    
    for(int i = 0; i < len; i++){
        pMatrixGraph->nodes[i]=nodes[i];
    }

    int edges[9][9] = {{0,1,1,0,0,0,0,0,0},//A
                       {0,0,0,1,1,0,0,0,0},//B
                       {0,0,0,0,1,0,0,0,0},//C
                       {0,0,0,0,0,1,0,0,0},//D
                       {0,0,0,0,0,0,1,0,0},//E
                       {0,0,0,0,0,0,0,1,0},//F
                       {0,0,0,0,0,1,0,0,1},//G
                       {0,0,0,0,0,0,0,0,1},//H
                       {0,0,0,0,0,0,0,0,0} //I
                       };

    pMatrixGraph->vaildNodeNum = len;
    
    for(int i = 0; i < len; i++){
       for (int j = 0; j < len; j++){
           pMatrixGraph->edges[i][j] = edges[i][j];
       }
    }

    showGraphMatrixGraph(pMatrixGraph);
    return pMatrixGraph;
}

PNode initNode(char tag){
    PNode item = (PNode)malloc(sizeof(Node));
    item->tag = tag;
    item->index = getIndex(tag);
    return item;
}

void showGraphMatrixGraph(PMatrixGraph pMatrixGraph){
    int vaildNodeNum = pMatrixGraph->vaildNodeNum;
    for (int i = 0; i < vaildNodeNum; i++){
        if(i == 0){
            printf(" \\ %c ",pMatrixGraph->nodes[i]->tag);
            continue;
        }
        printf(" %c ",pMatrixGraph->nodes[i]->tag);
    }
    printf("\n");
    
    for (int i = 0; i < vaildNodeNum; i++){
        printf("%c ",pMatrixGraph->nodes[i]->tag);
        for (int j = 0; j < vaildNodeNum; j++){
            printf(" %d ",pMatrixGraph->edges[i][j]);
        }
        printf("\n");
    }
}

int getIndex(char nodeName){
    char nodeNames[11] = {'A','B','C','D','E','F','G','H','I','J','K'};
    for (int i = 0; i <11; i++){
        if(nodeName == nodeNames[i]){
            return i;
        }
    }
    return -1;
}

char getNames(int index){
    char nodeNames[11] = {'A','B','C','D','E','F','G','H','I','J','K'};
    for (int i = 0; i < 11; i++){
        if(index == i){
            return nodeNames[i];
        }
    }
    return '0';
}