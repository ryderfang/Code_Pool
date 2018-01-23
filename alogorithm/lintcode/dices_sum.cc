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
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        vector<pair<int, double>> results;
        // f[i][j] -> sum == j with i dices
        vector<vector<double>> f(n + 1, vector<double>(6 * n + 1));
        for (int i = 1; i <= 6; i++) {
            f[1][i] = 1.0 / 6;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= 6 * i; j++) {
                // k is the point of last dices
                for (int k = 1; k <= 6; k++) {
                    if (j > k) {
                        f[i][j] += f[i - 1][j - k];
                    }
                }
                f[i][j] /= 6.0;
            }
        }

        for (int i = n; i <= 6 * n; i++) {
            results.push_back(make_pair(i, f[n][i]));
        }

        return results;
    }
};
