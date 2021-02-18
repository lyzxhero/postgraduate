# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int binarySearch(int array[],int arrayLength,int target);


int main(void){
    int array[20] = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200};
    int index = binarySearch(array,20,110);
    printf("index = %d ",index);
}

int binarySearch(int array[],int arrayLength,int target){
    int lowIndex = 0;
    int highIndex = arrayLength-1;
    int middle = 0;
    
    while(lowIndex <= highIndex){
        middle = (lowIndex + highIndex) / 2;

        if(array[middle] == target){
            return middle;
        }else if(array[middle] > target){
            highIndex = middle -1;
        }else{
            lowIndex = middle + 1;
        }
    } 
    return -1;
}