#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less<int>());
        vector<vector<int> > res;
        int sz = nums.size();
        for (int i = 0; i < sz - 3; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            for (int j = i + 1; j < sz - 2; ++j) {
                if (j != i + 1 && nums[j] == nums[j-1]) continue;
                int p = j + 1, q = sz - 1;
                while (p < q) {
                    if (nums[i] + nums[j] + nums[p] + nums[q] == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[p], nums[q]});
                        ++p;
                        --q;
                        while (p < q && nums[p] == nums[p-1]) ++p;
                        while (p < q && nums[q] == nums[q+1]) --q;
                    } else if (nums[i] + nums[j] + nums[p] + nums[q] < target) {
                        ++p;
                    } else {
                        --q;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums{1, 0, -1, 0, -2, 2};
    sol.fourSum(nums, 0);
    return 0;
}
