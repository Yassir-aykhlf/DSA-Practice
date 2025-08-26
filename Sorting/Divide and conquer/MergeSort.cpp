#include <vector>
#include <iostream>

void MergeArr(std::vector<int>& arr, int a, int b) {
	std::vector<int> tmp;
	int i = a;
	int mid = (a + b) / 2;
	int j = mid + 1;
	while (i <= mid && j <= b) {
		if (arr[i] < arr[j]) {
			tmp.push_back(arr[i]);
			i++;
		}
		else {
			tmp.push_back(arr[j]);
			j++;
		}
	}
	while (i <= mid) {
		tmp.push_back(arr[i]);
		i++;
	}
	while(j <= b) {
		tmp.push_back(arr[j]);
		j++;
	}
	for (int i = 0; i < tmp.size(); ++i) {
		arr[a] = tmp[i];
		a++;
	}
}

void MergeSort(std::vector<int>& arr, int a, int b) {
	if (a >= b) {
		return;
	}
	int mid = (a + b) / 2;
	MergeSort(arr, a, mid);
	MergeSort(arr, mid + 1, b);
	MergeArr(arr, a, b); 
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
    MergeSort(arr, 0, n-1);
    std::cout << "Sorted array: \n";
    printArray(arr);
    return 0;
}