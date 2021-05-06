/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
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
#include <climits>
using namespace std;

// int_min -2147483648
class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        if (dividend == divisor) {
            return 1;
        }
        int up = abs(dividend);
        int down = abs(divisor);
        // up < 0 溢出
        int carry = 0;
        if (dividend == INT_MIN) {
            if (down == 1) {
                return (divisor > 0) ? INT_MIN : INT_MAX;
            }
            // 防溢出
            up = INT_MAX;
            if (down > 0) {
                int two_power = 2;
                for (int i = 0; i < 30; i++) {
                    if (down == two_power) {
                        carry = 1;
                        break;
                    }
                    two_power <<= 1;
                }
            }
        }
        // down < 0 溢出
        if (divisor == INT_MIN) {
            return 0;
        }
        while (up >= down) {
            int base = down;
            int temp = 1;
            // 防溢出
            while ((base << 1) > 0 && up > (base << 1)) {
                temp <<= 1;
                base <<= 1;
            }
            up -= base;
            ans += temp;
        }
        ans += carry;
        ans = ((dividend > 0) ^ (divisor > 0)) ? -ans : ans;
        return ans;
    }
};

// @lc code=end

// int main() {
//     Solution sol;
//     cout << sol.divide(-2147483648, -1109186033) << endl;
//     cout << sol.divide(-2147483648, 122481295) << endl;
//     cout << sol.divide(-2147483648, 128) << endl;
//     cout << sol.divide(-2147483648, -1073741824) << endl;
//     cout << sol.divide(-1, -2147483648) << endl;
// }