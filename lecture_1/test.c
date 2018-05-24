#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���α׷� ����� 
// ���� / ��� / ���� / ���� / ����� ���� �ڵ� ���� 
// ���������� ����
enum running_mode
{
	MODE_EXIT = -1,	// ���� (-1)
	MODE_IDLE,			// ��� (0)
	MODE_INSERT_QUEUE,	// ���� (1)
	MODE_DELETE_QUEUE,	// ���� (2)
	MODE_PRINT_QUEUE	// ��� (3)
};

#pragma region Struct

// ť�� �� ��� ����ü
typedef struct Node {
	// �̸��� ����� ���ڿ�
	char name[10];
	// �� ����� �ڿ��� ����� �ּ�
	struct Node* link;
}Node;

// ���� ť 
typedef struct Queue {
	// ť�� ���� �տ� ��ġ�� ����� ^�ּ�
	Node *first;
	// ť�� ���� �ڿ� ��ġ�� ����� ^�ּ�
	Node *rear;
	// ť�� ����� ����� ���� 
	int count;

	// # NOTE
	// ť�� ���� �Ǳ� ���ؼ��� ť�� ���� �տ� ����� 
	// ����� �ּҰ� �ʿ��մϴ�.
	// �� ���ĺ��ʹ� �� ��尡 �ڽ��� ���ʿ� ��ġ�� �����
	// �ּҸ� ����ϰ� �ֱ� ������ �� ������ ����Ǿ� ������ 
	// �� �� �ֽ��ϴ�. 
	// rear ����, ��带 ���� ������ ť�� �����Ҷ�
	// ť�� ���� �ڿ� ��ġ���Ѿ��ϹǷ� �߰��߽��ϴ�.
}Queue;

#pragma endregion

// ���� ���� ť�� �ʱ�ȭ �Ѵ�
void initQueue(Queue *queue) {
	queue->first = NULL;
	queue->count = 0;
}

// ť�� ��带 ����
// ��带 ������ ť�� �ּҿ� ������ ��忡 ������ ���ڿ��� 
// �Է¹޴´�.
void insertQueue(Queue *queue, char insertName[10]) {
	printf("INSERT QUEUE \n");
	// Node�� ũ�⸸ŭ ( sizeof(struct Node)) )
	// ������ ����� malloc()
	// ���ο� Node�� ���� �� �ʱ�ȭ �Ѵ�.
	Node *current = (Node *)malloc(sizeof(struct Node));
	// �Է¹��� ���ڿ��� ������ ��忡 �����Ѵ�.
	// ���ڿ��� a = 1; ���� ������ ������ �� ����. 
	// string.h �� ���Ե� strcpy_s�Լ��� ����� �����ϵ����Ѵ�.
	strcpy_s(current->name, 10, insertName);
	// ��� ������ ��尡 ť�� ���� �ڿ� ��ġ�ϱ⶧���� link�� NULL
	current->link = NULL;

	// ť�� ���� �ƹ��͵� ������� ���� ���
	if (queue->count == 0) {
		// ť�� ù��° ���� ��� ������ ��带 �����մϴ�.
		queue->first = current;
	}
	// ť�� �̹� ��尡 ���ִ� ��� 
	else {
		// ť�� �������� ����ִ� ����� link�� ���� ��带 �����մϴ�
		queue->rear->link = current;
	}

	// ť�� �� ������ ��带 ���� ���� �����մϴ�.
	queue->rear = current;
	// ť�� ��� ������ +1 �մϴ�.
	queue->count++;

	printf("ť�� ��尡 �߰��Ǿ����ϴ�.\n");


	// # NOTE
	// ť�� ������� ��쿡�� ť�� first ���� ���� ��带 ����մϴ�.
	// ������� ���� ��쿡�� ť�� ������ ����� ���� ���� ���� ��带 
	// �������ݴϴ�. (line 78)
	// ���� ����Ʈ�� �� ��尡 �ڽ��� ���� ����� �ּҸ� �˰� �־���մϴ�.
}

// ť�� ����ִ� ��带 �����մϴ�.
// ���� ���� ��带 ���� �����մϴ�. (FIFO)
void deleteQueue(Queue *queue) {
	printf("DELETE QUEUE \n");

	// ť�� ����ִ� ���
	if (queue->count == 0) { printf("ť�� ����ֽ��ϴ�.\n"); return; }
	// ť�� ������� ���� ��� 
	else {
		// ������ ��带 ���� �մϴ�.
		Node *target;

		// ������ ��忡 ť�� ���� �տ� �ִ� ��带 �ʱ�ȭ�մϴ�.
		target = queue->first;
		// ť�� ���� �� ���� target(������ ���)�� link(���� ���)�� �����մϴ�.
		queue->first = target->link;
		// ������ ��带 �޸� ���� �մϴ�.
		free(target);
		// ť�� �� ������ -1 �մϴ�.
		queue->count--;

		printf("ť�� ��尡 �����Ǿ����ϴ�.\n");
	}

	// # NOTE
	// �� ���� ť�� ���� ���Ե� ��带 ���� ���� �ϵ��� �����ϱ�� �Ͽ��� ������,
	// ������ ť�� ���� �տ��ִ� ��带 �����ϰ� ������ ����� ���� ��� (link)��
	// ť�� first ���� �����ϰ� �˴ϴ�. 
}

// ť�� ���õ� ������ ��� ǥ���մϴ�.
// ť�� ũ�� , ť�� ù°����� �ּ� , ť�� ������ ����� �ּ� 
// ť�� ����ִ� ��� ����� �������� ����մϴ�.
void printQueue(Queue *queue) {

	// ť�� ��������� ������� �ʽ��ϴ�.
	if (queue->count == 0) { printf("ť�� ����ֽ��ϴ�.\n"); }
	else {
		// ���ʷ� ������ ����� ��带 ���� �� �ʱ�ȭ�մϴ�.
		Node *current = queue->first;

		// ��� ������ ǥ���ϱ� �����մϴ�.
		printf("## QUEUE INFO ##\n");
		// ������ %d , �����ʹ� %p�� ����մϴ�.
		printf("LENGTH : %d | QUEUE FIRST NODE ADDRESS : %p | REAR NODE ADDRESS : %p\n", queue->count, queue->first, queue->rear);

		// ���� ����� �����Ͱ� NULL�� �ƴѵ��� ��� �� �ݺ��մϴ�.
		while (current != NULL) {
			// ���� ����� ������ �Է��մϴ�.
			printf("ADDRESS : %p | NAME : %s | LINK ADDRESS : %p \n", current, current->name, current->link);
			// current�� ���� ����� ������ ��ġ�� ����� �ּҸ� �����ϴ�.
			current = current->link;
		}

		// # NOTE 
		// ������ ���� ������ ���� �ݺ����� �����մϴ�.
		// ���� 1) ť�� ����� ���� ù ����� �ּҸ� �˰� 
		// ���� 2) �� ���� �ڽ��� �ڿ� ����� ����� �߼Ҹ� �˱⶧���� 
		// 1. �� ���(current)�� �����ϰ�
		// 2. ť�� ���� ù ��带 �� ���(current)�� �ʱ�ȭ�մϴ�.
		// 3. �ش� ��带 ����� �������� ���� ���(current = queue->first)��
		//	���� ���(link)�� current�� �����ϴ�.
		// 4. �� �۾��� current != NULL �̶�� �������� �ݺ��ϸ�
		//	������ ��尡 �Ǿ����� link�� ����ִ� NULL�� current�� ���� �� 
		//	�ݺ����� ����ǰ� �˴ϴ�.
	}
}

void main() {
	// �Է� ��带 �����ϱ� ���� ����Դϴ�.
	int mode = MODE_IDLE;

	// ť�� �����մϴ�.
	Queue queue;
	// ť�� �ʱ�ȭ�մϴ�. 
	initQueue(&queue);

	// �����ϱ� ������ �Է��� ����� �޽��ϴ�.
	while (mode >= 0) {
		printf("%d : InsertQ \n%d : deleteQ \n3 : ��� \n-1 : ����  ...? \nchoose : ", MODE_INSERT_QUEUE, MODE_DELETE_QUEUE);
		scanf_s("%d", &mode);

		if (mode == MODE_INSERT_QUEUE) {
			// ������ �̸��� �������ݴϴ�.
			char name[10] = "PERSON";
			// ť�� �����մϴ�.
			insertQueue(&queue, name);
		}
		else if (mode == MODE_DELETE_QUEUE) {
			// ť�� �����մϴ�.
			deleteQueue(&queue);
		}
		else if (mode == MODE_EXIT) {
			// ���� ���α׷��� ������ �����մϴ�.
			printf("�����մϴ�.  \n");
		}
		else if (mode == MODE_PRINT_QUEUE) {
			// ť�� ������ ����մϴ�.
			printQueue(&queue);
		}
		else {
			// ������ ����� ���� ��� ����Դϴ�.
			// ������ ���̱� ���� �Է��� �����ϴ�.
			printf("�߸��� �Է��Դϴ� : %d\n", mode);
			mode = MODE_IDLE;
		}
	}
	return;
}

