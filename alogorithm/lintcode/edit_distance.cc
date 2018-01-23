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
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        int row = word1.size() + 1;
        int col = word2.size() + 1;
        vector<vector<int> > dp(row, vector<int>(col));
        for (int i = 0; i < row; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < col; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                dp[i][j] = min(dp[i][j], min(dp[i-1][j] + 1, dp[i][j-1] + 1));
            }
        }
        return dp[row - 1][col - 1];
    }
};

