/**
 * PROBLEM: Search Insert Position
 * 
 * DESCRIPTION:
 * Given a sorted array of distinct integers and a target value, return the index 
 * if the target is found. If not, return the index where it would be if it were 
 * inserted in order to maintain the sorted property.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * EXAMPLES:
 * 
 * Example 1:
 * Input:  nums = [1, 3, 5, 6], target = 5
 * Output: 2
 * Explanation: Target 5 is found at index 2
 * 
 * Example 2:
 * Input:  nums = [1, 3, 5, 6], target = 2
 * Output: 1
 * Explanation: Target 2 should be inserted at index 1 to maintain order [1, 2, 3, 5, 6]
 * 
 * Example 3:
 * Input:  nums = [1, 3, 5, 6], target = 7
 * Output: 4
 * Explanation: Target 7 should be inserted at index 4 to maintain order [1, 3, 5, 6, 7]
 * 
 * Example 4:
 * Input:  nums = [1, 3, 5, 6], target = 0
 * Output: 0
 * Explanation: Target 0 should be inserted at index 0 to maintain order [0, 1, 3, 5, 6]
 * 
 * CONSTRAINTS:
 * - Array size: 1 <= nums.length <= 10^4
 * - Element range: -10^4 <= nums[i] <= 10^4
 * - nums contains distinct values sorted in ascending order
 * - Target range: -10^4 <= target <= 10^4
 * 
 * TIME COMPLEXITY: O(log n) - Binary Search required
 * SPACE COMPLEXITY: O(1) - Constant extra space
 */

#include <vector>
#include <iostream>

using namespace std;

/**
 * DECONSTRUCTION:
 * the array is sorted so the search must be done using binary search
 * if the target is found return the index of target
 * if not return the the lower pointer since it would be indexing the number after 
 * the number less than the target, which will naturaly be the index where the target should be.
 * basically I am looking for the lower bound
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int n = nums.size();
		int a = 0;
		int b = n - 1;
		int mid;
		while (a <= b) {
			mid = (a + b) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			else if (nums[mid] > target) {
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
    
    vector<int> nums = {1, 3, 5, 6};
    int target1 = 5;
    int result1 = solution.searchInsert(nums, target1);
    cout << "nums: [1,3,5,6], target: " << target1 << " => Insert position: " << result1 << " (Expected: 2)" << endl;

    int target2 = 2;
    int result2 = solution.searchInsert(nums, target2);
    cout << "nums: [1,3,5,6], target: " << target2 << " => Insert position: " << result2 << " (Expected: 1)" << endl;

    int target3 = 7;
    int result3 = solution.searchInsert(nums, target3);
    cout << "nums: [1,3,5,6], target: " << target3 << " => Insert position: " << result3 << " (Expected: 4)" << endl;

    int target4 = 0;
    int result4 = solution.searchInsert(nums, target4);
    cout << "nums: [1,3,5,6], target: " << target4 << " => Insert position: " << result4 << " (Expected: 0)" << endl;

    int target5 = 1;
    int result5 = solution.searchInsert(nums, target5);
    cout << "nums: [1], target: " << target5 << " => Insert position: " << result5 << " (Expected: 0)" << endl;
    
    return 0;
}