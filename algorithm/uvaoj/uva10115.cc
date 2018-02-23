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

void _replace(const string& find, const string& replace, string& text) {
  size_t pos = text.find(find);
  while (pos != string::npos) {
    text.replace(pos, find.size(), replace);
    pos = text.find(find);
  }
}

int main() {
  int num;
  vector<pair<string, string> > rules;
  while (cin >> num) {
    rules.clear();
    getchar();
    if (num == 0) break;
    string find, replace;
    while (num--) {
      getline(cin, find);
      getline(cin, replace);
      rules.push_back(make_pair(find, replace));
    }
    string text;
    getline(cin, text);
    for (auto i : rules) {
      _replace(i.first, i.second, text);
    }

    cout << text << endl;
  }

  return 0;
}
