# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void insertSort(int target[],int len);
void showArr(int target[],int len);
void insertion_sort(int arr[], int len);

int main(void){
    int len = 13;
    int target[13]= {9,7,8,99,11,4567,4,5,6,3,2,1,0};
    showArr(target,len);
    insertSort(target,len);
    // insertion_sort(target,10);
    showArr(target,len);
    
    //8,9,7,6,5,4,3,2,1,0
}

void showArr(int target[],int len){
    for (int i = 0; i < len; i++){
        printf(" %d ",target[i]);
    }
    printf("\n");
}

void insertSort(int target[],int len){
    for (int i = 1; i < len; i++){
        int item = target[i];
        if(item < target[i-1]){

            int temIndex;
            for (int j = i-1; j >=0; j--){
                if(target[j] > item){
                    temIndex = j;
                    target[j+1] = target[j];
                }
            }
            target[temIndex] = item;
        }
    }
}

void insertion_sort(int arr[], int len){
        int i,j,key;
        for (i=1;i<len;i++){
                key = arr[i];
                j=i-1;
                while((j>=0) && (arr[j]>key)) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
        }
}