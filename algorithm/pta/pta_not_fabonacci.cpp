/*
二进制字符串是由数字 0 和 1 组成的字符串。给定一个二进制字符串 s=s1s2...sn(n>=3)，您需要将里面的数字重新排列，
使得重新排列后的字符串对于所有 3 <= i <= n 满足 s(i-2) + s(i-1) != s(i)

Input / 输入格式

有多组测试数据。第一行输入一个整数 T 代表测试数据组数。对于每组测试数据：
第一行输入一个二进制字符串 s (3 <= |s| <= 10^5), si <- {0, 1}
保证所有数据中 ∣s∣ 之和不超过 10^6。

Output / 输出格式
对于每组数据，若存在符合要求的重排列，输出一行重排列后的字符串（若有多种合理答案，您可以输出任意一种），否则输出 "Impossible"（不输出引号）。

Sample Input / 样例输入
2
01110
000

Sample Output / 样例输出
11100
Impossible
 */

//
// Created by ryderfang on 2020/4/24.
//

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;
const LL MAXN = 8;

int main() {
    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> s;
        int c0 = 0;
        int c1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                c0++;
            } else {
                c1++;
            }
        }
        if (c0 > 2 * c1 + 2) {
            cout << "Impossible" << endl;
        } else {
            int loop = min(c0 / 2, c1);
            int pre1 = c1 - loop;
            string result = "";
            result.append(pre1, '1');
            int c = loop;
            while (c--) {
                result.append("001");
            }
            result.append(c0 - loop * 2, '0');
            cout << result << endl;
        }
    }

    return 0;
}

/*
 * 0, 1 排列满足条件的只能是 111100100100100 这种样式的，而 0 的个数最多是 00100100100 这种情况
 * 也就是 c1 * 2 + 2 < c0 则无解，否则每两个 0 放一个 1，多余的 1 放开头
 */


