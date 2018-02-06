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
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

namespace {
using LL  = long long;
using uLL = unsigned long long;

#define EPS        1e-9
#define MAXL       20001
#define INF        1000000007
#define FEQ(a, b)  (a - b) < EPS

} // namespace

bool cmp(const string& l, const string& r) {
  return l.size() < r.size();
}

int main() {
  vector<string> group;
  string line;
  int cas = 1;
  while (cin >> line) {
    group.clear();
    while (line != "9") {
      group.push_back(line);
      cin >> line;
    }
    sort(group.begin(), group.end(), cmp);
    bool flag = true;
    for (vector<string>::iterator p = group.begin(); p != group.end(); ++p) {
      vector<string>::iterator q = p + 1;
      while (q != group.end()) {
        if (q->find(*p) == 0) {
          flag = false;
          break;
        }
        ++q;
      }
      if (!flag) {
        break;
      }
    }
    if (flag) {
      cout << "Set " << cas++ << " is immediately decodable" << endl;
    } else {
      cout << "Set " << cas++ << " is not immediately decodable" << endl;
    }
  }

  return 0;
}
