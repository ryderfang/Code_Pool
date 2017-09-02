#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;

class Solution {
private:
    int *temp;
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // size_type is an unsigned integral type
        int n = A.size();
        temp = new int[n];
        return mergeSort(A, 0, n - 1);
    }

    LL mergeSort(vector<int>& A, int l, int r) {
        LL ans = 0;
        if (l < r) {
            int m = (l + r) >> 1;
            ans += mergeSort(A, l, m);
            ans += mergeSort(A, m + 1, r);
            ans += merge(A, l, m, r);
        }
        return ans;
    }

    LL merge(vector<int>& A, int l, int m, int r) {
        int i = l, j = m + 1, k = l;
        LL ans = 0;
        while (i <= m && j <= r) {
            if (A[i] > A[j]) {
                temp[k++] = A[j++];
                ans += m + 1 - i;
            } else {
                temp[k++] = A[i++];
            }
        }
        while (i <= m) {
            temp[k++] = A[i++];
        }
        while (j <= r) {
            temp[k++] = A[j++];
        }
        for (i = l; i <= r; ++i) {
            A[i] = temp[i];
        }
        return ans;
    }
};

