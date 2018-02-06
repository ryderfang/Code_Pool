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
    // nums - sorted
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        auto p = nums.begin();
        while (p != nums.end()) {
            auto q = p;
            while (p + 1 != nums.end() && *p == *(p + 1)) ++p;
            p = nums.erase(q, p);
            ++res;
            ++p;
        }
        return res;
    }
};

