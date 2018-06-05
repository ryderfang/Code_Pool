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
    int kmp(string s, string p) {
        // next[j] -> 前j个元素首尾相同的长度 [0, next[j]) == [j-next[j], j)
        int next[p.size() + 1];
        next[0] = -1;
        next[1] = 0;
        int i, j;
        for (i = 2, j = 0; i < p.size(); ++i) {
            while (j >= 0 && p[i-1] != p[j]) j = next[j];
            next[i] = j + 1;
            ++j;
        }
        for (i = 0, j = 0; i < s.size() && j < p.size();) {
            if (j >= 0 && s[i] != p[j]) j = next[j];
            else ++i, ++j;
            if (j < 0) j = 0, ++i;
        }
        if (j == p.size()) return i - p.size();
        else return -1;
    }

    int strStr(string haystack, string needle) {        
        return kmp(haystack, needle);
    }
};

int main() {
    Solution sol;
    cout << sol.kmp("abcdeabacd", "aba") << endl;
    return 0;
}
