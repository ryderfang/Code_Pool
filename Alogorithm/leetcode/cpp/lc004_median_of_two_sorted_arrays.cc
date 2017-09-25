#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            double mid_left, mid_right;
            int sz1 = nums1.size();
            int sz2 = nums2.size();
            int sz = sz1 + sz2;

            int p1 = 0, p2 = 0;
            int mid = (sz + 2) >> 1;
            while (p1 + p2 < mid) {
                mid_left = mid_right;
                if (p1 < sz1 && p2 < sz2) {
                    if (nums1[p1] < nums2[p2]) {
                        mid_right = nums1[p1];
                        ++p1;
                    } else {
                        mid_right = nums2[p2];
                        ++p2;
                    }
                } else if (p1 == sz1) {
                    mid_right = nums2[p2];
                    ++p2;
                } else if (p2 == sz2) {
                    mid_right = nums1[p1];
                    ++p1;
                }
            }
            if (sz & 1) return mid_right;
            else return (mid_left + mid_right) / 2;
        }
};

