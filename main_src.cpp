#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <Windows.h>
using namespace std;
#pragma warning(disable:4996)

// typedef __int64 int64_t;
// typedef unsigned __int64 uint64_t;

#define MAX_LEN          20001
#define INF              1000000007

void GetDirectStrings(const vector<string>& grid, map<int, vector<string> >& candidates) {
  assert();
  int height = grid.size();
  int width  = grid[0].size(); 
  for ()
}

int main() {
  vector<string> grid;
  int m, n;
  int k;
  scanf("%d%d", &m, &n);
  grid.reserve(m);
  string line;
  for (int i = 0; i < m; ++i) {
    cin >> line;
    grid.push_back(line);
  }

  map<int, vector<string> > candidates;
  GetDirectStrings(grid, candidates);

  return 0;
}
