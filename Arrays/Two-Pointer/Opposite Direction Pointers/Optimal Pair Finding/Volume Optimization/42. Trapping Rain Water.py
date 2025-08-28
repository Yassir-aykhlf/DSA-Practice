"""
1.	Pre-computation analysis:
	*	we are given an array of positive integers, range [0, 10^5]
	*	the array's length can be between 1 and 2 * 10^4
	*	meaning I don't have to handle the empty array case
		and also the data can be very large
		elemenaing the possibility of a brute-force approach

2.	Problem Definition:
	*	we are given an array
		the array represents the heights of 1 width blocks 
		and asked to compute how much water it can trap after raining
	*	an abstraction for:
		  - the amount of blocks needed to flatten the shape
		  - the total area between neighbors
		  - ...
	*	the description says nothing about the indices [-1] and [n + 1]
		I must assume based on the examples provided that they can trap no water
		meaning the array [0] trap nothing
	
3.	Brute-Force Analysis:
	*	the brute-force approach would:
		  - calculate the water above each block
		  	by searching for the tallest block on the left
		    then search for the largest block to the right
			then take the smallest of these blocks, subtract the block height from it
			this is the water it can trap
			add the water level to the total
		  - we don't have to consider the index 0 and n - 1 since they can't trap water

"""
from typing import List

def trapBruteForce(height: List[int]) -> int:
    n = len(height)
    if n < 3:
        return 0
    total = 0
    for i in range(1, n-1):
        # look for the largest block left that is bigger than the current block:
        largestL = height[i]
        for l in range(i, -1, -1):
            largestL = max(largestL, height[l])

        # look for the largest block right that is bigger than the current block:
        largestR = height[i]
        for r in range(i, n):
            largestR = max(largestR, height[r])
        
        # the smallest largest block of the two is our bottleneck
        bottleneck = min(largestR, largestL)

        # calculate the capacity of the current block
        waterHere = bottleneck - height[i]

        if waterHere > 0:
            total += waterHere
    return total

"""
4.	Optimal Solution:
	*	the smart solution would take advantage of the fact that the area
		uses two ends, meaning I can use two pointers
		and move them greedly, move the smallest block and accumelate the total water
	*	basically calculate the water the current slot can hold
		then decide which end to shrink
		this decision obviously will be depend on the smallest end
		the goal is to find the largest possible container
		so it makes sense to shrink the smallest end
	*	efficiently keeping track of the largest ends

"""

"""
5.  Optimal Implementation:
"""
from typing import List

def trap(height: List[int]) -> int:
    n = len(height)
    if n < 3:
        return 0
    a = 0
    b = n - 1
    maxR = height[a]
    maxL = height[b]
    result = 0
    while (a < b):
        if height[a] < height[b]:
            a += 1
            maxR = max(maxR, height[a])
            result += maxR - height[a]
        else :
            b -= 1
            maxL = max(maxL, height[b])
            result += maxL - height[b]
    return result

"""
6.  Complexity:
    *   the complexity of the optimal solution is O(n)
		because both indices can only move n times
		traversing the array once instead of n times each index

	*	possible pitfalls:
		the most probable source of error is updating the pointer (left++ or right--) after calculating the trapped water, instead of before.
		the water calculation must be for the newly arrived-at position
		another pitfall is incorrectly initializing left_max and right_max
"""

"""
7.	Testing:
"""
if __name__ == "__main__":
	height1 = [0,1,0,2,1,0,1,3,2,1,2,1]
	height2 = [4,2,0,3,2,5]
	height3 = [4]
	print(trap(height1))
	print(trap(height2))
	print(trap(height3))
