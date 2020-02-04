# include <stdio.h>



void f1(int i){
    i = 100;
}

void f2(int* p){
    *p = 100;
}

void f3(){
    //一维数组名是地址第一个元素的地址 a[i]=*(a+i)
    int a[5] = {1,2,3,4,5};
    printf("a=%p\n",a);
    
    int temp;
    for(temp=0;temp<5;temp++){
        printf("a[%d]=%d\n",temp,a[temp]);
    }
}


//修改一个实参的值
void f4(int* p){
    p[0]=100;
}

void f5(){
    int a[5] = {1,2,3,4,5};
    printf("a[0]=%p\n",a);
    printf("a[1]=%p\n",a+1);

    double b[5] = {1.1,2.2,3.3,4.4,5.5};
    printf("b[0]=%p\n",b);
    printf("b[1]=%p\n",b+1);

    //*p 的 = 地址是p的值的内存中的元素 p+1=p的值加上p的类型所占的字节数的和
}


int main(){
    int j=10;

    //p只是一个变量名,int * p表示p只能保存整型数据的地址
    printf("p只是一个变量名,int * p表示p只能保存整型数据的地址\n");
    int* p;
    p = &j;
    printf("--------*p=%d,j=%d",*p,j);

    printf("--------------\n");

    // int i=9;
    // f2(&i);
    // printf("i=%d",i);
    
    // int a[5] = {1,2,3,4,5};
    // f4(a);
    // printf("a[0]=%d",a[0]);

    f5();
}