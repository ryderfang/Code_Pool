#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// 8! = 40320
int arr[40320][8];

int k[30];
int input[30][8];

int permutation(int n) {
    int t[8];
    for (int i = 0; i < n; i++) {
        t[i] = i + 1;
    }
    int count = 0;
    do {
        for (int i = 0; i < n; i++) {
            arr[count][i] = t[i];
        }
        count++;
    } while(next_permutation(t, t + n));
    return count;
}

int get_index(const vector<int> &t, int x) {
    int ret = -1;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == x) {
            ret = i;
            break;
        }
    }
    return ret;
}

bool check(vector<int> t, int n, int m) {
    for (int i = 0; i < m; i++) {
        int last_idx = get_index(t, input[i][0]);
        if (last_idx == -1) return false;
        for (int j = 1; j < k[i]; j++) {
            int idx = get_index(t, input[i][j]);
            if (idx == -1 || idx != last_idx + 1) {
                return false;
            } else {
                last_idx = idx;
            }
        }
    }
    return true;
}

//3 2
//1 3
//2 2 1

//8 3
//1 4
//3 7 5 1
//1 6

int main () {
    int n, m;
    scanf("%d %d", &n, &m);
    int count = permutation(n);
//    printf("count: %d\n", count);
//    for (int i = 0; i < count; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &k[i]);
        for (int j = 0; j < k[i]; j++) {
            scanf("%d", &input[i][j]);
        }
        //sort(input[i], input[i] + k[i]);
    }
    bool is_ok = false;
    int x = 0;
    for (; x < count; x++) {
        is_ok = check(vector<int>(arr[x], arr[x] + n), n, m);
        if (is_ok) {
            break;
        }
    }
    if (is_ok) {
        printf("%d", arr[x][0]);
        for (int i = 1; i < n; i++) {
            printf(" %d", arr[x][i]);
        }
        printf("\n");
    } else {
        printf("-1\n");
    }
}
