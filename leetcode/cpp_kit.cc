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
    // 二进制1的个数
    int countOnes(int num) {
        int c = 0;
        while (num) {
            num &= (num - 1);
            c++;
        }
        return c;
    }
    // O(1)判断2的幂
    bool checkPowerOf2(int n) {
        if (n <= 0) {
            return false;
        }
        return !(n & (n - 1));
    }

};

