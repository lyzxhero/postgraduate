# include <stdio.h>
# include <stdlib.h>

void f1(void);
void f2(void);
void f3(void);

int main(void){
    f2();
    return 0;
}


void f2(void){
    printf("请输入数组长度.....");
    int len;
    scanf("%d",&len);
    printf("数组长度=%d\n",len);

    int* parray = (int*)malloc(sizeof(int) * len);
    int i=0;
    for(i=0;i<len;i++){
        scanf("%d",&parray[i]);
    }

    for(i=0;i<len;i++){
        printf("-->parray[%d]=%d\n",i,parray[i]);
    }
}

void f1(void){
    int len;
    printf("请输入数组长度.....\n");
    //这儿需要注意,scanf后面接变量的地址而不是变量名
    scanf("%d",&len);

    //申请了len*sizeof(int)个字节数的空间并把这份空间转换为int *
    int* parray = (int *)malloc(sizeof(int)*len);
    *parray = 1;
    *(parray+1)=2;
    parray[1] = 200;

    printf("%d\n",*parray);
    printf("%d\n",*(parray+1));

    free(parray);
};


