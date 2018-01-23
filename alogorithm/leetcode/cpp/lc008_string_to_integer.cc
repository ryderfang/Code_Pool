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
const long long min_int = -2147483648;

// leading whitespace, optional inital +/-, overflow, empty str.. 
class Solution {
    public:
        int myAtoi(string str) {            
            if (str.empty()) return 0;
            int i = -1;
            while (str[++i] == ' ');
            bool is_negative = (str[i] == '-');
            if (str[i] == '-' || str[i] == '+') ++i;
            stack<int> nums;
            for (; i < str.size(); ++i) {
                if (!isdigit(str[i])) {
                    break;
                } else {
                    nums.push(str[i] - '0'); 
                }
            }
            long long radix = 1;
            long long res = 0;
            while (!nums.empty()) {
                res += nums.top() * radix;
                if (is_negative && res >= -min_int) {
                    res = -min_int;
                    break;
                } else if (!is_negative && res >= max_int) {
                    res = max_int;
                    break;
                }
                radix *= 10;
                nums.pop();
            }
            res = is_negative > 0 ? -res : res;
            return (int)res;
        }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("   -123") << endl;;
}
