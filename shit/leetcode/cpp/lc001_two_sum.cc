#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    struct Tmpl {
        Tmpl(int _v, int _i) : val(_v), index(_i) { }
        int val, index;
    };

    bool my_bsearch(const vector<Tmpl>& nums, int begin, int end, int val, int& val_i) {
        while (begin <= end) {
            int mid = (begin + end) >> 1;
            if (nums[mid].val == val) {
                val_i = nums[mid].index;
                return true;
            } else if (nums[mid].val < val) {
                begin = mid + 1;
            } else end = mid - 1;
        }
        val_i = -1;
        return false;
    }
    
    // O(nlogn)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int sz = nums.size();
        vector<Tmpl> num_st;
        for (int i = 0; i < nums.size(); ++i) {
            num_st.push_back(Tmpl(nums[i], i));
        }
        sort(num_st.begin(), num_st.end(), 
            [](const Tmpl& a, const Tmpl& b) {
                return a.val < b.val || (a.val == b.val && a.index < b.index);
            }
        );

        // O(nlogn)
        /*
        for (int i = 0; i < sz; ++i) {
            int j = -1, k = -1;
            if (my_bsearch(num_st, 0, i - 1, target - num_st[i].val, j) ||
                my_bsearch(num_st, i + 1, sz - 1, target - num_st[i].val, k)) {
                res.push_back(num_st[i].index);
                res.push_back(max(j, k));
                return res;
            }
        }
        */

        // O(n)
        int p = 0, q = sz - 1;
        while (p < q) {
            if (num_st[p].val + num_st[q].val == target) break;
            else if (num_st[p].val + num_st[q].val < target) ++p;
            else --q;
        }
        res.push_back(num_st[p].index);
        res.push_back(num_st[q].index);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> temp{3, 2, 4};
    vector<int> res = sol.twoSum(temp, 6);
    return 0;
}
