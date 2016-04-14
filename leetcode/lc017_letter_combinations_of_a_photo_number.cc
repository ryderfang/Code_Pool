#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void get_combi(const string& digits, int index, string s, vector<string>& res) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        } 
        string ps = phone[digits[index]];
        for (const auto& ch : ps) {
            string t = s;
            t.append(1, ch);
            get_combi(digits, index + 1, t, res);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>();
        for (const auto& ch : digits) {
            if (!phone.count(ch)) return vector<string>();
        }
        vector<string> res;
        string tmp;
        get_combi(digits, 0, tmp, res); 
        return res;
    }
private:
    static map<char, string> phone;
};

map<char, string> Solution::phone {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

int main() {
    Solution sol;
    vector<string> res = sol.letterCombinations("");
    return 0;
}
