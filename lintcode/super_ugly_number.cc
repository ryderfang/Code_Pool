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
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int> primes) {
        vector<int> uglys(n, INT_MAX);
        vector<int> dp(primes.size(), 0);
        uglys[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < primes.size(); j++) {
                uglys[i] = min(uglys[i], uglys[dp[j]] * primes[j]);
            }
            for (int j = 0; j < primes.size(); j++) {
                if (uglys[i] == uglys[dp[j]] * primes[j]) {
                    ++dp[j];
                }
            }
        }
        return uglys.back();
    }
};
