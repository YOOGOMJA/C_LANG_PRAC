#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 프로그램 실행시 
// 종료 / 대기 / 삽입 / 삭제 / 출력을 위한 코드 값을 
// 열거형으로 선언
enum running_mode
{
	MODE_EXIT = -1,	// 종료 (-1)
	MODE_IDLE,			// 대기 (0)
	MODE_INSERT_QUEUE,	// 삽입 (1)
	MODE_DELETE_QUEUE,	// 삭제 (2)
	MODE_PRINT_QUEUE	// 출력 (3)
};

#pragma region Struct

// 큐에 들어갈 노드 구조체
typedef struct Node {
	// 이름이 저장될 문자열
	char name[10];
	// 본 노드의 뒤에올 노드의 주소
	struct Node* link;
}Node;

// 연결 큐 
typedef struct Queue {
	// 큐의 가장 앞에 위치한 노드의 ^주소
	Node *first;
	// 큐의 가장 뒤에 위치한 노드의 ^주소
	Node *rear;
	// 큐에 저장된 노드의 갯수 
	int count;

	// # NOTE
	// 큐가 관리 되기 위해서는 큐의 가장 앞에 저장된 
	// 노드의 주소가 필요합니다.
	// 그 이후부터는 각 노드가 자신의 뒤쪽에 위치한 노드의
	// 주소를 기억하고 있기 때문에 각 노드들이 연결되어 있음을 
	// 알 수 있습니다. 
	// rear 노드는, 노드를 새로 생성해 큐에 삽입할때
	// 큐의 가장 뒤에 위치시켜야하므로 추가했습니다.
}Queue;

#pragma endregion

// 전달 받은 큐를 초기화 한다
void initQueue(Queue *queue) {
	queue->first = NULL;
	queue->count = 0;
}

// 큐에 노드를 삽입
// 노드를 삽입할 큐의 주소와 생성한 노드에 저장할 문자열을 
// 입력받는다.
void insertQueue(Queue *queue, char insertName[10]) {
	printf("INSERT QUEUE \n");
	// Node의 크기만큼 ( sizeof(struct Node)) )
	// 공간을 만들고 malloc()
	// 새로운 Node를 선언 후 초기화 한다.
	Node *current = (Node *)malloc(sizeof(struct Node));
	// 입력받은 문자열을 생성한 노드에 복사한다.
	// 문자열은 a = 1; 같은 식으로 삽입할 수 없다. 
	// string.h 에 포함된 strcpy_s함수를 사용해 복사하도록한다.
	strcpy_s(current->name, 10, insertName);
	// 방금 생성한 노드가 큐의 가장 뒤에 위치하기때문에 link는 NULL
	current->link = NULL;

	// 큐에 아직 아무것도 들어있지 않은 경우
	if (queue->count == 0) {
		// 큐의 첫번째 노드로 방금 생성한 노드를 저장합니다.
		queue->first = current;
	}
	// 큐에 이미 노드가 들어가있는 경우 
	else {
		// 큐의 마지막에 들어있는 노드의 link에 현재 노드를 저장합니다
		queue->rear->link = current;
	}

	// 큐의 맨 마지막 노드를 현재 노드로 지정합니다.
	queue->rear = current;
	// 큐의 노드 개수를 +1 합니다.
	queue->count++;

	printf("큐에 노드가 추가되었습니다.\n");


	// # NOTE
	// 큐가 비어있을 경우에는 큐의 first 노드로 현재 노드를 등록합니다.
	// 비어있지 않은 경우에는 큐의 마지막 노드의 다음 노드로 현재 노드를 
	// 지정해줍니다. (line 78)
	// 연결 리스트는 각 노드가 자신의 다음 노드의 주소를 알고 있어야합니다.
}

// 큐에 들어있는 노드를 삭제합니다.
// 먼저 들어온 노드를 먼저 삭제합니다. (FIFO)
void deleteQueue(Queue *queue) {
	printf("DELETE QUEUE \n");

	// 큐가 비어있는 경우
	if (queue->count == 0) { printf("큐가 비어있습니다.\n"); return; }
	// 큐가 비어있지 않은 경우 
	else {
		// 삭제할 노드를 선언 합니다.
		Node *target;

		// 선언한 노드에 큐에 가장 앞에 있는 노드를 초기화합니다.
		target = queue->first;
		// 큐의 가장 앞 노드로 target(삭제할 노드)의 link(다음 노드)를 지정합니다.
		queue->first = target->link;
		// 지정한 노드를 메모리 해제 합니다.
		free(target);
		// 큐의 총 갯수를 -1 합니다.
		queue->count--;

		printf("큐의 노드가 삭제되었습니다.\n");
	}

	// # NOTE
	// 본 연결 큐는 먼저 삽입된 노드를 먼저 삭제 하도록 설계하기로 하였기 때문에,
	// 삭제시 큐의 가장 앞에있는 노드를 삭제하고 삭제한 노드의 다음 노드 (link)를
	// 큐의 first 노드로 지정하게 됩니다. 
}

// 큐에 관련된 정보를 모두 표기합니다.
// 큐의 크기 , 큐의 첫째노드의 주소 , 큐의 마지막 노드의 주소 
// 큐에 들어있는 모든 노드의 정보들을 출력합니다.
void printQueue(Queue *queue) {

	// 큐가 비어있으면 출력하지 않습니다.
	if (queue->count == 0) { printf("큐가 비어있습니다.\n"); }
	else {
		// 최초로 정보를 출력할 노드를 선언 및 초기화합니다.
		Node *current = queue->first;

		// 노드 정보를 표기하기 시작합니다.
		printf("## QUEUE INFO ##\n");
		// 정수는 %d , 포인터는 %p로 출력합니다.
		printf("LENGTH : %d | QUEUE FIRST NODE ADDRESS : %p | REAR NODE ADDRESS : %p\n", queue->count, queue->first, queue->rear);

		// 현재 노드의 포인터가 NULL이 아닌동안 계속 해 반복합니다.
		while (current != NULL) {
			// 현재 노드의 정보를 입력합니다.
			printf("ADDRESS : %p | NAME : %s | LINK ADDRESS : %p \n", current, current->name, current->link);
			// current에 현재 노드의 다음에 위치한 노드의 주소를 덮어씌웁니다.
			current = current->link;
		}

		// # NOTE 
		// 다음과 같은 이유로 위의 반복문을 실행합니다.
		// 전제 1) 큐에 저장된 가장 첫 노드의 주소를 알고 
		// 전제 2) 각 노드는 자신의 뒤에 저장된 노드의 추소를 알기때문에 
		// 1. 빈 노드(current)를 선언하고
		// 2. 큐의 가장 첫 노드를 빈 노드(current)에 초기화합니다.
		// 3. 해당 노드를 출력한 다음에는 현재 노드(current = queue->first)의
		//	다음 노드(link)를 current에 덮어씌웁니다.
		// 4. 이 작업을 current != NULL 이라는 조건으로 반복하면
		//	마지막 노드가 되었을때 link에 들어있는 NULL을 current에 삽입 후 
		//	반복문이 종료되게 됩니다.
	}
}

void main() {
	// 입력 모드를 관리하기 위한 모드입니다.
	int mode = MODE_IDLE;

	// 큐를 선언합니다.
	Queue queue;
	// 큐를 초기화합니다. 
	initQueue(&queue);

	// 종료하기 전까지 입력을 계속해 받습니다.
	while (mode >= 0) {
		printf("%d : InsertQ \n%d : deleteQ \n3 : 출력 \n-1 : 종료  ...? \nchoose : ", MODE_INSERT_QUEUE, MODE_DELETE_QUEUE);
		scanf_s("%d", &mode);

		if (mode == MODE_INSERT_QUEUE) {
			// 임의의 이름을 생성해줍니다.
			char name[10] = "PERSON";
			// 큐를 삽입합니다.
			insertQueue(&queue, name);
		}
		else if (mode == MODE_DELETE_QUEUE) {
			// 큐를 삭제합니다.
			deleteQueue(&queue);
		}
		else if (mode == MODE_EXIT) {
			// 현재 프로그램을 완전히 종료합니다.
			printf("종료합니다.  \n");
		}
		else if (mode == MODE_PRINT_QUEUE) {
			// 큐의 정보를 출력합니다.
			printQueue(&queue);
		}
		else {
			// 지정된 모드의 값을 벗어난 경우입니다.
			// 오류를 줄이기 위해 입력을 막습니다.
			printf("잘못된 입력입니다 : %d\n", mode);
			mode = MODE_IDLE;
		}
	}
	return;
}

