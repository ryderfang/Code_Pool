#include <iostream>
#include <string>
using namespace std;

void simple_kmp(const string& S, const string& T) {
    // next[i] -> 长度为i的T的子串中最大公共长度（前缀=后缀）
    int next[T.size() + 1];
    next[0] = next[1] = 0;
    size_t j = 0;
    for (size_t i = 1; i < T.size(); ++i) {
        while (j > 0 && T[i] != T[j]) j = next[j];
        if (T[i] == T[j]) ++j;
        next[i+1] = j;
    }
    // match
    j = 0;
    for (size_t i = 0; i < S.size(); ++i) {
        while (j > 0 && S[i] != T[j]) j = next[j];
        if (S[i] == T[j]) ++j;
        if (j = T.size()) {
            cout << "find at pos " << i - j + 1 << endl;
            j = next[j];
        }
    }
}

// extend[i] -> S[i..n]与T的最长公共前缀 
void extend_kmp(const string& S, const string& T, int extend[]) {
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

int main() {
    string text = "this is the Sgin text, and this is a simle kmp.";
    string pattern = "is is";
    simple_kmp(text, pattern);
    int ex[text.size() + 1];
    extend_kmp(text, pattern, ex);

    return 0;
}

