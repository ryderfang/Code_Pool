
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
    * @param x: An integer
    * @return: The sqrt of x
    */
    int sqrt(int x) {
        if (x == 0) {
            return 0;
        }
        LL left = 1;
        LL right = x;
        while (left < right - 1) {
            LL mid = (left + right) >> 1;
            if (mid * mid <= x) {
                left = mid;
            } else if (mid * mid > x) {
                right = mid - 1;
            }
        }
        if (right * right <= x) {
            left = right;
        }
        return left;
    }
};

int main() {
    Solution sol;
    cout << sol.sqrt(999999999);

    return 0;
}

