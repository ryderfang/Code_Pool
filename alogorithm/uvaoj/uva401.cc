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

map<char, char> reverse_map;

bool is_zero(char ch) {
  return (ch == 'O' || ch == '0');
}

bool is_equal(char l, char r) {
  if (l == r ||
      (is_zero(l) && is_zero(r))) {
    return true;
  }
  return false;
}

bool is_palind(const string& str) {
  bool ret  = true;
  string rev;
  rev.resize(str.size());
  rev.assign(str.rbegin(), str.rend());
  for (size_t i = 0; i < str.size() / 2; ++i) {
    if (!is_equal(str[i], rev[i])) {
      ret = false;
      break;
    }
  }
  return ret;
}

bool is_mirror(const string& str) {
  string mirr;
  mirr.resize(str.size());
  for (size_t i = 0; i < str.size(); ++i) {
    if (reverse_map.count(str[i])) {
      mirr[i] = reverse_map[str[i]];
    } else {
      return false;
    }
  }
  // 字符串反转
  reverse(mirr.begin(), mirr.end());
  bool ret = true;
  for (size_t i = 0; i < str.size(); ++i) {
    if (!is_equal(str[i], mirr[i])) {
      ret = false;
      break;
    } 
  }
  return ret;
}

int main() {
  string line;
  {
    reverse_map['A'] = 'A';
    reverse_map['E'] = '3';
    reverse_map['H'] = 'H';
    reverse_map['I'] = 'I';
    reverse_map['J'] = 'L';
    reverse_map['L'] = 'J';
    reverse_map['M'] = 'M';
    reverse_map['O'] = 'O';
    reverse_map['S'] = '2';
    reverse_map['T'] = 'T';
    reverse_map['U'] = 'U';
    reverse_map['V'] = 'V';
    reverse_map['W'] = 'W';
    reverse_map['X'] = 'X';
    reverse_map['Y'] = 'Y';
    reverse_map['Z'] = '5';
    reverse_map['1'] = '1';
    reverse_map['2'] = 'S';
    reverse_map['3'] = 'E';
    reverse_map['5'] = 'Z';
    reverse_map['8'] = '8';
  }
  while (cin >> line) {
    bool is_p = is_palind(line);
    bool is_m = is_mirror(line);
    cout << line << " -- ";
    if (!is_p && !is_m) {
      cout << "is not a palindrome.\n" << endl;
    } else if (is_p && !is_m) {
      cout << "is a regular palindrome.\n" << endl;
    } else if (!is_p && is_m) {
      cout << "is a mirrored string.\n" << endl;
    } else {
      cout << "is a mirrored palindrome.\n" << endl;
    }
  }
  
  return 0;
}
