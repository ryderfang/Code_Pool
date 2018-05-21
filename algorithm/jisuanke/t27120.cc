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

// 4.445
// 4.395
// 4.0485
int main () {
    int T;
    long long x;
    char y[1024];
    scanf("%d", &T);
    while (T--) {
        scanf("%lld.%s", &x, y);
        //printf("%lld, %s\n", x, y);
        int carry = 0;
        for (int i = strlen(y) - 1; i >= 0; i--) {
            //printf("%c\n", y[i]);
            if (y[i] - '0' + carry >= 5) {
                carry = 1;
            } else {
                carry = 0;
            }
        }
        printf("%lld\n", x + carry);
    }
}
