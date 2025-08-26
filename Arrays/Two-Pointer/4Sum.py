"""
18. 4Sum

Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
"""

from typing import List

def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
    n = len(nums)
    result = []
    if n < 4:
        return result
    nums.sort()
    for i in range(n - 3):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        if nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target:
            continue
        if nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target:
            break
        for j in range (i + 1, n - 2):
            if j > i + 1 and nums[j] == nums[j - 1]:
                continue
            a = j + 1
            b = n - 1
            while (a < b):
                total = nums[i] + nums[j] + nums[a] + nums[b]
                if (total == target):
                    result.append([nums[i], nums[j], nums[a], nums[b]])
                    while a < b and nums[a] == nums[a + 1]:
                        a += 1
                    while a < b and nums[b] == nums[b - 1]:
                        b -= 1
                    a += 1
                    b -= 1
                elif (total > target):
                    b -= 1
                else:
                    a += 1
    return result

if __name__ == "__main__":
    nums1 = [1, 0, -1, 0, -2, 2]
    target1 = 0
    result1 = fourSum(nums1, target1)
    print(f"Input: nums = {nums1}, target = {target1}")
    print(f"Output: {result1}")
    print()
    
    nums2 = [2, 2, 2, 2, 2]
    target2 = 8
    result2 = fourSum(nums2, target2)
    print(f"Input: nums = {nums2}, target = {target2}")
    print(f"Output: {result2}")
    print()
    
    nums3 = [1, 2, 3, 4]
    target3 = 100
    result3 = fourSum(nums3, target3)
    print(f"Input: nums = {nums3}, target = {target3}")
    print(f"Output: {result3}")
