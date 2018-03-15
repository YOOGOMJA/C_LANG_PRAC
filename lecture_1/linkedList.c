#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum running_mode
{
	MODE_EXIT = -1 ,	// ���� ������
	MODE_IDLE,			// ��� 
	MODE_INSERT_QUEUE,	// ����
	MODE_DELETE_QUEUE,	// ���� 
	MODE_PRINT_QUEUE
};

#pragma region Struct

typedef struct Node {
	char name[10];
	struct Node* link;
}Node;


typedef struct Queue {
	Node *first;
	Node *rear;
	int count;
}Queue;

#pragma endregion

void initQueue(Queue *queue) {
	queue->first = NULL;
	queue->count = 0;
}

void insertQueue(Queue *queue , char insertName[10]) {
	printf("INSERT QUEUE \n");

	Node *current = (Node *)malloc(sizeof(struct Node));
	strcpy_s(current->name, 10, insertName);
	current->link = NULL;

	if (queue->count == 0) {
		queue->first = current;
	}
	else {
		queue->rear->link = current;
	}

	queue->rear = current;
	queue->count++;

	printf("ť�� ��尡 �߰��Ǿ����ϴ�.\n");
}

void deleteQueue(Queue *queue) {
	printf("DELETE QUEUE \n");

	if (queue->count == 0) { printf("ť�� ����ֽ��ϴ�.\n"); return; }
	else {
		Node *target;
		
		target = queue->first;
		queue->first = target->link;
		free(target);
		queue->count--;

		printf("ť�� ��尡 �����Ǿ����ϴ�.\n");
	}
}

void printQueue(Queue *queue) {
	
	if (queue->count == 0) { printf("ť�� ����ֽ��ϴ�.\n"); }
	else {
		Node *current = queue->first;
		int is_finished = 0;

		printf("## QUEUE INFO ##\n");
		printf("LENGTH : %d | QUEUE FIRST NODE ADDRESS : %p | REAR NODE ADDRESS : %p\n", queue->count , queue->first , queue->rear);
		
		while (current != NULL) {
			printf("ADDRESS : %p | NAME : %s | LINK ADDRESS : %p \n", current, current->name, current->link);
			current = current->link;
		}
	} 
}

void main() {
	int mode = MODE_IDLE;

	Queue queue;
	initQueue(&queue);

	while (mode >= 0) {
		printf("%d : InsertQ \n%d : deleteQ \n3 : ��� \n-1 : ����  ...? \nchoose : " , MODE_INSERT_QUEUE , MODE_DELETE_QUEUE);
		scanf_s("%d" , &mode);
		
		if (mode == MODE_INSERT_QUEUE) {
			char name[10] = "PERSON";
			insertQueue(&queue , name);
		}
		else if (mode == MODE_DELETE_QUEUE) {
			deleteQueue(&queue);
		}
		else if (mode == MODE_EXIT) {
			printf("�����մϴ�.  \n");
		}
		else if (mode == MODE_PRINT_QUEUE) {
			printQueue(&queue);
		}
		else {
			printf("�߸��� �Է��Դϴ� : %d\n", mode);
			mode = MODE_IDLE;
		}
	}
	return;
}

