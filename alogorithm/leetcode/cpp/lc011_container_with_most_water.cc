#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        struct Line {
            int x, h;
        };
        vector<Line> ln_vec;
        int sz = height.size();
        ln_vec.resize(sz);
        for (int i = 0; i < sz; ++i) {
            ln_vec[i].x = i;
            ln_vec[i].h = height[i];
        }
        sort(ln_vec.begin(), ln_vec.end(), 
             [](const Line& a, const Line& b) {
                 return a.h > b.h;
             });
        int min_index = ln_vec[0].x;
        int max_index = ln_vec[0].x;
        for (int i = 1; i < sz; ++i) {
            int area = max(abs(ln_vec[i].x - min_index), abs(max_index - ln_vec[i].x));
            area *= ln_vec[i].h;
            res = max(res, area);
            min_index = min(min_index, ln_vec[i].x);
            max_index = max(max_index, ln_vec[i].x);
        }
        return res;
    }
};

int main() {
    int a[] = {1, 2, 3, 7, 8};
    vector<int> h(a, a + 5);
    Solution sol;
    cout << sol.maxArea(h) << endl;
    return 0;
}
