#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// queen 실행 함수 
void queen(int idx);
// 판단 함수 	
bool promising(int idx);
// 결과 출력 함수 
void prtResult(int type);
// 결과 출력 함수 2
void prtSimple();
// 최초 배열 선언
void initArr(int length);

int *columns;
#define COLUMNS_LENGTH 4

int main() {
	initArr(COLUMNS_LENGTH);
	prtResult(1);
	queen(0);

	return 0;
}

void queen(int idx) {
	if (promising(idx)) {
		if (idx == COLUMNS_LENGTH) {
			prtResult(0);
			prtSimple();
			printf("## finished\n");

			exit(1);
		}
		else {
			for (int i = 1; i <= COLUMNS_LENGTH; i++) {
				columns[idx + 1] = i;
				queen(idx + 1);
			}
		}
	}
}

bool promising(int idx) {
	bool flag = true;
	int search = 1;
	while (search < idx && flag) {
		bool condition_1 = columns[idx] == columns[search];
		bool condition_2 = abs(columns[idx] - columns[search]) == abs(idx - search);
		if (condition_1 || condition_2) {
			flag = false;	
		}
		search++;
	}
	return flag;
}

void prtResult(int type) {
	if(type == 0){
		printf("###### RESULT ######\n\n");
	}
	else{
		printf("#### INIT ARRY ####\n\n");
	}
	for (int row = 1; row <= COLUMNS_LENGTH; row++) {
		printf("      ");
		for (int column = 1; column <= COLUMNS_LENGTH; column++) {
			if (columns[row] == column) {
				printf("O");
			}
			else {
				printf("#");
			}
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");
	printf("####################\n\n");
}

void prtSimple() {
	printf("Array : { ");
	for (int i = 1; i <= COLUMNS_LENGTH; i++) {
		printf("%d", columns[i]);
		if (i < COLUMNS_LENGTH) { printf(", "); }
	}
	printf(" }\n");
}

void initArr(int length) {
	columns = (int *)malloc(sizeof(int) * length);
	printf("Actual Array : { ");
	for (int i = 0; i <= length; i++) {
		columns[i] = 0;
		printf("%d", columns[i]);
		if (i < length) { printf(", "); }
	}
	printf(" }\n");
}
