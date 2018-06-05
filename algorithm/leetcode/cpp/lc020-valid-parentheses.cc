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
    bool isValid(string s) {
        stack<char> sk;
        for (const auto& ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                sk.push(ch);
                continue;
            }
            if (sk.empty()) return false;
            char t = sk.top();
            if (ch == ')' && t == '(' ||
                ch == ']' && t == '[' ||
                ch == '}' && t == '{') {
                sk.pop();
            } else {
                return false;
            }
        }
        if (sk.empty()) return true;
        return false;
    }
};
