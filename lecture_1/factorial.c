#include <stdio.h>
#include <time.h>

enum algorithm_types { TYPES_REPETITION , TYPES_RECURSION };

/*
	DESCRPTION		:	반복적 알고리즘을 이용해 팩토리얼을 구합니다.
	PARAMETERS	
		num		int	:	해당 수 만큼의 팩토리얼을 구합니다
*/
unsigned long long repetition(int num) {
	unsigned long long result = 1;

	for (int i = 1; i <= num; i++) {
		result *= i;
		printf("repetition track [%d] : %llu\n", i, result);
	}

	return result;
}

/*
	DESCRPTION		:	재귀적 알고리즘을 이용해 팩토리얼을 구합니다
	PARAMETERS
		num		int	:	해당 수 만큼의 팩토리얼을 구합니다
*/
unsigned long long recursion(int num) {
	unsigned long long result = 1;
	
	if (num <= 1) { 
		printf("recursion track last node\n");
		return 1;
	}
	else { 
		result = num * recursion(num - 1); 
		printf("recursion track [%d] : %llu\n", num, result);
	}
	
	return result;
}

/*
	DESCRIPTION		:	재귀적 알고리즘과 반복적 알고리즘 함수를 
						분기에 따라 실행합니다.
	PARAMETERS
		type	int	:	algorithm_types 열거형 값을 받습니다.
*/
void exec(int type) {
	int num = 1;

	// 타입에 따라 다른 제목을 출력합니다.
	if (type == TYPES_REPETITION) 	printf("##### FACTORIAL WITH REPETITON \n\n");
	else if (type == TYPES_RECURSION) printf("##### FACTORIAL WITH RECURSION \n\n");
	else return;
	
	// 여러번 결과를 출력받기 위해 반복문을 사용합니다.
	while (num >= 1) {
		// 팩토리얼 결과를 얻을 수를 입력받습니다.
		printf("please insert number to calculate factorial\n");
		printf("(if you want finished this process, insert 0 or smaller number than 0)\n : ");
		scanf_s("%d", &num);

		if (num >= 1) {			
			// 실행 시작시간을 저장하기 위한 변수입니다.
			clock_t started;
			// 총 실행시간을 저장하기 위한 변수입니다.
			double duration;

			// 실행시작 시간을 초기화합니다.
			started = clock();
			// 분기에 따라 함수를 실행합니다.
			if (type == TYPES_REPETITION) { repetition(num); }
			else if (type == TYPES_RECURSION) { recursion(num); }
			// 총 실행시간을 저장합니다.
			// 기본적으로 seconds 단위만 저장하므로 , 1000으로 나누어
			// milliseconds 단위를 저장합니다.
			duration = (clock() - started) / (CLOCKS_PER_SEC / 1000);

			printf("total running time : %f ms \n\n", duration);
		}
		else
			printf("finished! \n\n");
	}

	printf("############################");
}

void main() {
	// 반복적 방법으로 함수를 실행합니다.
	exec(TYPES_REPETITION);
	// 재귀적 방법으로 함수를 실행합니다.
	exec(TYPES_RECURSION);
	
	system("pause");
	return;
}