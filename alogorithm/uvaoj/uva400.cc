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

const char dashes[] = "------------------------------------------------------------";

int main() {
  int N;
  vector<string> files;
  while (cin >> N) {
    getchar();
    files.resize(N);
    size_t max_len = 0;
    for (int i = 0; i < N; ++i) {
      cin >> files[i];
      max_len = max(max_len, files[i].size());
    }
    cout << dashes << endl;
    size_t col = 62 / (max_len + 2);
    sort(files.begin(), files.end());
    size_t row = (N - 1) / col + 1;
    for (size_t i = 0; i < row; ++i) {
      for (size_t j = 0; j < col; ++j) {
        if (j < col - 1) {
          cout << left << setw(max_len + 2);
        } else {
          cout << left << setw(max_len);
        }
        size_t index = j * row + i;
        if (index < N) {
          cout << files[index];
        }
      }
      cout << endl;
    }
  }

  return 0;
}