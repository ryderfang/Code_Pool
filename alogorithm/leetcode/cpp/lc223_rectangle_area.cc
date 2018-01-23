#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long ll_A = A, ll_B = B, ll_C = C, ll_D = D, ll_E = E, ll_F = F, ll_G = G, ll_H = H;
        long long crossX = (ll_C - ll_A) + (ll_G - ll_E) - (max(ll_C, ll_G) - min(ll_A, ll_E));
        long long crossY = (ll_D - ll_B) + (ll_H - ll_F) - (max(ll_D, ll_H) - min(ll_B, ll_F));
        crossX = crossX < 0 ? 0 : crossX;
        crossY = crossY < 0 ? 0 : crossY;
        long long res = (ll_C - ll_A) * (ll_D- ll_B) + (ll_G - ll_E) * (ll_H - ll_F) - crossX * crossY;
        return (int)res;
    }
};

int main() {
    Solution sol;
    cout << sol.computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1) << endl;
    return 0;
}
