#include <stdio.h>
#include <time.h>

enum algorithm_types { TYPES_REPETITION , TYPES_RECURSION };

/*
	DESCRPTION		:	�ݺ��� �˰����� �̿��� ���丮���� ���մϴ�.
	PARAMETERS	
		num		int	:	�ش� �� ��ŭ�� ���丮���� ���մϴ�
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
	DESCRPTION		:	����� �˰����� �̿��� ���丮���� ���մϴ�
	PARAMETERS
		num		int	:	�ش� �� ��ŭ�� ���丮���� ���մϴ�
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
	DESCRIPTION		:	����� �˰���� �ݺ��� �˰��� �Լ��� 
						�б⿡ ���� �����մϴ�.
	PARAMETERS
		type	int	:	algorithm_types ������ ���� �޽��ϴ�.
*/
void exec(int type) {
	int num = 1;

	// Ÿ�Կ� ���� �ٸ� ������ ����մϴ�.
	if (type == TYPES_REPETITION) 	printf("##### FACTORIAL WITH REPETITON \n\n");
	else if (type == TYPES_RECURSION) printf("##### FACTORIAL WITH RECURSION \n\n");
	else return;
	
	// ������ ����� ��¹ޱ� ���� �ݺ����� ����մϴ�.
	while (num >= 1) {
		// ���丮�� ����� ���� ���� �Է¹޽��ϴ�.
		printf("please insert number to calculate factorial\n");
		printf("(if you want finished this process, insert 0 or smaller number than 0)\n : ");
		scanf_s("%d", &num);

		if (num >= 1) {			
			// ���� ���۽ð��� �����ϱ� ���� �����Դϴ�.
			clock_t started;
			// �� ����ð��� �����ϱ� ���� �����Դϴ�.
			double duration;

			// ������� �ð��� �ʱ�ȭ�մϴ�.
			started = clock();
			// �б⿡ ���� �Լ��� �����մϴ�.
			if (type == TYPES_REPETITION) { repetition(num); }
			else if (type == TYPES_RECURSION) { recursion(num); }
			// �� ����ð��� �����մϴ�.
			// �⺻������ seconds ������ �����ϹǷ� , 1000���� ������
			// milliseconds ������ �����մϴ�.
			duration = (clock() - started) / (CLOCKS_PER_SEC / 1000);

			printf("total running time : %f ms \n\n", duration);
		}
		else
			printf("finished! \n\n");
	}

	printf("############################");
}

void main() {
	// �ݺ��� ������� �Լ��� �����մϴ�.
	exec(TYPES_REPETITION);
	// ����� ������� �Լ��� �����մϴ�.
	exec(TYPES_RECURSION);
	
	system("pause");
	return;
}