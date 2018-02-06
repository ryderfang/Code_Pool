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
  map<char, int> sb;
  sb['A'] = '2'; sb['B'] = '2'; sb['C'] = '2';
  sb['D'] = '3'; sb['E'] = '3'; sb['F'] = '3';
  sb['G'] = '4'; sb['H'] = '4'; sb['I'] = '4';
  sb['J'] = '5'; sb['K'] = '5'; sb['L'] = '5';
  sb['M'] = '6'; sb['N'] = '6'; sb['O'] = '6';
  sb['P'] = '7'; sb['R'] = '7'; sb['S'] = '7';
  sb['T'] = '8'; sb['U'] = '8'; sb['V'] = '8';
  sb['W'] = '9'; sb['X'] = '9'; sb['Y'] = '9';

  int T;
  cin >> T;
  while (T--) {
    int N;
    map<string, int> tel_map;
    cin >> N;
    getchar();
    string line;
    for (int i = 0; i < N; ++i) {
      getline(cin, line);
      string tel_num;
      tel_num.resize(7, '-');
      size_t k = 0;
      for (auto ch : line) {
        if (::isupper(ch)) {
          tel_num[k++] = sb[ch];
        } else if (::isdigit(ch)) {
          tel_num[k++] = ch;
        }
      }
      tel_num.insert(3, "-");
      tel_map[tel_num]++;
    }

    bool has_dup = false;
    for (auto tel : tel_map) {
      if (tel.second > 1) {
        has_dup = true;
        cout << tel.first << " " << tel.second << endl;
      }
    }
    if (!has_dup)
      cout << "No duplicates." << endl;

    if (T) cout << endl;
  }

  return 0;
}