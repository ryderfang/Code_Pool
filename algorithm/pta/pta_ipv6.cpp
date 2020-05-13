/*

网际协议第 6 版（IPv6）是网际协议（IP）的最新版本。该协议用以鉴别并定位网络上的计算机，并对网络流量进行路由。该协议使用 128 个二进制位代表一个网络地址，其设计目的是为了替换第 4 版协议。

IPv6 的 128 位地址可以分为 8 组，每组各 16 位。我们可以将每组二进制位写成 4 个十六进制数，各组之间用冒号（:）分隔。例如，2001:0db8:0000:0000:0000:ff00:0042:8329 就是一个 IPv6 地址。

方便起见，一个 IPv6 地址可以按以下规则缩写为一个更加简短的表现形式：

每一组十六进制数的前导零会被去除。例如，0042 将变为 42。
连续多组十六进制表示的 0 会被一对双冒号（::）替换。请注意，一个地址中双冒号至多出现一次，否则该缩写对应的完整 IPv6 地址可能无法确定。
以下是这些简写规则的使用范例：

完整 IPv6 地址：2001:0db8:0000:0000:0000:ff00:0042:8329
去除每组十六进制数中的前导零后：2001:db8:0:0:0:ff00:42:8329
省略连续的十六进制零后：2001:db8::ff00:42:8329
根据上述规则，回环地址 0000:0000:0000:0000:0000:0000:0000:0001 可以被简写为 ::1

你的任务就是将一个缩写后的 IPv6 地址改写为一个完整的地址。

* Input

有多组测试数据。第一行输入一个整数 T（约 1000）代表测试数据组数。对于每组测试数据：

第一行输入一个字符串 s 代表一个合法的缩写后的 IPv6 地址，保证 s 只包含数字、小写字母和冒号。

* Output

每组数据输出一行一个字符串，代表完整的 IPv6 地址。

* Sample Input

4
7abc::00ff:fffc
fc:0:0:8976:0:0:0:ff
2c0f:9981::
::

* Sample Output

7abc:0000:0000:0000:0000:0000:00ff:fffc
00fc:0000:0000:8976:0000:0000:0000:00ff
2c0f:9981:0000:0000:0000:0000:0000:0000
0000:0000:0000:0000:0000:0000:0000:0000

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

string ip[MAXN];
int main() {
    int T;
    cin >> T;
    string s;
    while (T--) {
        for (int i = 0; i < MAXN; i++) {
            ip[i] = "0000";
        }
        cin >> s;
        size_t lidx = 0;
        size_t pre = 0;
        while (pre < s.size() && s[pre] != ':') {
            size_t now = s.find_first_of(':', pre);
            if (now == string::npos) {
                break;
            }
            ip[lidx++] = s.substr(pre, now - pre);
            pre = now + 1;
        }
        pre = s.size() - 1;
        size_t ridx = MAXN -1;
        while (pre >= 0 && s[pre] != ':') {
            size_t now = s.rfind(':', pre);
            if (now == string::npos) {
                break;
            }
            ip[ridx--] = s.substr(now + 1, pre - now);
            pre = now - 1;
        }
        for (int i = 0; i < MAXN; i++) {
            if (i != 0) {
                cout << ':';
            }
            cout << setw(4) << setfill('0') << ip[i];
        }
        cout << endl;
    }
    return 0;
}

