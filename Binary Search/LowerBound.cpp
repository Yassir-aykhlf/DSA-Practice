/**
 * PROBLEM: Lower Bound
 * 
 * DESCRIPTION:
 * Given a sorted array of integers and a target value x, find the lower bound of x.
 * The lower bound is the first (smallest) index in the sorted array where the value
 * at that index is greater than or equal to the given target x.
 * 
 * If no such index is found, return the size of the array.
 * 
 * EXAMPLES:
 * 
 * Example 1:
 * Input:  nums = [1, 2, 2, 3], x = 2
 * Output: 1
 * Explanation: Index 1 is the smallest index such that nums[1] >= x (2)
 * 
 * Example 2:
 * Input:  nums = [3, 5, 8, 15, 19], x = 9
 * Output: 3
 * Explanation: Index 3 is the smallest index such that nums[3] >= x (15 >= 9)
 * 
 * CONSTRAINTS:
 * - The input array is sorted in non-decreasing order
 * - Array size: 1 <= nums.length <= 10^5
 * - Element range: -10^9 <= nums[i], x <= 10^9
 * 
 * TIME COMPLEXITY: O(log n) - Binary Search
 * SPACE COMPLEXITY: O(1) - Constant extra space
*/

#include <vector>
#include <iostream>

using namespace std;

/**
 * DECONSTRUCTION:
 * a lower bound is the number greater than or equal to my target
 * to find the lower bound I must ignore all number less than my target
 * then keep updating my pointer till they overlap
 * then a would be equal to the lowerbound
 */
class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
		int n = nums.size();
		int a = 0;
		int b = n - 1;
		int mid;
		while (a <= b) {
			mid = (a + b) / 2;
			if (nums[mid] >= target) {
				b = mid - 1; 
			}
			else {
				a = mid + 1;
			}
		}
		return a;
    }
};

int main() {
	Solution solution;
	vector<int> nums = {1, 2, 2, 3};
	int target = 2;
	int result = solution.lowerBound(nums, target);
	cout << "Lower bound index for " << target << " is: " << result << endl;

	nums = {5, 6, 15, 15, 19};
	target = 9;
	result = solution.lowerBound(nums, target);
	cout << "Lower bound index for " << target << " is: " << result << endl;

	return 0;
}