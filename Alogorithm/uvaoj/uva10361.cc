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
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

using LL = long long;
using uLL = unsigned long long;

#define MAX_LEN          20001
#define INF              1000000007

int main() {
  int cas;
  scanf("%d", &cas);
  getchar();
  while (cas--) {
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    string c1, c2;
    c1.reserve(line1.size());
    for (auto ch : line1) {
      if (ch != '<' && ch != '>') {
        c1.push_back(ch);
      }
    }
    cout << c1 << endl;

    c2 = line2;
    string s2, s3, s4, s5;
    size_t pos1 = line1.find_first_of('<');
    size_t pos2 = line1.find_first_of('>');
    size_t pos3 = line1.find_last_of('<');
    size_t pos4 = line1.find_last_of('>');

    s2 = line1.substr(pos1 + 1, pos2 - pos1 - 1);
    s3 = line1.substr(pos2 + 1, pos3 - pos2 - 1);
    s4 = line1.substr(pos3 + 1, pos4 - pos3 - 1);
    s5 = line1.substr(pos4 + 1);

    pos1 = c2.find("...");
    c2.replace(pos1, 3, s4 + s3 + s2 + s5);
    cout << c2 << endl;
  }

  return 0;
}
