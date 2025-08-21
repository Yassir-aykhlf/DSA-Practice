/**
 * LeetCode 53: Maximum Subarray
 * 
 * Problem Statement:
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * 
 * Examples:
 * 
 * Example 1:
 * Input:  nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 * 
 * Example 2:
 * Input:  nums = [1]
 * Output: 1
 * Explanation: The subarray [1] has the largest sum 1.
 * 
 * Example 3:
 * Input:  nums = [5,4,-1,7,8]
 * Output: 23
 * Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 * 
 * Constraints:
 * • 1 <= nums.length <= 10^5
 * • -10^4 <= nums[i] <= 10^4
 * 
 * Follow-up:
 * If you have figured out the O(n) solution, try coding another solution using 
 * the divide and conquer approach, which is more subtle.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

/**
 * APPROACH 1: Kadane's Algorithm - Reset on Negative
 * 
 * Algorithm:
 * - Maintain a running sum and reset it to 0 when it becomes negative
 * - The key insight: if current_sum becomes negative, it's better to start fresh
 *   since any negative prefix will only decrease future sums
 * 
 * Edge Cases:
 * - Single element: Works normally
 * - All negative numbers: INT_MIN initialization ensures we return the least negative
 * 
 * Time: O(n), Space: O(1)
*/
int maxSubArrayKadane(std::vector<int>& nums) {
    int current_sum = 0;
    int max_sum = INT_MIN;
    
    for (int num : nums) {
        current_sum += num;
        max_sum = std::max(max_sum, current_sum);
        if (current_sum < 0) {
            current_sum = 0;
        }
    }
    
    return max_sum;
}

// SECOND APPROACH:

/**
 * APPROACH 2: Kadane's Algorithm - DP Perspective  
 * 
 * Algorithm:
 * - At each position, decide: extend previous subarray or start fresh?
 * - current_sum = max(num, current_sum + num)
 * - This is equivalent to the DP recurrence: dp[i] = max(nums[i], dp[i-1] + nums[i])
 * 
 * Time: O(n), Space: O(1)
*/
int maxSubArrayDP(std::vector<int>& nums) {
    int current_sum = 0;
    int max_sum = INT_MIN;
    
    for (int num : nums) {
        current_sum = std::max(num, current_sum + num);
        max_sum = std::max(max_sum, current_sum);
    }
    
    return max_sum;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result1 = maxSubArrayKadane(nums);
    std::cout << "Kadane's Algorithm Result: " << result1 << std::endl;
    
    int result2 = maxSubArrayDP(nums);
    std::cout << "DP Approach Result: " << result2 << std::endl;
    
    return 0;
}