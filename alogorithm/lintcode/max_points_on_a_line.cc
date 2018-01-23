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

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

typedef pair<int, int> IntPair;
typedef map<IntPair, int>::iterator mIter;

struct Line {
    IntPair a;
    IntPair b;
    Line(IntPair _a, IntPair _b) : a(_a), b(_b) {}
};

class Solution {
public:
    IntPair pointPair(const Point& p) {
        return make_pair(p.x, p.y);
    }

    bool isOnLine(const IntPair& p, const Line& ln) {
        if ((p.first - ln.b.first) *(p.second - ln.a.second) == (p.first - ln.a.first) * (p.second - ln.b.second)) {
            return true;
        }
        return false;
    }

    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        size_t sz = points.size();
        if (sz < 3) {
            return sz;
        }
        int result = 0;
        map<IntPair, int> pmp;
        pmp.clear();
        for (int i = 0; i < sz; i++) {
            pmp[pointPair(points[i])]++;
        }
        mIter end = pmp.end();
        for (mIter i = pmp.begin(); i != end; i++) {
            for (mIter j = i; j != end;) {
                ++j;
                if (j == end) {
                    break;
                }
                Line ln(i->first, j->first);
                int temp = i->second + j->second;
                for (mIter k = j; k != end;) {
                    ++k;
                    if (k == end) {
                        break;
                    }
                    if (isOnLine(k->first, ln)) {
                        temp += k->second;
                    }
                }
                result = max(result, temp);
            }
        }
        if (pmp.size() == 1) {
            result = pmp.begin()->second;
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}
