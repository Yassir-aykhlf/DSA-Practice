/**
 * PROBLEM: Container With Most Water (LeetCode 11)
 * 
 * DESCRIPTION:
 * You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that 
 * the two endpoints of the i-th line are (i, 0) and (i, height[i]).
 * 
 * Find two lines that, together with the x-axis, form a container that can store the most water.
 * 
 * Return the maximum amount of water a container can store.
 * 
 * Note: The container cannot be slanted.
 * 
 * EXAMPLES:
 * 
 * Example 1:
 * Input:  height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
 *              The maximum water container is formed by lines at indices 1 and 8 (heights 8 and 7),
 *              which can store 49 units of water.
 * 
 * Example 2:
 * Input:  height = [1,1]
 * Output: 1
 * Explanation: Both lines have equal height 1, forming a container of width 1 and area 1.
 * 
 * CONSTRAINTS:
 * - Array size: 2 <= n <= 10^5
 * - Height range: 0 <= height[i] <= 10^4
 * 
 * TIME COMPLEXITY: O(n)  - Two-pointer approach
 * SPACE COMPLEXITY: O(1) - Constant extra space
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int a = 0;
    int b = n - 1;
    int maxWater = 0;
    while (a < b) {
        maxWater = max(maxWater, min(height[a], height[b]) * (b - a));
        if (height[a] < height[b]) {
            a++;
        }
        else {
            b--;
        }     
    }
    return maxWater;
}

int main() {
	vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int result = maxArea(height);
	return result;
}