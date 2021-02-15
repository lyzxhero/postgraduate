# include <stdio.h>
# include <string.h>
# include <stdlib.h>


typedef struct {
    char tag;
}Node,*PNode;

typedef struct {
    PNode nodes[10];
    int edges[10][10];
    int vaildNodeNum;
}MatrixGraph,*PMatrixGraph;

PMatrixGraph matrixExpress();
PNode initNode(char tag);
void tableExpress();
void twoDimensionArrToArr(int edges[5][5],int valueArr[5][5],int len);
int getIndex(char nodeName);
int adjacentInMatrixGraph(PMatrixGraph pMatrixGraph,char edge[2]);
char getNames(int index);
void neighborsInMatrixGraph(PMatrixGraph pMatrixGraph,PNode pNode);
void showGraphMatrixGraph(PMatrixGraph pMatrixGraph);
void insertVertex(PMatrixGraph pMatrixGraph,char nodeName);
void deleteVertex(PMatrixGraph pMatrixGraph,char nodeName);
void addEdge(PMatrixGraph pMatrixGraph,char startNodeName,char endNodeName);
void removeEdge(PMatrixGraph pMatrixGraph,char startNodeName,char endNodeName);
int firstNeighbor(PMatrixGraph pMatrixGraph,char nodeName);


int main(void){
    PMatrixGraph pMatrixGraph = matrixExpress();
    // char names[2] = {'B','C'};
    // int i = adjacentInMatrixGraph(pMatrixGraph,names);
    // printf(" %d ",i);
    // neighborsInMatrixGraph(pMatrixGraph,initNode('E'));
    insertVertex(pMatrixGraph,'F');
    // insertVertex(pMatrixGraph,'G');
    // deleteVertex(pMatrixGraph,'G');

    addEdge(pMatrixGraph,'A','F');
    removeEdge(pMatrixGraph,'A','F');
    int index = firstNeighbor(pMatrixGraph,'A');
    printf(" %d \n",index);
    printf("A的第一个相邻节点为%c\n",getNames(index));
}

void removeEdge(PMatrixGraph pMatrixGraph,char startNodeName,char endNodeName){
    int startIndex = getIndex(startNodeName);
    int endIndex = getIndex(endNodeName);
    if(pMatrixGraph->edges[startIndex][endIndex] == 0 ){
        printf("从%c到%c的边不存在,无需再删除!",startNodeName,endNodeName);
        return;
    }

    pMatrixGraph->edges[startIndex][endIndex] = 0;
    pMatrixGraph->edges[endIndex][startIndex] = 0;
    printf("====================================\n");
    showGraphMatrixGraph(pMatrixGraph);
}

void addEdge(PMatrixGraph pMatrixGraph,char startNodeName,char endNodeName){
    int startIndex = getIndex(startNodeName);
    int endIndex = getIndex(endNodeName);
    if(pMatrixGraph->edges[startIndex][endIndex] == 1){
        printf("从%c到%c的边存在,无需再添加!",startNodeName,endNodeName);
        return;
    }

    pMatrixGraph->edges[startIndex][endIndex] = 1;
    pMatrixGraph->edges[endIndex][startIndex] = 1;
    printf("====================================\n");
    showGraphMatrixGraph(pMatrixGraph);
}

void deleteVertex(PMatrixGraph pMatrixGraph,char nodeName){
    int index = getIndex(nodeName);
    pMatrixGraph->nodes[index] = initNode('0');
    for (int i = 0; i < pMatrixGraph->vaildNodeNum; i++){
        for (int j = 0; j < pMatrixGraph->vaildNodeNum; j++){
            if(i == index || j == index){
                pMatrixGraph->edges[i][j] = -1;
            }
        }
    }
    printf("============================\n");
    showGraphMatrixGraph(pMatrixGraph);
}

void insertVertex(PMatrixGraph pMatrixGraph,char nodeName){
    int vaildNodeNum = pMatrixGraph->vaildNodeNum;
    pMatrixGraph->nodes[vaildNodeNum] = initNode(nodeName);
    pMatrixGraph->vaildNodeNum = vaildNodeNum + 1;

    for(int i=0;i<pMatrixGraph->vaildNodeNum;i++){
        for(int j=0; j < pMatrixGraph->vaildNodeNum; j++){
            if(i == vaildNodeNum || j == vaildNodeNum){
                pMatrixGraph->edges[i][j]=0;
            }
        }   
    }
    printf("============================\n");
    showGraphMatrixGraph(pMatrixGraph);
}

int firstNeighbor(PMatrixGraph pMatrixGraph,char nodeName){
    int index = getIndex(nodeName);
    for (int i = 0; i < pMatrixGraph->vaildNodeNum; i++){
        if(pMatrixGraph->edges[index][i] == 1){
            return i;
        }
    }
    return -1;
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
PMatrixGraph matrixExpress(){
    PMatrixGraph pMatrixGraph = (PMatrixGraph)malloc(sizeof(MatrixGraph));
    int len = 5;
    PNode nodes[5]={initNode('A'),initNode('B'),initNode('C'),initNode('D'),initNode('E')};
    
    for(int i = 0; i < len; i++){
        pMatrixGraph->nodes[i]=nodes[i];
    }

    int edges[5][5] = {{0,1,1,0,0},
                       {1,0,0,1,0},
                       {1,0,0,0,1},
                       {0,1,0,0,1},
                       {0,0,1,1,0}
                       };

    pMatrixGraph->vaildNodeNum = 5;
    
    for(int i = 0; i < len; i++){
       for (int j = 0; j < len; j++){
           pMatrixGraph->edges[i][j] = edges[i][j];
       }
    }

    showGraphMatrixGraph(pMatrixGraph);
    return pMatrixGraph;
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

/**
 * 在邻接矩阵中判断某个边是否存在
 * 
 **/ 
int adjacentInMatrixGraph(PMatrixGraph pMatrixGraph,char edge[2]){
    int startIndex = getIndex(edge[0]);
    int endIndex = getIndex(edge[1]);
    return pMatrixGraph->edges[startIndex][endIndex] == 1 ? 1 : 0;   
}

/**
 * 判断某节点所有的边
 * 
 **/
void neighborsInMatrixGraph(PMatrixGraph pMatrixGraph,PNode pNode){
    int index = getIndex(pNode->tag);
    printf("与%c有关的边有:\n",pNode->tag);
    for (int i = 0; i < 5; i++){
        if(pMatrixGraph->edges[index][i] == 1){
            printf(" %c--%c \n",pNode->tag,getNames(i));
        }
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

PNode initNode(char tag){
    PNode item = (PNode)malloc(sizeof(Node));
    item->tag = tag;
    return item;
}