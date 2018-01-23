/**
 *  Author: recker
 */
#include <algorithm>
#include <assert.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <time.h>
#include <utility>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

namespace {
typedef long long LL;
typedef unsigned long long uLL;

#define EPS        1e-9
#define INF        1000000007
#define MAXINT     2147483647
#define MAXUINT    0xffffffff
#define FEQ(a, b)  (a - b) < EPS

#define MAXNUM     20001
} // namespace

int main() {
  int n, q;
  int cas = 1;
  while (cin >> n >> q) {
    if (!n && !q) break;
    cout << "CASE# " << cas++ << ":" << endl;
    vector<int> marble;
    marble.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> marble[i];
    }
    sort(marble.begin(), marble.end());
    for (int i = 0; i < q; ++i) {
      int x;
      cin >> x;
      auto it = find(marble.begin(), marble.end(), x);
      if (it != marble.end()) {
        cout << x << " found at " << distance(marble.begin(), it) + 1 << endl;
      } else {
        cout << x << " not found" << endl;
      }
    }
  }
  return 0;
}
