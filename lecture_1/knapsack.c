#include <stdio.h>
#include <stdlib.h>

#define KNAPSACK_MAX_WEIGHT             19
#define KNAPSACK_ITEM_CNT         5

//int profits[KNAPSACK_ITEM_CNT + 1] = { 0, 40      ,30           ,50           ,10 };
//int weights[KNAPSACK_ITEM_CNT + 1] = { 0, 2      ,5            ,10           ,5 };
int profits[KNAPSACK_ITEM_CNT + 1] = { 0,20,30,35,12,3 };
int weights[KNAPSACK_ITEM_CNT + 1] = { 0,2,5,7,3,1 };
int include[KNAPSACK_ITEM_CNT + 1] = { 0, };
int bestset[KNAPSACK_ITEM_CNT + 1] = { 0, };
int selected[KNAPSACK_ITEM_CNT + 1] = { 0, };
int numbest, maxprofit;

void knapsack(int idx , int profit , int weight);
int promising(int idx , int profit , int weight);

int main() {

    numbest = 0;
    maxprofit = 0;

    knapsack(0, 0 ,0);

    printf("\n\n## MAX PROFIT : %d\n", maxprofit);
    printf("## BEST SET : \n{ ");
    for (int i = 1; i <= KNAPSACK_ITEM_CNT; i++) {
            printf("%d", bestset[i]);
            if (i < KNAPSACK_ITEM_CNT) { printf(" , "); }
    }
    printf(" }\n");
    return 0;
}
 
void knapsack(int idx, int profit, int weight) {
       
    printf("\n[KNAPSACK][CALLED] (%d,%d,%d)", idx, profit, weight);

    if (weight < KNAPSACK_MAX_WEIGHT && profit > maxprofit) {
            maxprofit = profit;
            numbest = idx;

            for (int i = 0; i < KNAPSACK_ITEM_CNT; i++) {
                    bestset[i] = include[i];
            }
    }

    if (promising(idx , profit , weight)) {
            printf("\n[KNAPSACK][CHK] PROMISING");

            include[idx + 1] = 1;
            knapsack(idx + 1, profit + profits[idx + 1], weight + weights[idx + 1]);
            include[idx + 1] = 0;
            knapsack(idx + 1, profit, weight);

    }
    else {
            printf("\n[KNAPSACK][CHK] NOT PROMISING");
    }

}
int promising(int idx, int profit , int weight) {
    int totWeight; // 총 무게
    float bound; // 경계값

    if (weight >= KNAPSACK_MAX_WEIGHT) {
        printf("\n[PROMISING] NOT PROMISING. weight is not enough");
        return 0;
    }
    else {
        // promising한지 확인
        int j = idx + 1;
        bound = (float)profit;
        totWeight = weight;
        while (j <= KNAPSACK_ITEM_CNT && (totWeight + weights[j] <= KNAPSACK_MAX_WEIGHT)) {
                totWeight = totWeight + weights[j];
                bound = bound + profits[j];
                j++;
        }
        printf("%  .2f %  .2f", bound, maxprofit);

        int k = j;
        if (k <= KNAPSACK_ITEM_CNT) {
            bound += (float)(KNAPSACK_MAX_WEIGHT - totWeight) * (profits[k] / weights[k]);
            printf("%  .2f %  .2f", bound, maxprofit);
        }
    }
    return (bound > maxprofit);
}
