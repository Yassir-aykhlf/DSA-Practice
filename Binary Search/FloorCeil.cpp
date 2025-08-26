/**
 * PROBLEM: Floor and Ceil in Sorted Array
 * 
 * DESCRIPTION:
 * Given a sorted array of integers and a target value x, find the floor and ceil of x.
 * 
 * DEFINITIONS:
 * - Floor: The largest element in the array that is smaller than or equal to x
 * - Ceil:  The smallest element in the array that is greater than or equal to x
 * 
 * If no floor or ceil exists, return -1 for that respective value.
 * 
 * EXAMPLES:
 * 
 * Example 1:
 * Input:  nums = [3, 4, 4, 7, 8, 10], x = 5
 * Output: Floor = 4, Ceil = 7
 * Explanation: 
 *   - Floor: 4 is the largest element ≤ 5
 *   - Ceil: 7 is the smallest element ≥ 5
 * 
 * Example 2:
 * Input:  nums = [3, 4, 4, 7, 8, 10], x = 8
 * Output: Floor = 8, Ceil = 8
 * Explanation: 
 *   - Floor: 8 is the largest element ≤ 8
 *   - Ceil: 8 is the smallest element ≥ 8
 * 
 * Example 3:
 * Input:  nums = [3, 4, 4, 7, 8, 10], x = 2
 * Output: Floor = -1, Ceil = 3
 * Explanation: 
 *   - Floor: No element ≤ 2 exists
 *   - Ceil: 3 is the smallest element ≥ 2
 * 
 * CONSTRAINTS:
 * - The input array is sorted in non-decreasing order
 * - Array size: 1 <= nums.length <= 10^5
 * - Element range: -10^9 <= nums[i], x <= 10^9
 * 
 * TIME COMPLEXITY: O(log n) - Binary Search
 * SPACE COMPLEXITY: O(1) - Constant extra space
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * DECONSTRUCTION:
 * since the array is sorted I will search using binary search
 * if i find the target i will return it as both floor and ceil
 * i will keep track of lower values as possible floor
 * i will keep track of upper values as possible ceil
 */
vector<int> getFloorAndCeil(vector<int> nums, int target) {
	int n = nums.size();
	int mid;
	int a = 0;
	int b = n - 1;
	int floor = -1;
	int ceil = -1;
	while (a <= b) {
		mid = (a + b) / 2;
		if (nums[mid] == target) {
			return {target, target};
		}
		else if (nums[mid] > target) {
			ceil = nums[mid];
			b = mid - 1;
		}
		else {
			floor = nums[mid];
			a = mid + 1;
		}
	}
	return {floor, ceil};
}

int main() {
	vector<int>	result;
	vector<int>	nums = {3, 4, 4, 7, 8, 10};
	int			x = 8;

	result = getFloorAndCeil(nums, x);
	std::cout << "Target: " << x << ", Floor: " << result[0] << ", Ceil: " << result[1] << std::endl;

	nums = {0,1,2,3,4,5,6,9,10};

	result = getFloorAndCeil(nums, x);
	std::cout << "Target: " << x << ", Floor: " << result[0] << ", Ceil: " << result[1] << std::endl;
}