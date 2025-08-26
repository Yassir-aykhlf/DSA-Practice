/**
 * PROBLEM: Single Element in a Sorted Array (LeetCode 540)
 * 
 * DESCRIPTION:
 * You are given a sorted array consisting of only integers where every element 
 * appears exactly twice, except for one element which appears exactly once.
 * 
 * Return the single element that appears only once.
 * 
 * Your solution must run in O(log n) time and O(1) space.
 * 
 * EXAMPLES:
 * 
 * Example 1:
 * Input:  nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]
 * Output: 2
 * Explanation: Element 2 appears only once, all others appear twice
 * 
 * Example 2:
 * Input:  nums = [3, 3, 7, 7, 10, 11, 11]
 * Output: 10
 * Explanation: Element 10 appears only once, all others appear twice
 * 
 * Example 3:
 * Input:  nums = [1]
 * Output: 1
 * Explanation: Single element array
 * 
 * Example 4:
 * Input:  nums = [1, 1, 2]
 * Output: 2
 * Explanation: Single element at the end
 * 
 * CONSTRAINTS:
 * - Array size: 1 <= nums.length <= 10^5
 * - Element range: 0 <= nums[i] <= 10^5
 * - Array is sorted in ascending order
 * - All elements appear exactly twice except one element which appears once
 * - nums.length is always odd (since we have pairs + 1 single element)
 * 
 * TIME COMPLEXITY: O(log n) - Binary Search required
 * SPACE COMPLEXITY: O(1) - Constant extra space
 */


#include <vector>
#include <iostream>
#include <vector>

using namespace std;

/**
 * DECONSTRUCTION:
 the array is sorted and the time complexity must be O(log n) which smells like binary search
 but what would be the condition?
 nums[i] != nums[i - 1] != nums[i + 1] ???
 then what would be the condition of cancellation ?
 maybe cancel the part that equals nums[mid]
 no this does not make any since
 looking at the examples there is a clever pattern
 if all elements are duplicated once, they will all start at an even index and end in an even one
 after the imposter is inserted that would shift by one
*/
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1 || nums[0] != nums[1]) return nums[0];
    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
    int a = 0;
    int b = n - 1;
    int mid;
    while (a <= b) {
        mid = (a + b) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }
        else if ((nums[mid] == nums[mid - 1] && mid % 2 != 0) || (nums[mid] == nums[mid + 1] && mid % 2 == 0)) {
            a = mid + 1;
        }
        else if ((nums[mid] == nums[mid - 1] && mid % 2 == 0) || (nums[mid] == nums[mid + 1] && mid % 2 != 0)) {
            b = mid - 1;
        }
    }
    return nums[mid];
}

// BETTER YET
// Utilize the XOR approach for a more elegant solution
int XORsingleNonDuplicate(vector<int>& nums) {
    int a = 0;
    int b = nums.size() - 1;

    while (a < b) {
        int mid = (a + b) / 2;

        // XOR with 1 flips the last bit: even becomes odd, odd becomes even
        // that means we compare nums[mid] with its pair partner
        // if they are equal, the single element is in the right half
        // if they are not equal, the single element is in the left half
        if (nums[mid] == nums[mid ^ 1]) {
            a = mid + 1; // Single element is to the right
        } else {
            b = mid; // Single element is to the left (including mid)
        }
    }

    return nums[a];
}

int main() {
	vector<int> nums = {1, 1, 2, 3, 3, 4, 4};
	int result = singleNonDuplicate(nums);
	cout << "Single non-duplicate element: " << result << endl; // Output: 2

	nums = {2, 2, 3, 3, 4, 5, 5};
	result = singleNonDuplicate(nums);
	cout << "Single non-duplicate element: " << result << endl; // Output: 4

	nums = {1};
	result = singleNonDuplicate(nums);
	cout << "Single non-duplicate element: " << result << endl; // Output: 1

	return 0;
}