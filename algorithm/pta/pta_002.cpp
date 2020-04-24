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
const LL MAXN = 100001;

map<string, int> matrix;
vector<string> record;
LL counter = 0;
string _op(const string& str, int row, int col) {
    char cstr[str.size() + 1];
    strcpy(cstr, str.c_str());
    if (row >= 0 && row < 3) {
        char c3 = cstr[row * 3 + 2];
        cstr[row * 3 + 2] = cstr[row * 3 + 1];
        cstr[row * 3 + 1] = cstr[row * 3];
        cstr[row * 3] = c3;
    } else if (col >= 0 && col < 3) {
        char c3 = cstr[col + 6];
        cstr[col + 6] = cstr[col + 3];
        cstr[col + 3] = cstr[col];
        cstr[col] = c3;
    }
    counter++;
    return string(cstr);
}

// 超时了，要改用 bfs
void make_map() {
    string init = "123456789";
    matrix[init] = 0;
    record.push_back(init);
    int count = 0;
    const int max_count = 181440;
    bool has_new = true;
    while (count < max_count) {
        has_new = false;
        string current = record[count];
        for (int i = 0; i < 3; i++) {
            string row_res = _op(current, i, -1);
            if (matrix.count(row_res) == 0) {
                matrix[row_res] = matrix[current] + 1;
                record.push_back(row_res);
                has_new = true;
            } else {
                matrix[row_res] = min(matrix[current] + 1, matrix[row_res]);
            }

            string col_res = _op(current, -1, i);
            if (matrix.count(col_res) == 0) {
                matrix[col_res] = matrix[current] + 1;
                record.push_back(col_res);
                has_new = true;
            } else {
                matrix[col_res] = min(matrix[current] + 1, matrix[col_res]);
            }
        }
        count++;
    }
    printf("\n%d %d!!\n", record.size(), matrix.size());
    printf("counter: %lld\n", counter);
}

int main() {
    int T;
    scanf("%d", &T);
    string standard_matrix = "123456789";
    auto t1 = std::chrono::high_resolution_clock::now();
    make_map();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
    printf("cost: %lld s\n", duration);
    while (T--) {
        string s1, s2, s3;
        string t1, t2, t3;
        getchar();
        cin >> s1 >> s2 >> s3;
        cin >> t1 >> t2 >> t3;
        string s = s1 + s2 + s3;
        string t = t1 + t2 + t3;
        string target = t;
        if (s != standard_matrix) {
            map<char, char> convert;
            for (int i = 0; i < s.length(); i++) {
                convert[s[i]] = standard_matrix[i];
            }
            for (int i = 0; i < t.length(); i++) {
                target = target.replace(i, 1, 1, convert[t[i]]);
            }
        }
        if (matrix.count(target)) {
            printf("%d\n", matrix[target]);
        } else {
            printf("impossible\n");
        }
    }
}

