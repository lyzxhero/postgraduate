# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct {
    int nodes[7];
    int edges[7][7];
    int vaildNodeNum;
}MatrixGraph,*PMatrixGraph;

typedef struct Element{
    int id;
    struct Element * prevElement;
    struct Element * nextElement;
}Element,*PElement;

typedef struct LinkedQueue{
       PElement head;
       PElement tail;
       int size;
}LinkedQueue,*PLinkedQueue;

PMatrixGraph matrixExpress();
void showGraphMatrixGraph(PMatrixGraph pMatrixGraph);
PElement initElement(int id);
PLinkedQueue initLinkedQueue();
PElement outQueue(PLinkedQueue pQueue);
void showQueue(PLinkedQueue pQueue);
void showElement(PElement pEle);
char checkQueue(PLinkedQueue pQueue);
void inQueue(PLinkedQueue pQueue,PElement pEle);
void BFS(PMatrixGraph pMatrixGraph);



/**
 * 
 * 用邻接矩阵表示法表示的图的广度优先搜索
 * GraphBreadthFirstSearch
 * 
 **/ 
int main(void){
    PMatrixGraph pMatrixGraph = matrixExpress();
    BFS(pMatrixGraph);
    // int flag[7] = {0,0,0,0,0,0,0};

    // PLinkedQueue queue = initLinkedQueue();
    // inQueue(queue,initElement(0));
    // inQueue(queue,initElement(1));
    // inQueue(queue,initElement(2));
    // showQueue(queue);
    // outQueue(queue);
    // printf("\n");
    // showQueue(queue);
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
                       {1,0,0,1,1,0,0},
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

void BFS(PMatrixGraph pMatrixGraph){
    int flag[7] = {0,0,0,0,0,0,0};
    PLinkedQueue queue = initLinkedQueue();
    inQueue(queue,initElement(0));
    flag[0] = 1;
    
    int vaildNodeNum = pMatrixGraph->vaildNodeNum;

    for (int i = 0; i < vaildNodeNum; i++){
        for (int j = 0; j < vaildNodeNum; j++){
            int item = pMatrixGraph->edges[i][j];
            if(item == 0){
                continue;
            }

            if(flag[j] == 0){
                inQueue(queue,initElement(j));
                flag[j] = 1;
            }
        }
    }

    for (int i = 0; i < vaildNodeNum; i++){
        PElement pEle = outQueue(queue);
        printf(" %d ",pEle->id);
    }
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

PElement initElement(int id){
    PElement ele = (PElement)malloc(sizeof(Element));
    ele->id = id;
    ele->nextElement=NULL;
    ele->prevElement=NULL;
    return ele;
}

PLinkedQueue initLinkedQueue(){
    PLinkedQueue pQueue = (PLinkedQueue)malloc(sizeof(LinkedQueue));
    int seq = -1;
    PElement head = initElement(seq);
    pQueue->head=head;
    pQueue->tail=head;
    pQueue->size=0;
    return pQueue;
}

void inQueue(PLinkedQueue pQueue,PElement pEle){
    if(0 == pQueue->size){
        free(pQueue->head);
        pQueue->head=pEle;
        pQueue->tail=pEle;
        pQueue->size = pQueue->size+1;
        return;
    }

    pQueue->head->prevElement=pEle;
    pEle->nextElement=pQueue->head;
    pQueue->head = pEle;
    pQueue->size = pQueue->size+1;
    return;
}
void showElement(PElement pEle){
    printf(" %d ",pEle->id);
}

char checkQueue(PLinkedQueue pQueue){
    if(NULL == pQueue || 0 == pQueue->size){
        return 'F';
    }
    return 'M';
}

void showQueue(PLinkedQueue pQueue){
    char checkResult = checkQueue(pQueue);
    if('F' == checkResult){
        printf("队列为空!不给展示!");
        return;
    }
    PElement tempEle = pQueue->head;

    int i = 0;
    while(i < pQueue->size){
        showElement(tempEle);
        tempEle = tempEle->nextElement;
        i++;
    }
}

PElement outQueue(PLinkedQueue pQueue){
    char checkResult = checkQueue(pQueue);
    if('F' == checkResult){
        printf("队列为空，没法儿出队列!");
        return NULL;
    }

    PElement pEle = pQueue->tail;
    if(1 == pQueue->size){
        pQueue->size = 0;
        PElement pTempHead = initElement(-1);
        pQueue->tail=pTempHead;
        pQueue->head=pTempHead;
        return pEle;
    }

    pQueue->tail = pQueue->tail->prevElement;
    pQueue->size= pQueue->size-1;
    pEle->prevElement=NULL;

    return pEle;
}