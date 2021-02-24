# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void showArr(int target[],int len);
void bubbleSort(int arr[],int len);

int main(void){
    int len =10;
    int arr[10] = {10,8,9,4,3,2,1,5,6,7};
    showArr(arr,len);
    bubbleSort(arr,len);
    showArr(arr,len);
}

void bubbleSort(int arr[],int len){
    for (int i = 0; i < len-1; i++){
        for (int j = 0; j < len-1-i; j++){
            if(arr[j] > arr[j+1]){
                arr[j] = arr[j+1]+arr[j];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
    }
    
}

void showArr(int target[],int len){
    for (int i = 0; i < len; i++){
        printf(" %d ",target[i]);
    }
    printf("\n");
}