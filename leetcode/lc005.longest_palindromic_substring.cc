#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        // O(n^2)
        string longestPalindrome_1(string s) {
            if (s.empty()) return "";
            int start_pos = 0, max_len = 1; 
            int s_sz = s.size();
            // substr's length is odd
            for (int i = 1; i < s_sz - 1; ++i) {
                int j = 1;
                while (j <= i && i + j < s_sz && s[i-j] == s[i+j]) ++j; 
                if (2 * j - 1 > max_len) {
                    start_pos = i - j + 1;
                    max_len = 2 * j - 1;
                }
            }
            // substr's length is even
            for (int i = 0; i < s_sz - 1 ; ++i) {
                if (s[i] != s[i+1]) {
                    continue;
                }
                int j = 1;
                while (j <= i && i + 1 + j < s_sz && s[i-j] == s[i+1+j]) ++j;
                if (2 * j > max_len) {
                    start_pos = i - j + 1;
                    max_len = 2 * j;
                }
            }
            return s.substr(start_pos, max_len);
        }

        string longestPalindrome(string s) {
            int s_sz = s.size();
            int is_odd = s_sz % 2;
            int mid = (s_sz + 1) / 2;
            string r_s(s);
            std::reverse(r_s.begin(), r_s.end());
            string r_left = r_s.substr(mid - is_odd);
            string r_right = r_s.substr(0, mid - is_odd);

            int extend_left[s_sz + 1];
            int extend_right[s_sz + 1]; 
            // [0..mid]
            extend_kmp(s.substr(0, mid), r_left, extend_right);
            extend_kmp(r_left, s.substr(mid), extend_left);
            for (int i = 0; i < mid; ++i) {
               if (extend_right[i] * 2 >= mid - i) {
                    int len = extend_left[i+1] * 2 + mid - i; 
                    if (len > max_palin_.size()) {
                        max_pos_ = i - extend_left[i+1];
                        max_palin_ = s.substr(max_pos, len); 
                    }
               }
            }
            // [mid+1..sz]
            extend_kmp(r_right, s.substr(mid), extend_left);
            extend_kmp(s.substr(mid), r_left, extend_right);
            for (int i = mid; i < s_sz; ++i) {
                if (extend_left[
            }
        }

    private:

        // extend[i] -> S[i..n]与T的最长公共前缀 
        void extend_kmp(const string& S, const string& T, int* extend) {
            int t_sz = T.size();
            // next[i] -> T[i..m]与T的最长公共前缀
            int next[t_sz + 1];  
            next[0] = t_sz; 
            int i = 0;
            while (T[i] == T[i+1] && i + 1 < t_sz) ++i;
            next[1] = i;
            // p0 -> [1..k-1]中匹配到最远位置(next[p0] + p0 - 1)的起点
            int p0 = 1;
            for (int k = 2; k < t_sz; ++k) {
                if (next[k-p0] < next[p0] + p0 - k) {
                    next[k] = next[k-p0]; 
                } else {
                    int j = next[p0] + p0 - k;
                    j = j < 0 ? 0 : j;
                    while (j + k < t_sz && T[j+k] == T[j]) ++j;
                    next[k] = j;
                    // next[p0] + p0 <= next[k] + k, 更新p0
                    p0 = k;
                }
            }

            i = 0;
            int s_sz = S.size();
            while (S[i] == T[i] && i < s_sz && i < t_sz) ++i;
            extend[0] = i;
            p0 = 0;
            for (int k = 1; k < s_sz; ++k) {
                if (next[k-p0] < extend[p0] + p0 - k) {
                    extend[k] = next[k-p0];
                } else {
                    int j = extend[p0] + p0 - k;
                    j = j < 0 ? 0 : j;
                    while (j + k < s_sz && j < t_sz && S[j+k] == T[j]) ++j;
                    extend[k] = j;
                    p0 = k;
                }
            }
        }
    private:
        int max_pos_;

        string max_palin_;
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("abafcdgabb") << endl;
    return 0;
}

