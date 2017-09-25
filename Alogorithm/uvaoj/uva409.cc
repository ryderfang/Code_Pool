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



int main() {
  int cas = 1;
  int nk, ne;
  while (cin >> nk >> ne) {
    cout << "Excuse Set #" << cas++ << endl;

    getchar();
    vector<string> key;
    vector<string> excuse;
    string line;
    while (nk--) {
      getline(cin, line);
      key.push_back(line);
    }
    while (ne--) {
      getline(cin, line);
      excuse.push_back(line);
    }

    map<int, vector<string> > result_map;
    int worst = 0;
    for (auto str : excuse) {
      string lower_str = str;
      transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
      int count = 0;
      for (auto word : key) {
        size_t index = 0;
        size_t pos = lower_str.find(word, index);
        while (pos != string::npos) {
          index += pos + word.size();
          if ((pos == 0 || !isalpha(lower_str[pos-1])) &&
              (index == lower_str.size() || !isalpha(lower_str[index]))) {
            count++;
          }
          pos = lower_str.find(word, index);
        }
      }
      if (count > worst) worst = count;
      result_map[count].push_back(str);
    }

    for (auto str : result_map[worst]) {
      cout << str << endl;
    }

    cout << endl;
  }

  return 0;
}
