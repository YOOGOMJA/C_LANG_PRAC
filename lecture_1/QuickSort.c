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

void printAll_Highlight(int len , int target[] , int highlight_index){
    if(len <= 0) { printf("{  }"); }
	else{
		printf("{");
		for(int i = 0 ; i < len ; i++){
			if(highlight_index == i){
                printf(" [ %d ]" , target[i]);
            }
            else{
                printf(" %d " , target[i]);
            }
			if(i < len-1){ printf(","); }
		}
		printf("}\n");
	}
}

// 1. partition 
void partition(int low , int high , int *pivotpoint){
    printf("partition method called !! low : %d , high : %d\n" , low , high );
    printf("partition target : ");
    printAll_Highlight(8,arr,low);
    // 최초에는 첫 아이템을 기준으로 한다.
    int pivotitem = arr[low];
    int j = low; int temp;
    for(int i = low + 1 ; i <= high ; i++){
        if(arr[i] < pivotitem) {        
            
            j++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    *pivotpoint = j;
    temp = arr[low];
    arr[low] = arr[*pivotpoint];
    arr[*pivotpoint] = temp;
    //printf("in partiion method !! j : %d pivotpoint : %d low : %d\n" , j , *pivotpoint , low);
    
    printf("partition result : ");

    printAll_Highlight(8,arr, *pivotpoint);

    printf("partition finished !! pivotpoint : %d \n" , *pivotpoint);
}

void quicksort(int low , int high){
    int pivotpoint = 0;
    printf("quicksort method called !! low : %d , high : %d\n", low , high);
    if(low < high){
        partition(low , high , &pivotpoint);
        quicksort(low , pivotpoint -1);
        quicksort(pivotpoint + 1,high);
        printf("quicksort method finished !! low : %d , high: %d\n", low , high);
    }
    else{
        printf("quicksort method skipped !! low : %d, high : %d\n", low , high);
    }
}

int main(){
    printf("##### quicksort start \n");
    printf("target : ");
    printAll(8,arr);
    printf("\n");

    quicksort(0,7);

    printf("\n###### RESULT\n");
    printAll(8 , arr);
    return 0;
}