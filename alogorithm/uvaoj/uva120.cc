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
  while (getline(cin, line)) {
    stringstream ss;
    ss << line;
    vector<int> stack;
    stack.resize(40, 0);
    int i = 0;
    while (ss >> stack[i++]);
    stack.erase(find(stack.begin(), stack.end(), 0), stack.end());
    int sz = stack.size();
    vector<int> seq;
    for (int bottom = sz - 1; bottom > 0; ) {
      int max_pos = 0;
      for (int j = 1; j <= bottom; ++j) {
        if (stack[j] > stack[max_pos]) max_pos = j;
      }
      if (max_pos == bottom) {
        --bottom;
      } else if (max_pos == 0) {
        seq.push_back(sz - bottom);
        reverse(stack.begin(), stack.begin() + bottom + 1);
        --bottom;
      } else {
        seq.push_back(sz - max_pos);
        reverse(stack.begin(), stack.begin() + max_pos + 1);
      }
    }
    cout << line << endl;
    seq.push_back(0);
    for (size_t j = 0; j < seq.size(); ++j) {
      if (j) cout << " ";
      cout << seq[j];
    }
    cout << endl;
  }

  return 0;
}