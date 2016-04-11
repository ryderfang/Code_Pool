#include <algorithm>
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
    string intToRoman(int num) {
        vector<vector<string> > dict = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"}
        };
        string res;
        res.append(dict[3][num / 1000 % 10]);
        res.append(dict[2][num / 100 % 10]);
        res.append(dict[1][num / 10 % 10]);
        res.append(dict[0][num % 10]);
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.intToRoman(3999) << endl;
    return 0;
}
