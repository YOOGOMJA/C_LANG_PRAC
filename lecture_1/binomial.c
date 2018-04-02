#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Description : 이항 계수를 재귀적 방법으로 구한다
// Parameters 
// { 
//      pow : 대상인 식의 제곱 수 
//      seq : 몇번 째 항의 값을 구할지 정함
// }
int getBinoWithRecursive(int pow, int seq);

// Description : 이항 계수를 동적 계획 방법으로 구한다 
// Parameters 
// { 
//      pow : 대상인 식의 제곱 수 
//      seq : 몇번 째 항의 값을 구할지 정함
// }
int getBinoWithDynamic(int pow , int seq);

// UTILITY METHODS
// 1차원 배열 출력 
void prfArr(int *a);
// 2차원 배열 출력
void prfMatrix(int **a, int height , int width);
// 0으로 채워진 배열을 만듦
int* getZeroArr(int length);
// 둘 중 작은 값을 구함
int min(int a , int b);

int main (){
    int pow = 3;
    int seq = 

    // RECURSIVE
    printf("############## GET BINOMIAL WITH RECURSIVE ################\n");

    clock_t recurv = clock();
    
    int ret_recur = getBinoWithRecursive(pow , seq -1);
    
    printf("\n############################\n");
    printf("RESULT : %d\n", ret_recur);
    printf("DURATION : %lums\n" , (clock() - recurv));
    printf("############################\n");
    printf("\n\n");
    printf("########## GET BINOMIAL WITH DYNAMIC PROGRAMMING ##########\n");

    clock_t dp = clock();
    int ret_dp = getBinoWithDynamic(pow , seq);
    printf("\n############################\n");
    printf("RESULT : %d\n", ret_dp);
    printf("DURATION : %lums" , (clock() - dp));
    printf("\n############################\n");
    return 0;
}

int getBinoWithRecursive(int pow, int seq){
    printf("recursive method called!! pow : %d seq : %d\n" , pow , seq);
    if(seq == 0 || pow == seq) 
    {
        printf("recursive return 1\n");
        return 1;
    }
    else 
    {   
        int left = getBinoWithRecursive(pow - 1, seq -1);
        printf("left recursive method completed pow : %d seq : %d\n", pow,seq);
        int right = getBinoWithRecursive(pow - 1, seq);
        printf("right recursive method completed pow : %d seq : %d \n", pow ,seq);
        int result = left + right;
        printf("recursive method completed pow : %d seq : %d\n", pow,seq);
        return result;
    }
}

int getBinoWithDynamic(int pow , int seq){
    printf("methods called ! power : %d sequence number : %d\n" , pow , seq); 
    int **arr = (int**)malloc(sizeof(int*) * (pow + 1)); 
    int temp = 0 ;
    for(int i = 0 ; i <= pow ; i++){
        arr[i] = getZeroArr(seq);

        for(int j = 0 ; j <= min(seq , i); j++){
            if(j == 0 || j == pow){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }
    prfMatrix(arr, pow + 1 , seq);
    return arr[pow][seq-1];
}

// UTILITY METHODS 
int min(int a , int b){
    if(a > b) return b;
    else return a;
}

void prfArr (int *a){
    int size = sizeof(*a);
    printf("{");
    for(int i = 0 ; i <= size ; i++){
        printf(" %d", a[i]);
        if(i <= size-1) printf(",");
    }
    printf(" }\n");
}

void prfMatrix(int **a, int height , int width){
    printf("[\n");
    for(int i = 0 ; i < height ; i++){
        printf("{");
        for(int j = 0 ; j < width ; j++){
            printf("%d", a[i][j]);
            if(j < width -1) printf(",");
        }
        printf("}\n");
    }
    printf("]\n");
}

int* getZeroArr(int length){
    int *arr = (int*)malloc(sizeof(int) * length);
    for(int i = 0 ; i < length ; i++){
        arr[i] = 0;
    }
    return arr;
}