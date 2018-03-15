#include <stdio.h>

void merge(int l_left, int l_right, int arr_left[], int arr_right[], int root[]) {
	int i = 0, j = 0, k = 0;
		
	while (i < l_left && j < l_right) {
		if (arr_left[i] < arr_right[j]) {
			root[k] = arr_right[j];
			j++;
		}
		else {
			root[k] = arr_left[i];
			i++;
		}
		k++;
	}

	for (int idx = k; idx < (l_left + l_right); idx++) {
		if (i >= l_left) {  
			root[idx] = arr_right[j];
			j++;
		}
		else {  
			root[idx] = arr_left[i];
			i++;
		}
	}
}

void mergeSort(int len, int arr[]) {
	if (len > 1) {
		int l_left, l_right;
		l_left = len / 2;
		l_right = len - l_left;

		int *arr_left, *arr_right;
		arr_left = (int*)malloc(sizeof(int) * l_left);
		arr_right = (int*)malloc(sizeof(int) * l_right);

		for (int i = 0; i < l_left; i++) {
			arr_left[i] = arr[i];
		}
		for (int i = 0; i < l_right; i++) {
			arr_right[i] = arr[i + l_left];
		}
		
		mergeSort(l_left, arr_left);
		mergeSort(l_right, arr_right);
		merge(l_left, l_right, arr_left, arr_right, arr);
	}
}


int main() {

	int arr[10] = { 2,4,5,1,9,6,8,3,10,11 };
	
	printf("## MERGESORT ##\n arr : { ");
	for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
		printf("%d", arr[i]);
		if (i < (sizeof(arr) / sizeof(int)) - 1) {
			printf(", ");
		}
	}
	printf(" }\n");
	
	
	// 9, 8, 6, 5, 4, 3, 2, 1
	mergeSort((sizeof(arr) / sizeof(int)), arr);

	printf("##### RESULT #### \n arr : { ");
	for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
		printf("%d", arr[i]);
		if (i < (sizeof(arr) / sizeof(int)) - 1) {
			printf(", ");
		}
	}
	printf(" }\n");
	system("pause");

	return 0;
}