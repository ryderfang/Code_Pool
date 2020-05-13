/**
有 n 枚硬币在桌子上排成一排，编号从左到右从 1 至 n。一些硬币正面朝上，其它硬币背面朝上。玩家可以按以下伪代码中的 flip 函数描述的规则翻转硬币：
procedure flip(
  i: the index of the coin to flip)
Flip the i-th coin
if i > 1
  check(i − 1, i)
if i < n
  check(i + 1, i)
	
procedure check(
  i: the index of the coin to check,
  p: the index of the previous flipped coin)
if the side of the i-th and p-th coins facing upward is different
  flip(i)

  给出每枚硬币的初始状态和目标状态，求玩家最少需要调用几次 flip 函数才能将所有硬币从初始状态调整为目标状态。请注意，每次调用 flip 函数时，函数的参数可以不同。


# Input

有多组测试数据。第一行输入一个整数 T 代表测试数据组数。对于每组测试数据：

第一行输入一个整数 n (1 <= n <= 10^5)，代表硬币的数量。

第二行输入一个字符串 A = a1a2...an (ai ∈ {‘0’,‘1’}) 代表每枚硬币的初始状态。若 ai = ‘0’ 则第 i 枚硬币一开始正面朝上，否则背面朝上。

第三行输入一个字符串 B = b1b2...bn (bi ∈ {‘0’,‘1’}) 代表每枚硬币的目标状态。若 bi = ‘0’ 则第 i 枚硬币的目标为正面朝上，否则为背面朝上。

保证所有数据的 n 之和不超过 5 * 10^5

# Output

每组数据输出一行一个整数，代表将所有硬币从初始状态调整为目标状态最少需要调用多少次 flip 函数。若无论调用多少次都无法满足要求，则输出 "-1"（不输出引号）。

# Sample Input

2
12
110101110011
110111111111
3
101
010

# Sample Output

2
-1

# Hint

对于第一组样例数据，玩家可以先调用 flip(7)（硬币的状态将会变为 110100000011），然后再调用 flip(5)。所以答案是 2。

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
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;
const LL MAXN = 100001;

char a[MAXN], b[MAXN];
int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s %s", a, b);
        int ret = 0;
        int diff = (a[0] != b[0]);
        for (int i = 1; i < n; i++) {
            if (b[i] != b[i-1]) {
                // 结尾不同
                if (a[i-1] != b[i-1]) {
                    ret = -1;
                    break;
                }
                ret += diff;
                diff = 0;
                // 开头不同
                if (a[i] != b[i]) {
                    ret = -1;
                    break;
                }
            } else {
                if (a[i] != a[i-1] && a[i] != b[i]) {
                    diff++;
                }
            }
        }
        if (ret != -1) {
            ret += diff;
        }
        printf("%d\n", ret);
    }
}


/*
 * 将 b 连续相同的字符分成 N 组，在每个组内检查 a，每组开头和结尾必须满足 ai = bi，否则无法翻转；可以通过反证得到这个结论。
 * 每个组内翻转次数等于 a 与 b 不同的连续串个数。
 */
