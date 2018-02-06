#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;

class Solution {
public:
    /*
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        vector<int> f, g;
        f.push_back(nums[0]);
        g.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            f.push_back(max(max(f[i-1] * nums[i], g[i-1] * nums[i]), nums[i]));
            g.push_back(min(min(f[i-1] * nums[i], g[i-1] * nums[i]), nums[i]));
        }
        int m = f[0];
        for (int i = 0; i < f.size(); i++) {
            m = max(m, f[i]);
        }
        return m;
    }
};

