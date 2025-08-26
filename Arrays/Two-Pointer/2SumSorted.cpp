/**
 * PROBLEM: Two Sum II - Input Array Is Sorted (LeetCode 167)
 * 
 * DESCRIPTION:
 * You are given a 1-indexed array of integers `numbers` that is already sorted in non-decreasing order. 
 * You are also given an integer `target`. 
 * 
 * Your task is to find two numbers such that they add up to `target`.
 * Return the indices of the two numbers (1-indexed) as an integer array [index1, index2], 
 * where 1 <= index1 < index2 <= numbers.length.
 * 
 * The solution must use only constant extra space.
 * 
 * EXAMPLES:
 * 
 * Example 1:
 * Input:  numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: 2 + 7 = 9. Indices are [1,2].
 * 
 * Example 2:
 * Input:  numbers = [2,3,4], target = 6
 * Output: [1,3]
 * Explanation: 2 + 4 = 6. Indices are [1,3].
 * 
 * Example 3:
 * Input:  numbers = [-1,0], target = -1
 * Output: [1,2]
 * Explanation: -1 + 0 = -1. Indices are [1,2].
 * 
 * CONSTRAINTS:
 * - Array size: 2 <= numbers.length <= 3 * 10^4
 * - Element range: -1000 <= numbers[i] <= 1000
 * - Target range: -1000 <= target <= 1000
 * - Exactly one solution exists
 * - Input array is sorted in non-decreasing order
 * 
 * TIME COMPLEXITY: O(n)  - Two-pointer approach
 * SPACE COMPLEXITY: O(1) - Constant extra space
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int idx1 = 0;
    int idx2 = n - 1;
    int sum;
    while (idx1 < idx2) {
        sum = numbers[idx1] + numbers[idx2];
        if (sum == target) {
            return {idx1 + 1, idx2 + 1};
        }
        else if (sum > target) {
            idx2--;
        }
        else {
            idx1++;
        }
    }
    return {-1};
}

int main() {
	vector<int> numbers = {2, 7, 11, 15};
	int target = 9;
	vector<int> result = twoSum(numbers, target);
	for (int idx : result) {
		cout << idx << " ";
	}
	return 0;
}