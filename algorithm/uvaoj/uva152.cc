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

struct PT {
  int x, y, z;

  int distance(const PT& rhs) {
    for (int i = 1; i < 11; ++i) {
      if ((rhs.x-x)*(rhs.x-x) + (rhs.y-y)*(rhs.y-y) + (rhs.z-z)*(rhs.z-z) < i * i) {
        return i - 1;
      }
    }
    return 10;
  }
};

int main() {
  vector<PT> trees;
  vector<set<int> > dist;
  PT point;
  while (cin >> point.x >> point.y >> point.z) {
    if (!point.x && !point.y && !point.z) break;

    trees.push_back(point);
  }
  int n = trees.size();
  dist.resize(n);
  for (int i = 0; i < n; ++i) {
    PT p1 = trees[i];
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        PT p2 = trees[j];
        dist[i].insert(p1.distance(p2));
      }
    }
  }
  vector<int> hist;
  hist.resize(11);
  for (auto it : dist) {
    hist[*it.begin()]++;
  }
  for (int i = 0; i < 10; ++i) {
    cout << setw(4) << hist[i];
  }
  cout << endl;

  return 0;
}
