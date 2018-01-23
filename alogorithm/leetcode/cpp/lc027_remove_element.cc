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
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        auto p = nums.begin();
        while (p != nums.end()) {
            if (*p == val) {
                p = nums.erase(p);
            } else {
                ++p;
                ++res;
            }
        }
        return res;
    }
};
