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
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (s == nullptr || p == nullptr) {
            return false;
        }

        int slen = strlen(s);
        int plen = strlen(p);
        vector<vector<bool> > dp(slen + 1, vector<bool>(plen + 1));
        for (int i = 0; i <= slen; i++) {
            for (int j = 0; j <= plen; j++) {
                if (j == 0) {
                    dp[i][j] = (i == 0);
                    continue;
                }
                if (p[j - 1] == '*' && j >= 2) {
                    for (int k = 0; k <= i; k++) {
                        if (k != 0 && !isSame(s[i - k], p[j - 2])) {
                            dp[i][j] = false;
                            break;
                        }
                        if (dp[i - k][j - 2]) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                } else {
                    dp[i][j] = (i >= 1) && isSame(s[i - 1], p[j - 1]) && (dp[i - 1][j - 1]);
                }
            }
        }
        return dp[slen][plen];
    }

    bool isSame(char a, char b) {
        return a == b || b == '.';
    }
};

int main() {
    Solution sol;
    cout << sol.isMatch("bbabacccbcbbcaaab", "*a*b..b*b");

    return 0;
}
