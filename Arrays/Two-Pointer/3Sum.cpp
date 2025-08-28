#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
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
	vector<int> nums = {0,6,1,4,-6,2,-3};
	vector<vector<int>> result = threeSum(nums);

	for (vector<int> arr : result) {
		for (int elem : arr) {
			cout << elem << ", ";
		}
		cout << "\n";
	}
}