#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows < 2) return s;
            vector<string> zig;
            int sz = s.size();
            zig.resize(numRows, string(sz, 0));
            if (numRows == 2) {
                int si = 0;
                int j = 0;
                while (si < sz) {
                    if (j & 1) {
                        int fill_blank = ((j - 1) >> 1) & 1;
                        zig[fill_blank][j] = s[si++];
                        zig[1-fill_blank][j] = ' ';
                    } else {
                        int from_top = (j >> 1) & 1;
                        zig[from_top][j] = s[si++];
                        if (si < sz) zig[1-from_top][j] = s[si++];
                    }
                    ++j;
                }
            } else {
                int si = 0;
                int j = 0;
                while (si < sz) {
                    int r = j % (numRows - 1);
                    if (r == 0) {
                        for (int k = 0; k < numRows; ++k) {
                            if (si < sz) zig[k][j] = s[si++];
                            else break;
                        }
                    } else {
                        for (int k = 0; k < numRows; ++k) {
                            zig[k][j] = ' ';
                        }
                        zig[numRows-1-r][j] = s[si++];
                    }
                    ++j;
                }
            }
            string res;
            for (const auto& line : zig) {
                for (int i = 0; line[i] != '\0'; ++i) {
                    if (line[i] != ' ') res.push_back(line[i]);
                }
            }
            return res;
        }
};

int main() {
    Solution sol;
    sol.convert("ABCDEFGHIJKLMN", 4);

    return 0;
}
