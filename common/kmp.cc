#include <iostream>
#include <string>
using namespace std;

void simple_kmp(const string& ori, const string& pat) {
    int next[pat.size() + 1];
    // next[i] -> 长度为i的子串中最大公共长度（前缀=后缀）
    next[0] = next[1] = 0;
    size_t j = 0;
    for (size_t i = 1; i < pat.size(); ++i) {
        while (j > 0 && pat[i] != pat[j]) j = next[j];
        if (pat[i] == pat[j]) ++j;
        next[i+1] = j;
    }
    // match
    j = 0;
    for (size_t i = 0; i < ori.size(); ++i) {
        while (j > 0 && ori[i] != pat[j]) j = next[j];
        if (ori[i] == pat[j]) ++j;
        if (j == pat.size()) {
           cout << "find at pos " << i - j + 1 << endl;
           j = next[j];
        }
    }
}

int main() {
    string text = "this is the origin text, and this is a simle kmp.";
    string pat = "is is";
    simple_kmp(text, pat);
    return 0;
}

