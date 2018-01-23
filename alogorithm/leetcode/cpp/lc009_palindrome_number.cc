#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x == 0) return true;
            if (x < 0) return false;

            int radix = 1;
            int cnt = 1;
            int tmp = x;
            while (tmp /= 10) {
                radix *= 10;
                cnt++;
            }
            if (cnt == 1) return true;
            tmp = x;
            cnt >>= 1;
            int high = radix;
            while (cnt) {
                if (tmp / high == tmp % 10) {
                    tmp = (tmp % high) / 10; 
                    high /= 100;
                } else {
                    return false;
                }
                --cnt;
            }
            return true;
        }
};

