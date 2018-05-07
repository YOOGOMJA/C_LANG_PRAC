#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void queen(int idx);
bool promising(int idx);
void prtResult();
void prtSimple();
void initArr(int length);

int *columns;
#define COLUMNS_LENGTH 4

int main() {
	
	initArr(COLUMNS_LENGTH);
	prtResult();

	queen(0);
	
	return 0;
}

void queen(int idx) {
	//printf("QUEEN METHODS CALLED : [%d]\n" , idx);
	prtSimple();
	if (promising(idx)) {
		
		//printf("# PROMISED! idx : %d col : %d\n", idx, columns[idx]);
		if (idx == COLUMNS_LENGTH) {
			prtResult();
			printf("## finished\n");
			prtSimple();
		}
		else {
			//printf("## make branches!! idx : %d  col : %d\n", idx, columns[idx]);
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
			//printf("[FAIL] search : %d column[search] : [%d] idx : %d column[idx]: [%d] flag : %d\n", search, columns[search], idx, columns[idx], flag);
			flag = false;
			
		}
		else {
			//printf("[FINE] search : %d column[search] : [%d] idx : %d column[idx]: [%d] flag : %d\n", search, columns[search], idx, columns[idx], flag);
		}
		search++;
	}
	return flag;
}

void prtResult() {
	printf("###### RESULT ######\n\n");
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
	printf("Array : { ");
	for (int i = 0; i <= length; i++) {
		columns[i] = 0;
		printf("%d", columns[i]);
		if (i < length) { printf(", "); }
	}
	printf(" }\n");
}

/*

#include <stdio.h>
#include <stdlib.h>

void queens(int);
int promising(int);
int n;
int col[255] = { 0, };

FILE *inputFile, *outputFile;

int main() {
	char fileName[255];
	printf("input num? ");
	scanf("%d", &n);
	queens(0);
}

void printResult() {
	int i;
	printf("result : ");
	for (i = 1; i <= n; i++) printf("%d ", col[i]);
	exit(1);
}

void queens(int i) {
	int j;
	if (promising(i)) {
		if (i == n) printResult();
		else
			for (j = 1; j <= n; j++) {
				col[i + 1] = j;
				queens(i + 1);
			}
	}
}

int promising(int i) { // 직선, 대각선으로 만나는지 검사
	int k = 1, promising = 1;
	while (k < i && promising) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k))
			promising = 0;
		k++;
	}
	return promising;
}

*/