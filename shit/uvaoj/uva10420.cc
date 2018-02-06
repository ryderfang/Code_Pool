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
  string line;
  cin >> n;
  map<string, set<string> > women;
  while (true) {
    getline(cin, line);
    if (line.empty()) continue;
    size_t pos = line.find_first_of(' ');
    string country = line.substr(0, pos);
    string name = line.substr(pos + 1);
    women[country].insert(name);
    if (--n == 0) break;
  }
  for (auto it : women) {
    cout << it.first << " " << it.second.size() << endl;
  }
  return 0;
}
