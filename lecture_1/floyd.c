#include<stdio.h>
#include<stdlib.h>

#define MAX         999
int graph[5][5] = {
    { 0,    1,      MAX,    1,      5    },
    { 9,    0,      3,      2,      MAX  },
    { MAX,  MAX,    0,      4,      MAX  },
    { MAX,  MAX,    2,      0,      3    },
    { 5,    MAX,    MAX,    MAX,    0    }
};

int* getZeroArr(int width, int height);
void floyd(int width , int target[5][5], int result[][]);
void prfMatrix(int **a, int height , int width);

int main(){
    int** ret;
    floyd(5, graph, ret); 
    prfMatrix(ret, 5, 5);
    return 0;
}


void floyd(int width , int target[5][5] , int result[][]){
    result = target;
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


