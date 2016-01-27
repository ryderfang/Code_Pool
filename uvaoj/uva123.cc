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
#include <queue>
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

void Str2L(string& val) {
  transform(val.begin(), val.end(), val.begin(), ::tolower);
}

void Str2U(string& val) {
  transform(val.begin(), val.end(), val.begin(), ::toupper);
}

#define MAXNUM     20001
} // namespace

void GetWords(const string& line, vector<string>& words) {
  if (line.empty()) return;
  size_t st_pos, ed_pos;
  ed_pos = 0;
  while (ed_pos < line.size()) {
    st_pos = line.find_first_not_of(' ', ed_pos);
    if (st_pos == string::npos) break;
    ed_pos = line.find_first_of(' ', st_pos);
    if (ed_pos == string::npos) ed_pos = line.size();
    words.push_back(line.substr(st_pos, ed_pos - st_pos));
  }
}

int main() {
  set<string> ignores;
  string line;
  while (getline(cin, line)) {
    if (line == "::") break;
    ignores.insert(line);
  }
  vector<string> titles;
  set<string> keys;
  while (getline(cin, line)) {
    vector<string> temp;
    GetWords(line, temp);
    for (auto it : temp) {
      Str2L(it);
      keys.insert(it);
    }
    Str2L(line);
    titles.push_back(line);
  }

  for (auto keyword : keys) {
    if (ignores.count(keyword)) continue;
    for (auto tt : titles) {
      size_t pos = tt.find(keyword, 0);
      while (pos != string::npos) {
        if ((pos == 0 || tt[pos - 1] == ' ') && 
            (pos + keyword.size() == tt.size() || tt[pos + keyword.size()] == ' ')) {
          string tt_copy = tt;
          transform(tt_copy.begin() + pos, tt_copy.begin() + pos + keyword.size(), tt_copy.begin() + pos, ::toupper);
          cout << tt_copy << endl;
        }
        pos = tt.find(keyword, pos + keyword.size());
      }
    }
  }

  return 0;
}