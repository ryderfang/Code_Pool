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

class Solution {

private:
    int fb[48];

public:

    Solution() {
        fb[1] = 0;
        fb[2] = 1;
        for (int i = 3; i < 48; i++) {
            fb[i] = fb[i - 1] + fb[i - 2];
        }
    }
    /*
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        return fb[n];
    }
};

int main() {
    Solution sol;
    cout << sol.fibonacci(20);
    
    return 0;
}