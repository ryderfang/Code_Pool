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
    int romanToInt(string s) {
        vector<vector<string> > dict {
            {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"M", "MM", "MMM"}
        };
        int res = 0;
        int pos = 0;
        for (int i = dict[3].size() - 1; i >= 0; --i) {
            if (s.find(dict[3][i], pos) == pos) {
                res += (i + 1) * 1000;
                pos += dict[3][i].size();
                break;
            }
        }
        for (int i = dict[2].size() - 1; i >= 0; --i) {
            if (s.find(dict[2][i], pos) == pos) {
                res += (i + 1) * 100;
                pos += dict[2][i].size();
                break;
            }
        }
        for (int i = dict[1].size() - 1; i >= 0; --i) {
            if (s.find(dict[1][i], pos) == pos) {
                res += (i + 1) * 10;
                pos += dict[1][i].size();
                break;
            }
        }
        for (int i = dict[0].size() - 1; i >= 0; --i) {
            if (s.find(dict[0][i], pos) == pos) {
                res += (i + 1);
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.romanToInt("MCMLXXVI") << endl;

    return 0;
}
