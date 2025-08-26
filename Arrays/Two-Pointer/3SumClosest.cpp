/*
16. 3Sum Closest

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int closestSum = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int a = i + 1;
        int b = n - 1;
        while (a < b) {
            int currentSum = nums[i] + nums[a] + nums[b];
            
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }            
            if (currentSum == target) {
                return currentSum;
            }
            if (currentSum < target) {
                a++;
            }
			else {
                b--;
            }
        }
    }
    return closestSum;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = threeSumClosest(nums, target);
    cout << "3Sum Closest: " << result << endl;
    return 0;
}
