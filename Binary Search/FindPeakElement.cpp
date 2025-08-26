/**
 * PROBLEM: Find Peak Element
 * 
 * DESCRIPTION:
 * A peak element is an element that is strictly greater than its neighbors.
 * Given a 0-indexed integer array nums, find a peak element and return its index.
 * If the array contains multiple peaks, return the index to any of the peaks.
 * 
 * IMPORTANT: You may imagine that nums[-1] = nums[n] = -∞ (negative infinity).
 * In other words, an element is always considered to be strictly greater than 
 * a neighbor that is outside the array.
 * 
 * You must write an algorithm that runs in O(log n) time.
 * 
 * EXAMPLES:
 * 
 * Example 1:
 * Input:  nums = [1, 2, 3, 1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index number 2.
 * 
 * Example 2:
 * Input:  nums = [1, 2, 1, 3, 5, 6, 4]
 * Output: 5 (or 1)
 * Explanation: Your function can return either index 1 (peak element 2) 
 *              or index 5 (peak element 6).
 * 
 * Example 3:
 * Input:  nums = [1]
 * Output: 0
 * Explanation: Single element is always a peak.
 * 
 * Example 4:
 * Input:  nums = [1, 2]
 * Output: 1
 * Explanation: Element 2 is greater than its left neighbor and imaginary right neighbor (-∞).
 * 
 * CONSTRAINTS:
 * - Array size: 1 <= nums.length <= 1000
 * - Element range: -2^31 <= nums[i] <= 2^31 - 1
 * - nums[i] != nums[i + 1] for all valid i (no adjacent equal elements)
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
 * the array is not sorted
 * however we can use binary search to dismiss half of the array
 * this is the power of binary search
 * and the dismissing logic would be
 * if the middle element is less than the element after it
 *   this means there is a peak after the mid, since nums[n] = +infinity
 * if the middle element is greater than the element after it 
 *   this means the middle element may be a peak
 *   or an element before it, canceling all the elements on the right
 * until a = b
 * then we find the peak element
 * why the loop terminates at a peak?
 * the search space keeps shrinking while maintaining the guarantee that a peak exists
 * when a == b, we've narrowed down to a single element
 * by our elimination logic, this element must be a peak
*/
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int a = 0;
    int b = n - 1;
    int mid;
    if (n == 1) return 0;
    if (nums[0] > nums[1]) return 0;
    if (nums[b] > nums[b - 1]) return b;
    while (a <= b) {
        mid = (a + b) / 2;
        if (nums[mid] < nums[mid + 1]) {
            a = mid + 1;
        }
        else {
            b = mid - 1;
        }
    }
    return a;
}

int main() {
	vector<int> nums = {1, 2, 3, 1};
	int peakIndex = findPeakElement(nums);
	cout << "Peak element index: " << peakIndex << endl; 

	nums = {1, 2, 1, 3, 5, 6, 4};
	peakIndex = findPeakElement(nums);
	cout << "Peak element index: " << peakIndex << endl;

	return 0;
}