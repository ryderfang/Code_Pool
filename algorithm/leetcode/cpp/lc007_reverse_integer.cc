#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// numeric_limits<int>::max()
const long long max_int = 2147483647;
const long long min_int = 2147483648;

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        bool is_negative = x < 0 ? true : false;
        stack<int> nums;
        // abs(x) may overflow, eg. -2147483648
        long long tmp = x;
        tmp = abs(tmp);
        while (tmp) {
            nums.push(tmp % 10);
            tmp /= 10;
        }
        long long radix = 1;
        while (!nums.empty()) {
            res += nums.top() * radix;
            nums.pop();
            radix *= 10;
        }
        if (is_negative && res > min_int ||
            !is_negative && res > max_int) {
            res = 0;
        } else {
            res = is_negative ? -res : res;
        }
        return (int)res;
    }
};

int main() {
    Solution sol;
    cout << sol.reverse(-2147483648) << endl;
    return 0;
}
