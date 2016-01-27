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

int main() {
  set<string> alphabet;
  string line;
  while (getline(cin, line)) {
    if (line.empty()) {
      continue;
    }
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    string word;
    for (auto ch : line) {
      if (isalpha(ch)) {
        word.push_back(ch);
      } else {
        if (!word.empty()) alphabet.insert(word);
        word.clear();
      }
    }
    if (!word.empty()) alphabet.insert(word);
  }

  for (auto iter : alphabet) {
    cout << iter << endl;
  }

  return 0;
}
