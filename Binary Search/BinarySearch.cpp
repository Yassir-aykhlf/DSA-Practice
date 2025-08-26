#include <vector>
#include <algorithm>
#include <iostream>

int	BinarySearch(std::vector<int>& arr, int target) {
	int mid;
	int n = arr.size();
	int a = 0;
	int b = n - 1;
	while (a <= b) {
		mid = (a + b) / 2;
		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] > target) {
			b = mid - 1;
		}
		else {
			a = mid + 1;
		}
	}
	return -1;
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
}

int main() {
    std::vector<int> arr = {4, 8, 16, 25, 34};
    int n = arr.size();
	int target = 4;
	int pos;

    pos = BinarySearch(arr, target);
	if (pos != -1) {
		std::cout << target << " is at index [" << pos << "] in the sorted array: ";
		printArray(arr);
		std::cout << std::endl;
	}
	else {
		std::cout << target << " does not exist in the array: ";
		printArray(arr);
		std::cout << std::endl;
	}
    return 0;
}