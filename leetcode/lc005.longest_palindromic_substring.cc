#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start_pos = 0, max_len = 1; 
        // substr's length is odd
        for (int i = 1; i < s.size() - 1; ++i) {
            int j = 1;
            while (j <= i && i + j < s.size() && s[i-j] == s[i+j]) ++j; 
            if (2 * j - 1 > max_len) {
                start_pos = i - j + 1;
                max_len = 2 * j - 1;
            }
        }
        // substr's length is even
        for (int i = 0; i < s.size() - 1 ; ++i) {
            if (s[i] != s[i+1]) {
                continue;
            }
            int j = 1;
            while (j <= i && i + 1 + j < s.size() && s[i-j] == s[i+1+j]) ++j;
            if (2 * j > max_len) {
                start_pos = i - j + 1;
                max_len = 2 * j;
            }
        }
        return s.substr(start_pos, max_len);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("abb") << endl;
    return 0;
}
