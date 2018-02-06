#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less<int>());
        int res = nums[0] + nums[1] + nums[2];
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            while (i != 0 && nums[i] == nums[i-1]) ++i;
            int p = i + 1, q = sz - 1;
            while (p < q) {
                int sum = nums[i] + nums[p] + nums[q];
                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                }
                if (sum <= target) {
                    ++p;
                    while (p < q && nums[p] == nums[p-1]) ++p;
                } else {
                    --q;
                    while (p < q && nums[q] == nums[q+1]) --q;
                }
            }
        }
        return res;
    }
};

