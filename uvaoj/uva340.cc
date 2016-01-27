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
  int n;
  vector<int> secret_vec;
  map<int, int> secret_map;
  int cas = 1;
  while (cin >> n, n != 0) {
    secret_vec.clear();
    secret_vec.resize(n, 0);
    secret_map.clear();
    for (int i = 0; i < n; ++i) {
      cin >> secret_vec[i];
      secret_map[secret_vec[i]]++;
    }
    cout << "Game " << cas++ << ":\n";
    do {
      map<int, int> guess;
      map<int, int> secret_copy = secret_map;
      int strong = 0, weak = 0;
      for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (secret_vec[i] == num) {
          ++strong;
          secret_copy[num]--;
        } else {
          guess[num]++;
        }
      }

      if (guess.count(0)) break;

      for (auto it : guess) {
        weak += std::min(secret_copy[it.first], guess[it.first]);
      }


      cout << "    (" << strong << "," << weak << ")\n";
    } while (true);
  }

  return 0;
}
