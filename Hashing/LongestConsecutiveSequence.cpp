/**
 * LeetCode 128: Longest Consecutive Sequence
 * Difficulty: Medium
 * 
 * Problem Description:
 * Given an unsorted array of integers nums, return the length of the longest 
 * consecutive elements sequence.
 * 
 * Requirements:
 * - Algorithm must run in O(n) time complexity
 * 
 * Examples:
 * 
 * Example 1:
 * Input:  nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive sequence is [1,2,3,4] with length 4.
 * 
 * Example 2:
 * Input:  nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * Explanation: The longest consecutive sequence is [0,1,2,3,4,5,6,7,8] with length 9.
 * 
 * Example 3:
 * Input:  nums = [1,0,1,2]
 * Output: 3
 * Explanation: The longest consecutive sequence is [0,1,2] with length 3.
 * 
 * Constraints:
 * - 0 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
*/

#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

int longestConsecutive(std::vector<int>& nums) {
	if (nums.empty()) return 0;
	std::unordered_set<int> set(nums.begin(), nums.end());
	int longest_seq = 0;
	for (auto num : set) {
		if (set.find(num - 1) == set.end()) {
			int current_seq = 1;
			int current_num = num;			
			while (set.find(current_num + current_seq) != set.end()) {
				current_seq++;
			}
			longest_seq = std::max(longest_seq, current_seq);
		}
	}
	return longest_seq;
}  

int main() {
	std::vector<int> arr1 = {100,4,200,1,3,2};
	std::vector<int> arr2 = {0,3,7,2,5,8,4,6,0,1};
	std::vector<int> arr3 = {1,0,1,2};
	cout << "Test 1: " << longestConsecutive(arr1) << endl;
	cout << "Test 2: " << longestConsecutive(arr2) << endl;
	cout << "Test 3: " << longestConsecutive(arr3) << endl;
}