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

using LL  = long long;
using uLL = unsigned long long;

#define EPS        1e-9
#define MAXL       20001
#define INF        1000000007
#define FEQ(a, b)  (a - b) < EPS

const char kTapeEnd[] = "___________";

int main() {
  string line;
  getline(cin, line);
  string decoded_msg;
  while (getline(cin, line)) {
    if (line == kTapeEnd) {
      break;
    }
    string asci;
    asci.resize(10);
    size_t j = 0;
    for (size_t i = 1; i < 10; ++i) {
      if (line[i] == ' ') {
        asci[j++] = '0';
      } else if (line[i] == 'o') {
        asci[j++] = '1';
      }
    }
    char ch;
    ch = strtol(asci.c_str(), nullptr, 2);
    decoded_msg.push_back(ch);
  }

  cout << decoded_msg;
  return 0;
}
