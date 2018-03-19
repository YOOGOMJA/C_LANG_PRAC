#include <stdio.h>
#include <stdlib.h>

int arr[8] = { 3,4,6,1,2,10,9,8 };

// 보조 함수 
void printAll(int len , int target[]){
    if(len <= 0) { printf("{  }"); }
	else{
		printf("{");
		for(int i = 0 ; i < len ; i++){
			printf(" %d " , target[i]);
			if(i < len-1){ printf(","); }
		}
		printf("}\n");
	}
}

// 1. partition 
void partition(int low , int high , int *pivotpoint){
    printAll(8,arr);

    printf("low : %d high : %d\n" , low , high );
    // 최초에는 첫 아이템을 기준으로 한다.
    int pivotitem = arr[low];
    int j = low; int temp;
    for(int i = low + 1 ; i <= high ; i++){
        if(arr[i] > pivotitem) {        
            // 오름차순 정렬로 만들었기 때문에 순서가 반대 
            j++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        printf("########\nstep : %d " , i);
        printAll(8,arr);
        printf("########\n");
    }

    *pivotpoint = j;
    temp = arr[low];
    arr[low] = arr[*pivotpoint];
    arr[*pivotpoint] = temp;
    //printf("in partiion method !! j : %d pivotpoint : %d low : %d\n" , j , *pivotpoint , low);
    
    printAll(8 , arr);
}

void quicksort(int low , int high){
    int pivotpoint = 0;
    printf("quicksort method called !! low : %d , high : %d\n", low , high);
    if(low < high){
        partition(low , high , &pivotpoint);
        printf("pivotpoint : %d \n" , pivotpoint);
        quicksort(low , pivotpoint -1);
        quicksort(pivotpoint + 1,high);
    }
}

int main(){
    quicksort(0,7);

    printAll(8 , arr);
    return 0;
}