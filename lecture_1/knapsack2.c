#include <stdio.h>
#include <stdlib.h>
// STRUCT START
typedef struct Node {
	int level;
    int weight;
    int profit;
	struct Node* link;
}Node;

typedef struct Queue{
    struct Node* first;
    struct Node* rear;
    int count;
}Queue;
// STRUCT END

// QUEUE METHOD START
void enqueue(Queue* _queue, int profit, int weight , int level);
Node* dequeue(Queue* _queue);
void initQueue(Queue* _queue);
void printQueue(Queue* _queue);
// QUEUE METHOD END

// KNAPSACK START
#define KNAPSACK_CNT 5
#define KNAPSACK_MAX_WEIGHT 13
int P[6] = { 0, 20, 30, 35, 13 , 3 };
int W[6] = { 0, 2, 5, 7, 3 ,1 };
void knapsack2();
int promising();
// KNAPSACK END

// GLOBAL VARIABLE
Queue* queue;
// GLOBAL VARIABLE

int main(){
    initQueue(queue);
    printQueue(queue);
}



void initQueue(Queue* _queue){  
    _queue = (Queue *)malloc(sizeof(struct Queue));
    _queue->count = 0;
}

void enqueue(Queue* _queue , int profit, int weight , int level){
    Node* current = (Node *)malloc(sizeof(struct Node));
    
    current->level = level;
    current->profit = profit;
    current->weight = weight;
    current->link = NULL;

	if (queue->count == 0) {
		queue->first = current;
	}
	else {
		queue->rear->link = current;
	}
	queue->rear = current;
	queue->count++;
}

Node* dequeue(Queue* _queue){
    if (queue->count == 0) { printf("Queue is empty.\n"); return; }
	
	else {
		Node *target;
		target = queue->first;
		queue->first = target->link;
		queue->count--;
        target->link = NULL;
        return target;
	}
}

void printQueue(Queue* _queue){
    if (queue->count == 0) { printf("QUEUE IS EMPTY.\n"); }
	else {
		Node *current = queue->first;
		printf("## QUEUE INFO ##\n");
		printf("LENGTH : %d | QUEUE FIRST NODE ADDRESS : %p | REAR NODE ADDRESS : %p\n", queue->count , queue->first , queue->rear);
		
		while (current != NULL) {
			printf("ADDRESS : %p | LEVEL : %d | LINK ADDRESS : %p \n", current, current->level, current->link);
			current = current->link;
		}
    }
}



// KNAPSACK
