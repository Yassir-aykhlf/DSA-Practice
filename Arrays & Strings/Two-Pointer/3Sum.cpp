#include <algorithm>
#include <iostream>
#include <vector>


std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    int a;
    int b;

    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        a = i + 1;
        b = n - 1;
        while (a < b) {
            int target = -nums[i];
            int comb = nums[a] + nums[b];
            if (comb == target) {
                result.push_back({nums[i], nums[a], nums[b]});
                while (a < b && nums[a] == nums[a+1]) {
                    a++;
                }
                while (a < b && nums[b] == nums[b-1]) {
                    b--;
                }
                a++;
                b--;
            }
            else if (comb > target) {
                b--;
            }
            else {
                a++;
            }         
        }
    }
    return result;
}

int main(void) {
	std::vector<int> nums = {0,6,1,4,-6,2,-3};
	std::vector<std::vector<int>> result = threeSum(nums);

	for (std::vector<int> arr : result) {
		for (int elem : arr) {
			std::cout << elem << ", ";
		}
		std::cout << "\n";
	}
}