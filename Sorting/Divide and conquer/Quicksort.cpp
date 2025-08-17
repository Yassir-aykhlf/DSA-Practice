#include <vector>
#include <algorithm>
#include <iostream>

void printArray(std::vector<int>& arr);

int partition(std::vector<int>& arr, int a, int b) {
	int pivot = arr[a];
	int cursor = a;
	for (int i = a + 1; i <= b; ++i) {
		if (arr[i] < pivot) {
			cursor++;
			std::swap(arr[i], arr[cursor]);
		}
	}
	std::swap(arr[cursor], arr[a]);
	return cursor;
}

void Quicksort(std::vector<int>& arr, int a, int b) {
	if (a >= b)
		return;
	int pos = partition(arr, a, b);
	Quicksort(arr, a, pos);
	Quicksort(arr, pos + 1, b);
}

void printArray(std::vector<int>& arr) {
	bool isFirst = true;
	for (int i = 0; i < arr.size(); ++i) {
		if (isFirst != true) 
			std::cout << ", ";
		std::cout << arr[i];
		if (isFirst == true)
			isFirst = false;
	}
	std::cout << "\n";
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    Quicksort(arr, 0, n-1);
    std::cout << "Sorted array: \n";
    printArray(arr);
    return 0;
}