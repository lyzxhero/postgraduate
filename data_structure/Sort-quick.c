# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void quickSort(int arr[],int lowIndex,int hightIndex);
int adjustArray(int arr[], int lowIndex, int hightIndex);



int main(void){

}

void quickSort(int arr[],int lowIndex,int hightIndex){
    if(lowIndex >= hightIndex){
        return;
    }

    int index = adjustArray(arr,lowIndex,hightIndex);
    quickSort(arr,lowIndex,index);
    quickSort(arr,index+1,hightIndex);
}

int adjustArray(int arr[], int lowIndex, int hightIndex){
    int upperCount = 0;
    int lowwerCount = 0;
    int equalCount = 0;

    int tempLowwerIndex = lowIndex;
    int pivot = arr[tempLowwerIndex];
    tempLowwerIndex++;

    while(tempLowwerIndex < hightIndex){
        if(arr[tempLowwerIndex] > pivot){
            upperCount++;
        }else if(arr[tempLowwerIndex] < pivot){
            lowwerCount++;
        }else{
            equalCount++;
        }
        tempLowwerIndex++;
    }

    //找到小于pivot的数的个数lowwerCount和等于pivot的数的个数equalCount
    //在lowIndex的基础之上计算得出arr[lowIndex]即pivot应该的索引位置index
    int index = lowIndex+lowwerCount+equalCount;

    //这种情况属于pivot就是最小的直接返回即可
    if( index == lowIndex){
        return index;
    }

    //这种情况属于pivot为最大的,互换第一个和最后一个
    if(index == hightIndex){
        arr[lowIndex] = arr[lowIndex] + arr[hightIndex];
        arr[hightIndex] = arr[lowIndex] - arr[hightIndex];
        arr[lowIndex] = arr[lowIndex] - arr[hightIndex];
        return index;
    }


    /**
     * 
     * 下列属于既有大于pivot的数又有小于pivot的数
     * 即index在lowIndex和hightIndex之间
     **/

    //把pivot放到了对的位置
    int tempNumber = arr[index];
    arr[index] = arr[lowIndex];
    arr[lowIndex] = tempNumber;


    int tempPointor = lowIndex;
    int count = lowwerCount > upperCount ? lowwerCount : upperCount;
    for(int i = index-1,j=index+1; i >= lowIndex && j<= hightIndex ;){
        
        for (int ii = i; ii < i; ii++){
            
        }

        if(arr[j] < pivot){

            j--;
        }
    }
    
    
    return index;
}