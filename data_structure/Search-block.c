# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int blockSearch(int array[],int arrLen,int blocks[],int lowIndexs[],int highIndexs[],int blockLen,int target);
/**
 * @author hero.li
 * @date 2021-01-18
 *分块查找 
 * 
 **/
int main(void){
    int array[20] = {10,20,30,40,
                     90,50,70,80,60,100,
                     140,110,120,130,150,
                     170,190,200,160,180};
    
    int blocks[4] ={40,100,150,200};
    int lowIndexs[4] = {0,4,10,15};
    int highIndexs[4] = {3,9,14,19};

    int i = blockSearch(array,20,blocks,lowIndexs,highIndexs,4,111);
    printf(" %d \n",i);
    
}

int blockSearch(int array[],int arrLen,int blocks[],int lowIndexs[],int highIndexs[],int blockLen,int target){
    int index = -1;
    for (int i = 0; i < blockLen; i++){
        if(target <= blocks[i]){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("次数[%d]不存在!\n",target);
        return -1;
    }

    printf("初步筛选数[%d]在第%d组,下标范围是:%d-%d\n",target,(index+1),lowIndexs[index],highIndexs[index]);

    for (int i = lowIndexs[index]; i < highIndexs[index]; i++){
        if(array[i] == target){
            return i;
        }
    }
    return -1;
}