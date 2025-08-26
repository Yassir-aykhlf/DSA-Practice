#include <stdio.h>
#include <iostream>

void InsertionSort(int arr[], int n) {
	if (n <= 1)
		return;
	InsertionSort(arr, n - 1);
	int current = arr[n - 1];
	int prev = n - 2;
	while (prev >= 0 && arr[prev] > current) {
		arr[prev + 1] = arr[prev];
		prev--;
	}
	arr[prev + 1] = current;
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
    InsertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}