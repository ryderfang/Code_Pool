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

#define MAXNUM     20001
} // namespace

int main() {
  string line;
  map<string, string> words; 
  while (getline(cin, line)) {
    if (line == "#") break;
    size_t index = 0;
    size_t st_pos;
    size_t ed_pos;
    string word;
    while (index < line.size()) { 
      st_pos = line.find_first_not_of(' ', index);
      ed_pos = line.find_first_of(' ', st_pos);
      if (st_pos == string::npos) break;
      if (ed_pos == string::npos) ed_pos = line.size();
      word = line.substr(st_pos, ed_pos - st_pos);
      index = ed_pos;

      string another = word;
      transform(word.begin(), word.end(), another.begin(), ::tolower);
      sort(another.begin(), another.end());
      auto iter = words.find(another);
      if (iter == words.end()) {
        words.insert(make_pair(another, word));
      } else {
        words[another] = "";
      }
    }
  }

  vector<string> result;
  for (auto it : words) {
    if (!it.second.empty()) result.push_back(it.second);
  }
  sort(result.begin(), result.end());
  for (auto it : result) {
    cout << it << endl;
  }

  return 0;
}