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
     * @param n: An integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
        LL sum = 0;
        while (n > 0) {
            sum += n / 5;
            n = n / 5;
        }
        return sum;
    }
};
