#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ascii_count = 256;
// visited[i] -> 字符i上次出现的位置
int visited[ascii_count + 1];

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::fill(visited, visited + sizeof(visited), -1);
        int start_pos = 0;
        int max_len = 0;
        int cur_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (visited[s[i]] == -1) {
                ++cur_len;
            } else {
                if (start_pos <= visited[s[i]]) {
                    cur_len = i - visited[s[i]];
                    start_pos = visited[s[i]] + 1;
                } else {
                    ++cur_len;
                }
            }
            visited[s[i]] = i;
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    string s;
    while (cin >> s) {
        cout << sol.lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}
