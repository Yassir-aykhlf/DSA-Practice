#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

//using namespace std;

//Brute Force
std::vector<int> pairSum(std::vector<int> arr, int target) {
	for (int i = 0; i < arr.size(); ++i) {
		int comp = target - arr[i];
		for (int j = i + 1; j < arr.size(); ++j) {
			if (arr[j] == comp) {
				return {arr[i], arr[j]};
			}
		}
	}
	return {-1};
}

//Two Pointers
std::vector<int> pairSum(std::vector<int> arr, int target) {
	std::sort(arr.begin(), arr.end());
	int a = 0;
	int b = arr.size() - 1;

	while (a < b) {
		int result = arr[a] + arr[b];
		if (result == target) {
			return {arr[a], arr[b]};
		}
		else if (result > target) {
			b--;
		}
		else {
			a++;
		}
	}
	return {-1};
}

//Hash Set
std::vector<int> pairSum(std::vector<int> arr, int target) {
	std::unordered_set<int> hash_set;
	int comp;

	for (int i = 0; i < arr.size(); ++i) {
		comp = target - arr[i];
		if (hash_set.find(comp) != hash_set.end()) {
			return {arr[i], comp};
		}
		hash_set.insert(arr[i]);
	}
	return {-1};
}

int main() {
	std::vector<int> arr{10,5,2,3,-6,9,11};
	int target = 4;

	std::vector<int> result = pairSum(arr, target);
}