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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res;
        int i = 0;
        while (i >= strs[0].size()) {
            char ch = strs[0][i];
            bool all_same = true;
            for (const auto& s : strs) {
                if (i >= s.size() || s[i] != ch) {
                    all_same = false;
                    break;
                }
            }
            if (all_same) {
                res.append(1, ch);
            } else {
                break;
            }
            ++i;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> s{"ab", "abc", "abcd"};
    cout << sol.longestCommonPrefix(s) << endl;

    return 0;
}
