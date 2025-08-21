/**
 * Print Maximum Subarray
 * 
 * Problem Statement:
 * Given an integer array, find and print the actual subarray (not just the sum) 
 * that has the maximum sum.
 * 
 * Example:
 * Input:  nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: [4,-1,2,1] (subarray with maximum sum = 6)
 * 
 * Challenge:
 * This is a non-trivial extension that requires augmenting Kadane's algorithm
 * with additional variables to track the start and end indices of the maximum 
 * subarray found so far. You must carefully consider when to update these indices.
 * 
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

/**
 * INTUITION:
 * 1. use two pointers to track where the maximum subarray starts and finishs
 * 2. iterate through the subarray printing its elements
 * 
 * 1.1	I update the end pointer when max_sum changes only
 * 1.2	I update the first pointer when the current_sum becomes negative
 * 		but keep track of the best start index
 */
void printMaxSubArray(std::vector<int>& nums) {
	int start = 0;
	int best_start = 0;
	int end = 0;
	int current_sum = 0;
	int max_sum = INT_MIN;
	for (int i = 0; i < nums.size(); ++i) {
		current_sum += nums[i];
		if (current_sum > max_sum) {
			best_start = start;
			end = i;
			max_sum = current_sum;
		}
		if (current_sum < 0) {
			start = i + 1;
			current_sum = 0;
		}
	}
	for (int i = best_start; i <= end; i++) {
		std::cout << nums[i] << " ";
	} 
}

int main() {
	std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	printMaxSubArray(nums);
	return 0;
}