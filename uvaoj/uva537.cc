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

using LL = long long;
using uLL = unsigned long long;

#define MAXL    20001
#define INF     1000000007
#define EPS     1e-9

#define FEQ(a, b)    (a - b) < EPS

enum Concept {
  kPower,
  kVoltage,
  kCurrent
};

double GetPrefix(char pre) {
  switch (pre) {
    case 'm':
      return 0.001;
    case 'k':
      return 1e3;
    case 'M':
      return 1e6;
    default:
      return 1.0;
  }
}

double GetData(const string& line, Concept type) {
  double prefix = 1;
  size_t pos1, pos2;
  switch (type) {
    case kPower: {    
      pos1 = line.find("P=");
      if (pos1 == string::npos) {
        return 0;
      }
      pos2 = line.find_first_of('W', pos1);
      prefix = GetPrefix(line[pos2-1]);
      break;
    }
    case kVoltage: {
      pos1 = line.find("U=");
      if (pos1 == string::npos) {
        return 0;
      }
      pos2 = line.find_first_of('V', pos1);
      prefix = GetPrefix(line[pos2-1]);
      break;
    }
    case kCurrent: {
      pos1 = line.find("I=");
      if (pos1 == string::npos) {
        return 0;
      }
      pos2 = line.find_first_of('A', pos1);
      prefix = GetPrefix(line[pos2-1]);
      break;
    }
  }
  string data;
  if (FEQ(prefix, 1.0)) {
    data = line.substr(pos1 + 2, pos2 - pos1 - 2);
  } else {
    data = line.substr(pos1 + 2, pos2 - pos1 - 3);
  }
  double float_data;
  sscanf(data.c_str(), "%lf", &float_data);
  return float_data * prefix;
}

int main() {
  int cas;
  scanf("%d", &cas);
  getchar();
  for (int k = 1; k <= cas; ++k) {
    double P, U, I;
    cout << "Problem #" << k << endl;
    string line;
    getline(cin, line);

    P = GetData(line, kPower);
    U = GetData(line, kVoltage);
    I = GetData(line, kCurrent);

    if (FEQ(P, 0)) {
      cout << "P=" << setprecision(2) << fixed << U * I << "W" << endl;
    } else if (FEQ(U, 0)) {
      cout << "U=" << setprecision(2) << fixed << P / I << "V" << endl;
    } else if (FEQ(I, 0)) {
      cout << "I=" << setprecision(2) << fixed << P / U << "A" << endl;
    }
    cout << endl;
  }

  return 0;
}
