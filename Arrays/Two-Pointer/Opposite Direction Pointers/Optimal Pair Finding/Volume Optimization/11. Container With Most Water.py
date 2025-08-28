"""
1.	Pre-computation analysis:
	*	we are given an array of positive integers, range [0, 10^4]
	*	the array's length can be between 2 and 10^5
	*	meaning I don't have to handle the empty array case
		and also the data can be very large
		elemenaing the possibility of a brute-force approach

2.	Problem Definition:
	*	the problem is to find the two lines (indices)
		that together with x-axis from a container (the base or floor)
		can contain the most water, (the result of multiplying the smallest index with the distance between the indices)
	*	and return that maximum amount of water
	*	there is a notice: Notice that you may not slant the container.
		maybe it means the water should always be horizental?? inforcing the min index hypostasis

3.	Brute-Force Analysis:
	*	the most obvious solution
		would be to traverse the array and calculate the area it forms with every index in front of it
		and register the maximum value we find so far.
		the code would be:
		
		class Solution:
			def maxArea(self, height: List[int]) -> int:
				n = len(height)
				maxAmount = 0
				for i in range(n - 1):
					for j in range(i + 1, n):
						maxAmount = max(maxAmount, ((j - i) * min(height[i], height[j])))
				return maxAmount
		
	*	the complexity would be O(n^2), that to inefficient for a data size of 10^5

4.	Optimal Solution:
	*	the smart solution would take advantage of the fact that the area or container
		uses two ends, meaning i can use two iterators and keep calculating the area between them
		and greedly decide which pointer to shrink until they meet in the middle
	*	basically calculate the widest container
		then decide which end to shrink
		this decision obviously will be depend on the smallest end
		the goal is to find the largest possible container
		so it makes sense to shrink the smallest end
"""

"""
5.  Optimal Implementation:
"""
from typing import List

def maxArea(height: List[int]) -> int:
    n = len(height)
    maxAmount = 0
    a = 0
    b = n - 1
    while (a < b):
        area = min(height[a], height[b]) * (b - a)
        maxAmount = max(maxAmount, area)
        if (height[a] < height[b]) :
            a += 1
        else :
            b -= 1
    return maxAmount

"""
6.  Complexity:
    *   the complexity of the optimal solution is O(n)
		because both indices can only move n times
		traversing the array once instead of n times each index

	*	possible pitfalls:
		using the condition while (a <= b) instead of (a < b) and off-by one indexing
		(a <= b) would calculate an invalid void container
"""

"""
7.	Testing:
"""
if __name__ == "__main__":
	height1 = [1,8,6,2,5,4,8,3,7]
	height2 = [1,1]
	print(maxArea(height1))
	print(maxArea(height2))
