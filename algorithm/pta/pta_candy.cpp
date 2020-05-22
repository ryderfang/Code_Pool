/*
 * Alice 和 Bob 买了一些糖果，他们准备用这些糖果玩一个游戏。游戏规则如下
 * 
 * Alice 和 Bob 轮流拿取糖果。
 * 轮到 Alice 时，每次她必须拿走恰好一颗糖果。
 * 轮到 Bob 时，每次他必须拿走至少两颗口味相同的糖果。
 * 轮到 Alice 时，若没有剩余糖果可以拿取，则判 Alice 输。
 * 轮到 Bob 时，若不存在两颗口味相同的糖果，则判 Bob 输。
 * Alice 和 Bob 都会采用最优策略进行游戏。给出他们购买的糖果的信息以及谁第一个拿取糖果，求最终的胜利者。
 *
 * Input
 *
 * 只有一组测试数据。
 * 第一行输入一个整数 n (1≤n≤300) 和一个字符串 s (s∈{“Alice”,“Bob”})，代表两人购买的糖果数量以及先手玩家。
 * 第二行输入 n 个整数 a1,a2,...,an(1<=ai<=300), 其中 ai 代表第 i 颗糖果的口味。糖果 i 和 j 拥有相同口味若 ai = aj。
 *
 * Output
 *
 * 输出一行一个字符串代表胜利者的名字。
 *
 * Sample Input
 *
 *  4 Alice
 *  1 2 3 1
 *
 * Sample Output
 * 
 * Alice
 *
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
const LL MAXN = 1001;

int a[MAXN];
int main() {
    int n;
    string s;
    cin >> n >> s;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (mp.count(a[i])) {
            mp[a[i]]++;
        } else {
            mp[a[i]] = 1;
        }
    }
    int one_count = 0;
    int two_count = 0;
    map<int, int>::iterator iter = mp.begin();
    while (iter != mp.end()) {
        int count = iter->second;
        if (count == 1) {
            one_count++;
        } else if (count == 2) {
            two_count++;
        }
        iter++;
    }
    if (one_count == 0) {
        if (two_count == 0) {
            cout << "Bob";
        } else if (two_count == 1) {
            cout << s;
        } else {
            cout << "Alice";
        }
    } else {
        cout << "Alice";
    }
    cout << endl;
    return 0;
}

/*
 * one_count > 0
 * 若存在一种只有 1 颗的糖果（设为种类 x），由于 Bob 永远拿不走这种糖果，所以轮到 Alice 时，要么只剩种类 x 的糖果（那么 Alice 拿走它即可获胜），
   要么还剩其它糖果（那么 Alice 可以先拿其它糖果）。也就是说，在这种情况下 Alice 总能操作，Alice 必胜。

 * one_count == 0 && two_count == 0
 * 若每种糖果都有至少 3 颗。若 Alice 先手，由于 Alice 一次无法拿空一种糖果且这种糖果至少剩两个，那么 Bob 就可以把刚才 Alice 拿的那种糖果全部拿空。也就是说 Bob 总是可以操作；
   若 Bob 先手则 Bob 一开始可以直接拿空一种糖果，就回到了 Alice 先手的情况。也就是说，在这种情况下 Bob 必胜。

 * one_count == 0 && two_count = 1
 * 若仅存在一种只有 2 颗的糖果（设为种类 y，其它种类的糖果都至少有 3 颗），若 Alice 先手则 Alice 可以先拿走 1 颗种类 y 的糖果，就回到了第一种情况的讨论，也就是说 Alice 必胜；
   若 Bob 先手则 Bob 可以拿走所有种类 y 的糖果，就回到了第二种情况的讨论，也就是说 Bob 必胜。

 * two_count > 1
 * 若存在多种只有 2 颗的糖果，因为有不止 1 种糖果所以 Alice 至少有一次操作机会，且轮到 Alice 操作时还存在有 2 颗的糖果。
   那么 Alice 可以拿走 1 颗该种类糖果，就回到了第一种情况的讨论，也就是说 Alice 必胜。
 */

