#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
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
    int hammingDistance(int x, int y) {
        int ret = 0;
        int exor = x ^ y;
        while (exor > 0) {
            if (exor & 1) ret++;
            exor >>= 1;
        }
        return ret;
    }
};

