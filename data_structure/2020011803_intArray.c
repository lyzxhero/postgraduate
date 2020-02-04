# include <stdio.h>
# include <stdlib.h>


struct IntArray{
    int * pBase;
    int size;  //��ǰ����
    int len; //�����ܳ���
};

void init_IntArray(struct IntArray *,int);
void show_IntArrayAttr(struct IntArray *);
void showIntArray(struct IntArray *);
int isEmpty(struct IntArray *);
int isFull(struct IntArray *);
int append(struct IntArray *,int);
int deleteFromeEnd(struct IntArray *);
int delete(struct IntArray *,int);
int insert(struct IntArray *,int,int);
int getWithIndex(struct IntArray *,int);
int get(struct IntArray *);
int reSize(struct IntArray *);
void f1(struct IntArray *);
void f2(struct IntArray *);

int main(void){
    struct IntArray * arr;
    f2(arr);
    return 0;
};

void f2(struct IntArray * arr){
    init_IntArray(arr,4);
    show_IntArrayAttr(arr);
    append(arr,100);
    append(arr,200);
    append(arr,300);
    append(arr,400);
    showIntArray(arr);
    insert(arr,3,99);
    showIntArray(arr);
    show_IntArrayAttr(arr);
    // insert(arr,3,990);
    // showIntArray(arr);
}


void f1(struct IntArray * arr){
    init_IntArray(arr,4);
    show_IntArrayAttr(arr);
    append(arr,100);
    append(arr,200);
    append(arr,300);
    append(arr,400);
    append(arr,500);
    showIntArray(arr);
    show_IntArrayAttr(arr);
    append(arr,600);
    append(arr,700);
    append(arr,800);
    append(arr,900);
    append(arr,1000);
    showIntArray(arr);
    show_IntArrayAttr(arr);
    deleteFromeEnd(arr);
    showIntArray(arr);
    delete(arr,2);
    showIntArray(arr);
    delete(arr,5);
    showIntArray(arr);
    delete(arr,1);
    showIntArray(arr);

    int item = getWithIndex(arr,2);
    printf("item[2]=%d",item);
    int item2 = get(arr);
    printf("itemEnd=%d",item2);
}

int insert(struct IntArray * parr,int index ,int item){
    if(index > parr->len-1){
        printf("insert error index=%d > parr->len=%d",index,parr->len);
        return 0;
    }

    //���������������
    if(index > parr->size - 1 ){
        // parr->pBase[index] = item;
        // parr->size++;
        // return 1;
    }else{
        //���ڸ�������Ϊ1 ������Ҫ���������������
        if(parr->size == parr->len){
            reSize(parr);
        }

        printf("parr->size-1=%d         index=%d",parr->size-1,index);
        for(int i=parr->size-1;i>=index;i--){
            printf("parr->pBase[%d](%d) = parr->pBase[%d](%d)",i+1,parr->pBase[i+1],i,parr->pBase[i]);
            parr->pBase[i+1] = parr->pBase[i];
        }

        parr->size++;
        for(int j=0;j<parr->size;j++){
            printf("2------------>%d\n",parr->pBase[j]);
        }
        parr->pBase[index] = item;
    }
}

/**
 * ����������
 * �����µĿռ䲢����ԭ�������ݸ�parr->pBase
 * Ȼ�����parr->len
 */
int reSize(struct IntArray * parr){
    printf("IntArray is full,reSizing....\n");
    int * p_temp = (int * )malloc(sizeof(int) * 2 * parr->len);
    for(int i=0;i<parr->size;i++){
        p_temp[i]=parr->pBase[i];
    }
    free(parr->pBase);
    parr->pBase = p_temp;
    parr->len = parr->len * 2;
}

int getWithIndex(struct IntArray * parr,int index){
    return parr->pBase[index];
}

int get(struct IntArray * parr){
    return getWithIndex(parr,parr->size-1);
}

int deleteFromeEnd(struct IntArray * parr){
    return delete(parr,parr->size-1);
}

int delete(struct IntArray * parr,int index){
    //(����Ϊ�� || ��������) ֱ�ӷ��� 
    if(1 == isEmpty(parr) || index < 0){
        return 1;
    }

    //Ҫɾ�����һ��
    if(index == parr->size-1){
        parr->size--;
        return 1;
    }

    if(0 == isEmpty(parr) && index < parr->size-1){
        for(int i=index;i<parr->size;i++){
            parr->pBase[i] = parr->pBase[i+1];
        }
        parr->size--;
        return 1;
    }
    return 0;
}


void init_IntArray(struct IntArray * parr,int len){
    printf("===============================\n");
    parr->pBase = (int *)malloc(sizeof(int) * len);
    parr->len=len;
    parr->size=0;
};

void show_IntArrayAttr(struct IntArray * parr){
    printf("===============================\n");
    printf("||      IntArray.size=%d       ||\n",parr->size);
    printf("||      IntArray.len=%d       ||\n",parr->len);
    printf("===============================\n");
};

int isEmpty(struct IntArray * parr){
    return parr->size == 0 ? 1 : 0;
};

int isFull(struct IntArray * parr){
    return parr->size == parr->len ? 1 : 0;
}

int append(struct IntArray * parr,int item){
    if(1 == isFull(parr)){
        reSize(parr);
        parr->pBase[parr->size]=item;
        parr->size = parr->size+1;
    }else{
        parr->pBase[parr->size]=item;
        parr->size = parr->size+1;
    }
}

void showIntArray(struct IntArray * parr){
    if(0 == isEmpty(parr)){
        printf("parr->size=%d\n",parr->size);
        for(int i=0;i<parr->size;i++){
            printf("parr[%d]---->%d\n",i,parr->pBase[i]);
        }
    }else{
        printf("����Ϊ��....");
    }
}