#include <stdio.h>
#include <iostream>

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
	}
}

void printArray(int arr[], int n) {
	bool isFirst = true;
	for (int i = 0; i < n; ++i) {
		if (isFirst != true) 
			std::cout << ", ";
		std::cout << arr[i];
		if (isFirst == true)
			isFirst = false;
	}
	std::cout << "\n";
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}