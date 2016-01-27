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

void Merge(int left, int mid, int right, int& swaps, vector<int>& a) {
  int i = left;
  int j = mid + 1;
  vector<int> temp;
  while (i <= mid && j <= right) {
    if (a[i] > a[j]) {
      swaps += mid - i + 1;
      temp.push_back(a[j++]);
    } else {
      temp.push_back(a[i++]);
    }
  }
  while (i <= mid) temp.push_back(a[i++]);
  while (j <= right) temp.push_back(a[j++]);
  int k = left;
  for (auto it : temp) {
    a[k++] = it;
  }
}

void MergeSort(int left, int right, int& swaps, vector<int>& a) {
  if (left < right) {
    int mid = (left + right) >> 1;
    MergeSort(left, mid, swaps, a);
    MergeSort(mid + 1, right, swaps, a);
    Merge(left, mid, right, swaps, a);
  }
}

int main() {
  int N, L;
  cin >> N;
  vector<int> carriages;
  while (N--) {
    cin >> L;
    carriages.resize(L, 0);
    for (int i = 0; i < L; ++i) {
      cin >> carriages[i];
    }
    int swaps = 0;
    MergeSort(0, L - 1, swaps, carriages);
    cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
  }

  return 0;
}
