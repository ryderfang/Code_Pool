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
    // O(n^3)
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
                // two lines with time efficient influence
                if (nums[j+1] + nums[j+2] + nums[j] + nums[i] > target) break;
                if (nums[sz-1]+ nums[sz-2] + nums[j] + nums[i] < target) continue;
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

    // O(n^2logn) (NO! worst time complexity is O(n^4)
    vector<vector<int>> fourSum_1(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less<int>());
        vector<vector<int>> res;
        map<int, vector<pair<int, int>>> sums;
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                sums[nums[i] + nums[j]].push_back(make_pair(i, j));
            }
        }

        for (int i = 0; i < sz; ++i) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < sz; ++j) {
                if (j != i + 1 && nums[j] == nums[j-1]) continue; 
                vector<pair<int, int>> tmp = sums[target-nums[i]-nums[j]];
                for (const auto& p : tmp) {
                    if (j < p.first) {
                        res.push_back(
                            vector<int>{nums[i], nums[j], nums[p.first], nums[p.second]});
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums{-458,-442,-428,-421,-408,-402,-385,-377,-377,-318,-318,-298,-230,-225,-203,-150,-130,-125,-124,-106,-86,-71,-59,-11,-3,37,59,92,94,97,108,145,188,189,190,239,257,270,281,296,308,309,355,405,412,416,429,434,438,455,460,462,466,469};
    vector<vector<int> > a = sol.fourSum(nums, -6120);
    for (auto & b : a) {
        cout << b.size() << endl;
    }
    return 0;
}

