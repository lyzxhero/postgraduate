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
    char tag;
    PEdge PEdge;
}Node,*PNode;

typedef struct {
    PNode pNodes[10];
    int len;
}GraphWithTable,*PGraphWithTable;


PEdge initEdge(int vertexIndex);
PNode initNode(char tag);
void tableExpress(PGraphWithTable graph);
void showGraphWithTable(PGraphWithTable graph);
char getNames(int index);
int getIndex(char nodeName);
int adjacent(PGraphWithTable graph,char startNodeName,char endNodeName);
void neighbors(PGraphWithTable graph,char nodeName);
void insertVertex(PGraphWithTable graph,char nodeName);
PGraphWithTable initGraph();
void deleteVertex(PGraphWithTable graph,char nodeName);
void addEdge(PGraphWithTable graph,char startNodeName,char endNodeName);
void removeEdge(PGraphWithTable graph,char startNodeName,char endNodeName);
void firstNeighbor(PGraphWithTable graph,char nodeName);



int main(void){
    PGraphWithTable graph  = initGraph();
    tableExpress(graph);
    showGraphWithTable(graph);
    adjacent(graph,'B','D');
    neighbors(graph,'B');
    insertVertex(graph,'F');
    insertVertex(graph,'G');
    // deleteVertex(graph,'F');

    addEdge(graph,'F','G');
    addEdge(graph,'E','G');
    addEdge(graph,'G','A');
    addEdge(graph,'D','F');
    addEdge(graph,'D','G');


    // removeEdge(graph,'B','A');
    // removeEdge(graph,'C','E');


    // removeEdge(graph,'D','F');
    // removeEdge(graph,'D','E');
    // removeEdge(graph,'D','B');


    // removeEdge(graph,'D','B');
    // removeEdge(graph,'D','E');
    // removeEdge(graph,'D','F');
    
    // removeEdge(graph,'D','E');
    // removeEdge(graph,'D','F');
    // removeEdge(graph,'D','B');
    // removeEdge(graph,'D','G');

    firstNeighbor(graph,'A');
    firstNeighbor(graph,'D');
}

void firstNeighbor(PGraphWithTable graph,char nodeName){
    char tag = getNames(graph->pNodes[getIndex(nodeName)]->PEdge->vertexIndex);
    printf("%c的第一出边为%c\n",nodeName,tag);
}

void removeEdge(PGraphWithTable graph,char startNodeName,char endNodeName){
    int result = adjacent(graph,startNodeName,endNodeName);
    if(result == 0){
        printf("%c->%c边不存在,没必要删除!",startNodeName,endNodeName);
        return;
    }

    int startIndex = getIndex(startNodeName);
    int endIndex = getIndex(endNodeName);

    PNode pNode = graph->pNodes[startIndex];
    PEdge indexEdge = pNode->PEdge;
    PEdge tempEdge = indexEdge;

    //len=出边的个数  index要删除节点的下标
    int len =0;
    int index = 0;
    int flag = 1;

    while(tempEdge){
        len++;
        if(flag == 1 && tempEdge->vertexIndex != endIndex){
            index++;
        }

        if(tempEdge->vertexIndex == endIndex){
            flag = 0;
        }

        tempEdge = tempEdge->nextEdge;
    }

    if(len == 0){
        printf("removeEdge方法传参错误!\n");
        return;
    }

    //只有一条出边
    if(len == 1){
        PEdge cc = pNode->PEdge;
        pNode->PEdge = NULL;
        
        free(indexEdge);
        showGraphWithTable(graph);
        return;
    }

    //有多条出边且要删除的是第一个节点
    if(index == 0){
        PEdge target = indexEdge->nextEdge;
        indexEdge->nextEdge = NULL;
        pNode->PEdge = target;
        free(indexEdge);
        showGraphWithTable(graph);
        return;
    }

    //要删除的边是最后一个,需要找到倒数第二个边的指针并置为NULL
    if(len == index+1){
        PEdge prevEdge = indexEdge;
        for (int i = 0; i < index-1 ; i++){
            prevEdge = prevEdge->nextEdge;
        }

        PEdge targetEdge = prevEdge->nextEdge;
        prevEdge->nextEdge = NULL;
        free(targetEdge);
        showGraphWithTable(graph);
        return;
    }

    
    //要删除的节点在链表的中间
    tempEdge = pNode->PEdge;
    //循环执行完毕后tempEdge指向要删除节点的前一个
    for (int i = 0; i < index-1; i++){
        tempEdge = tempEdge->nextEdge;
    }

    PEdge prevEdge = tempEdge;
    PEdge nextEdge = tempEdge->nextEdge->nextEdge;
    PEdge currentEdge = tempEdge->nextEdge;

    currentEdge->nextEdge = NULL;
    prevEdge->nextEdge = nextEdge;
    free(currentEdge);
    showGraphWithTable(graph);
    return;
}

PGraphWithTable initGraph(){
    return (PGraphWithTable)malloc(sizeof(GraphWithTable));
}

void deleteVertex(PGraphWithTable graph,char nodeName){
    int index = getIndex(nodeName);
    printf("\n您要删除的节点是[%c][index=%d]",nodeName,index);
    int len = graph->len;

    for (int i = index; i < len; i++){
        if(i == len -1){
            continue;
        }
        graph->pNodes[index] = graph->pNodes[i+1];
    }
    free(graph->pNodes[len-1]);
    graph->len = len-1;

    showGraphWithTable(graph);
}

/**
 * 
 * 判断是否存在某条边
 * 
 **/ 
int adjacent(PGraphWithTable graph,char startNodeName,char endNodeName){
    int startIndex = getIndex(startNodeName);
    int endIndex = getIndex(endNodeName);

    PEdge tempEdge = graph->pNodes[startIndex]->PEdge;
    while (tempEdge){
        if(tempEdge->vertexIndex == endIndex){
            printf("(√)从%c到%c的边存在!\n",startNodeName,endNodeName);
            return 1;
        }
        tempEdge = tempEdge->nextEdge;
    }
    printf("(×)从%c到%c的边不存在!\n",startNodeName,endNodeName);
    return 0;
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
void tableExpress(PGraphWithTable graph){
    PNode A = initNode('A');
    PNode B = initNode('B');
    PNode C = initNode('C');
    PNode D = initNode('D');
    PNode E = initNode('E');

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

    graph->pNodes[0]= A;
    graph->pNodes[1]= B;
    graph->pNodes[2]= C;
    graph->pNodes[3]= D;
    graph->pNodes[4]= E;

    graph->len = 5;
}

void addEdge(PGraphWithTable graph,char startNodeName,char endNodeName){
    int startIndex = getIndex(startNodeName);
    int endIndex = getIndex(endNodeName);

    PEdge tempEdge = graph->pNodes[startIndex]->PEdge;
    PEdge lastEdge = NULL;
    
    //如果图中有边就不用添加
    while (tempEdge){
        lastEdge = tempEdge;
        if(tempEdge->vertexIndex == endIndex){
            printf("从%c到%c的边本来就存在,不必添加!",startNodeName,endNodeName);
            return;
        }
        tempEdge = tempEdge->nextEdge;
    }

    //添加startNodeName的出边
    PEdge pEdge = initEdge(endIndex);
    if(NULL == lastEdge){
        graph->pNodes[startIndex]->PEdge = pEdge;
    }else{
        lastEdge->nextEdge = pEdge;
    }

    printf("========================================\n");
    showGraphWithTable(graph);

}




void insertVertex(PGraphWithTable graph,char nodeName){
    printf("========================================\n");
    int len = graph->len;
    graph->pNodes[len]=initNode(nodeName);
    graph->len = len + 1;
    showGraphWithTable(graph);
}

void neighbors(PGraphWithTable graph,char nodeName){
    printf("和%c相关的所有边有:\n",nodeName);
    int index = getIndex(nodeName);
    
    //打印出边
    PEdge tempNode = graph->pNodes[index]->PEdge;
    while (tempNode){
        printf("          %c->%c\n",nodeName,getNames(tempNode->vertexIndex));
        tempNode = tempNode->nextEdge;
    }

    //循环整个类HashMap结构筛选入边
    for (int i = 0; i < graph->len; i++){
        if(i == index){
            continue;
        }
        tempNode = graph->pNodes[i]->PEdge;
        while (tempNode){
            if(tempNode->vertexIndex == index){
                printf("          %c->%c\n",getNames(i),nodeName);
            }
            tempNode = tempNode->nextEdge;
        }
    }
    printf("\n");
}

void showGraphWithTable(PGraphWithTable graph){
    printf("\n");
    for (int i = 0; i < graph->len; i++){
        printf("[%d]%c ",i,graph->pNodes[i]->tag);
        
        PEdge tempEdge = graph->pNodes[i]->PEdge;
        while(tempEdge){
            printf(" ->[%d]%c",tempEdge->vertexIndex,getNames(tempEdge->vertexIndex));
            tempEdge = tempEdge->nextEdge;
        }
        printf("\n");
    }
}


PEdge initEdge(int vertexIndex){
    PEdge edge = (PEdge)malloc(sizeof(Node));
    edge->vertexIndex = vertexIndex;
    edge->nextEdge = NULL;
    return edge;
}

PNode initNode(char tag){
    PNode item = (PNode)malloc(sizeof(Node));
    item->tag = tag;
    return item;
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