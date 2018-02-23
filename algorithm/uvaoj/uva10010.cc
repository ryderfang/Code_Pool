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

void GetDirectStrings(const vector<string>& grid, map<int, vector<string> >& candidates) {
  int height = grid.size();
  int width  = grid[0].size(); 
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      int x = i * width + j;
      string temp;
      temp.reserve(height + width);
      int k, t;
      // 左
      k = i;
      t = j;
      while (t >= 0) {
        temp.push_back(grid[k][t]);
        t--;
      }
      temp.push_back('\0');
      candidates[x].push_back(temp);

      // 左上
      temp.clear();
      k = i;
      t = j;
      while (k >= 0 && t >= 0) {
        temp.push_back(grid[k][t]);
        k--;
        t--;
      }
      temp.push_back('\0');
      candidates[x].push_back(temp);

      // 上
      temp.clear();
      k = i;
      t = j;
      while (k >= 0) {
        temp.push_back(grid[k][t]);
        k--;
      }
      temp.push_back('\0');
      candidates[x].push_back(temp);

      // 右上
      temp.clear();
      k = i;
      t = j;
      while (k >= 0 && t < width) {
        temp.push_back(grid[k][t]);
        k--;
        t++;
      }
      temp.push_back('\0');
      candidates[x].push_back(temp);

      // 右
      temp.clear();
      k = i;
      t = j;
      while (t < width) {
        temp.push_back(grid[k][t]);
        t++;
      }
      temp.push_back('\0');
      candidates[x].push_back(temp);

      // 右下
      temp.clear();
      k = i;
      t = j;
      while (k < height && t < width) {
        temp.push_back(grid[k][t]);
        k++;
        t++;
      }
      temp.push_back('\0');
      candidates[x].push_back(temp);

      // 下
      temp.clear();
      k = i;
      t = j;
      while (k < height) {
        temp.push_back(grid[k][t]);
        k++;
      }
      temp.push_back('\0');
      candidates[x].push_back(temp);

      // 左下
      temp.clear();
      k = i;
      t = j;
      while (k < height && t >= 0) {
        temp.push_back(grid[k][t]);
        k++;
        t--;
      }
      temp.push_back('\0');
      candidates[x].push_back(temp);
    }
  }
}

int main() {
  vector<string> grid;
  int cas;
  int m, n;
  int k;
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d%d", &m, &n);
    grid.reserve(m);
    grid.clear();
    string line;
    for (int i = 0; i < m; ++i) {
      cin >> line;
      transform(line.begin(), line.end(), line.begin(), ::tolower);
      grid.push_back(line);
    }

    map<int, vector<string> > candidates;
    candidates.clear();
    GetDirectStrings(grid, candidates);

    scanf("%d", &k);
    int retx, rety;
    while (k--) {
      cin >> line;
      transform(line.begin(), line.end(), line.begin(), ::tolower);
      retx = 1, rety = 1;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          int x = i * n + j;
          for (auto str : candidates[x]) {
            if (str.find(line) == 0) {
              retx = i + 1;
              rety = j + 1;
              goto loop;
            }
          }
        }
      }

    loop:
      cout << retx << " " << rety << endl;
    }

    if (cas) cout << endl;
  }
  
  return 0;
}
