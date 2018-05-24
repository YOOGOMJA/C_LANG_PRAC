#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

<<<<<<< HEAD
// queen ì‹¤í–‰ í•¨ìˆ˜ 
void queen(int idx);
// íŒë‹¨ í•¨ìˆ˜ 	
bool promising(int idx);
// ê²°ê³¼ ì¶œë ¥ í•¨ìˆ˜ 
void prtResult(int type);
// ê²°ê³¼ ì¶œë ¥ í•¨ìˆ˜ 2
void prtSimple();
// ìµœì´ˆ ë°°ì—´ ì„ ì–¸
=======
void queen(int idx);
bool promising(int idx);
void prtResult();
void prtSimple();
>>>>>>> dc052271fc4b642b8aa6b9109dc6ec0d9965d5e1
void initArr(int length);

int *columns;
#define COLUMNS_LENGTH 4

int main() {
<<<<<<< HEAD
	initArr(COLUMNS_LENGTH);
	prtResult(1);
	queen(0);

=======
	
	initArr(COLUMNS_LENGTH);
	prtResult();

	queen(0);
	
>>>>>>> dc052271fc4b642b8aa6b9109dc6ec0d9965d5e1
	return 0;
}

void queen(int idx) {
<<<<<<< HEAD
	if (promising(idx)) {
		if (idx == COLUMNS_LENGTH) {
			prtResult(0);
			prtSimple();
			printf("## finished\n");

			exit(1);
		}
		else {
=======
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
>>>>>>> dc052271fc4b642b8aa6b9109dc6ec0d9965d5e1
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
<<<<<<< HEAD
			flag = false;	
=======
			//printf("[FAIL] search : %d column[search] : [%d] idx : %d column[idx]: [%d] flag : %d\n", search, columns[search], idx, columns[idx], flag);
			flag = false;
			
		}
		else {
			//printf("[FINE] search : %d column[search] : [%d] idx : %d column[idx]: [%d] flag : %d\n", search, columns[search], idx, columns[idx], flag);
>>>>>>> dc052271fc4b642b8aa6b9109dc6ec0d9965d5e1
		}
		search++;
	}
	return flag;
}

<<<<<<< HEAD
void prtResult(int type) {
	if(type == 0){
		printf("###### RESULT ######\n\n");
	}
	else{
		printf("#### INIT ARRY ####\n\n");
	}
=======
void prtResult() {
	printf("###### RESULT ######\n\n");
>>>>>>> dc052271fc4b642b8aa6b9109dc6ec0d9965d5e1
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
<<<<<<< HEAD
	printf("Actual Array : { ");
=======
	printf("Array : { ");
>>>>>>> dc052271fc4b642b8aa6b9109dc6ec0d9965d5e1
	for (int i = 0; i <= length; i++) {
		columns[i] = 0;
		printf("%d", columns[i]);
		if (i < length) { printf(", "); }
	}
	printf(" }\n");
}
<<<<<<< HEAD
=======

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

int promising(int i) { // Á÷¼±, ´ë°¢¼±À¸·Î ¸¸³ª´ÂÁö °Ë»ç
	int k = 1, promising = 1;
	while (k < i && promising) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k))
			promising = 0;
		k++;
	}
	return promising;
}

*/
>>>>>>> dc052271fc4b642b8aa6b9109dc6ec0d9965d5e1
