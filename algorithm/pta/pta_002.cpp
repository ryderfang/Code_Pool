/**
 一个三阶幻方就是一个由数字 1 至 9 组成的 3×3 的矩阵，矩阵内元素两两不相同。

允许对三阶幻方进行以下操作：

选择其中一行，并将该行最右边的元素移动到最左边。
选择其中一列，并将该列最下方的元素移动到最上方。
给出一个三阶幻方，求将其转换为另一个三阶幻方的最小操作数。


# Input

有多组测试数据。第一行输入一个整数 T (1 <= T <= 2 * 10^4) 代表测试数据组数。对于每组测试数据：

前三行中第 i 行输入一个字符串 si (|si| = 3)，其中 sij 表示初始幻方中第 i 行第 j 列的数字。

接下来三行中第 i 行输入一个字符串 ti (|ti| = 3)，其中 tij 表示目标幻方中第 i 行第 j 列的数字。

# Output

每组数据输出一行一个整数，代表所需的最少操作数。

若无法将幻方从初始状态转化为目标状态，则输出 "impossible"（不输出引号）。

# Sample Input

4
123
456
789
231
456
789
457
213
689
257
361
489
927
641
358
297
651
384
123
456
789
123
456
789

# Sample Output

2
3
impossible
0

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
//const LL MAXN = 100001;

const int min_mat = 123456789;
map<int, int> matrix;
queue<int> my_queue;
LL counter = 0;

template<typename T, int N>
void _round(T (&d)[N], int a, int b, int c) {
    T temp = d[c];
    d[c] = d[b];
    d[b] = d[a];
    d[a] = temp;
}

int _op(int t, int row, int col) {
    int d[10];
    d[1] = t / 100000000;
    d[2] = (t / 10000000) % 10;
    d[3] = (t / 1000000) % 10;
    d[4] = (t / 100000) % 10;
    d[5] = (t / 10000) % 10;
    d[6] = (t % 10000) / 1000;
    d[7] = (t % 1000) / 100;
    d[8] = (t % 100) / 10;
    d[9] = t % 10;
    int temp;
    switch (row) {
        case 0:
            _round(d, 1, 2, 3);
            break;
        case 1:
            _round(d, 4, 5, 6);
            break;
        case 2:
            _round(d, 7, 8, 9);
            break;
    }
    if (row < 0) {
        switch (col) {
            case 0:
                _round(d, 1, 4, 7);
                break;
            case 1:
                _round(d, 2, 5, 8);
                break;
            case 2:
                _round(d, 3, 6, 9);
                break;
        }
    }
    int result = 0;
    int fact = 1;
    for (int i = 0; i < 9; i++) {
        result += d[9-i] * fact;
        fact *= 10;
    }
    return result;
}

void make_map() {
    matrix[min_mat] = 0;
    my_queue.push(min_mat);
    while (!my_queue.empty()) {
        int t = my_queue.front();
        my_queue.pop();
        for (int i = 0; i < 3; i++) {
            int row_t = _op(t, i, -1);
            if (!matrix.count(row_t)) {
                matrix[row_t] = matrix[t] + 1;
                my_queue.push(row_t);
            }
            int col_t = _op(t, -1, i);
            if (!matrix.count(col_t)) {
                matrix[col_t] = matrix[t] + 1;
                my_queue.push(col_t);
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    string standard_matrix = "123456789";
//    auto t1 = std::chrono::high_resolution_clock::now();
    make_map();
//    auto t2 = std::chrono::high_resolution_clock::now();
//    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    //printf("cost: %lld ms\n", duration);
    while (T--) {
        int s1, s2, s3;
        int t1, t2, t3;
        scanf("%d %d %d", &s1, &s2, &s3);
        scanf("%d %d %d", &t1, &t2, &t3);
        int s = s1 * 1000000 + s2 * 1000 + s3;
        int t = t1 * 1000000 + t2 * 1000 + t3;
        if (t != min_mat) {
            map<char, char> convert;
            string s_str = to_string(s);
            string t_str = to_string(t);
            string min_str = to_string(min_mat);
            for (int i = 0; i < s_str.length(); i++) {
                convert[s_str[i]] = min_str[i];
            }
            for (int i = 0; i < t_str.length(); i++) {
                t_str = t_str.replace(i, 1, 1, convert[t_str[i]]);
            }
            t = std::stoi(t_str);
        }
        if (matrix.count(t)) {
            printf("%d\n", matrix[t]);
        } else {
            printf("impossible\n");
        }
    }
}

/*
 * 本质是个打表，先用 BFS 搜索所有从标准三阶幻方
 *          1 2 3
 *          4 5 6
 *          7 8 9
 * 变化能得到的所有可能，共 181440 个。
 * 对于每一个输入，将初始状态直接映射成标准三阶幻方，然后根据这个映射关系将目标状态映射一下。
 * 然后查表即可。
 */

