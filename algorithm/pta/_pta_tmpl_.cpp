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

int a[300];
int main() {
    int T, n, k, b;
    int cnt = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &b);
        a[0] += b;
        for (int i = 1; i < n; i++) {
            scanf("%d", &b);
        }
        cnt = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[0]) {
                cnt++;
            }
        }
        (cnt < k) ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}