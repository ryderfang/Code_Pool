#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
   vector<vector<int> > threeSum(vector<int>& nums);
};

vector<vector<int> > Solution::threeSum(vector<int>& nums) {
  vector<vector<int> > ret;
  int len = nums.size();
  if (len < 3) {
    return ret;
  }
  vector<int> temp;
  map<int, int> nums_count;
  nums_count.clear();
  for (int i = 0; i < len; ++i) {
    if (!nums_count.count(nums[i])) {
      nums_count[nums[i]] = 1;
    } else {
      nums_count[nums[i]]++;
    }
  }

  // special for 0
  if (nums_count.count(0)) {
    for (map<int, int>::iterator iter = nums_count.begin(); (iter->first < 0) && (iter != nums_count.end()); ++iter) {
      if (nums_count.count(-iter->first)) {
        temp.clear();
        temp.push_back(iter->first);
        temp.push_back(0);
        temp.push_back(-iter->first);
        ret.push_back(temp);
      }
    }

    if (nums_count[0] >= 3) {
      ret.push_back(vector<int>({0, 0, 0}));
    }

    nums_count.erase(nums_count.find(0));
  }

  if (nums_count.size() > 1) {
    map<int, int>::iterator iter_front;
    for (map<int, int>::iterator iter = nums_count.begin(); (iter->first < 0) && (iter != nums_count.end()); ++iter) {
      for (iter_front = iter, ++iter_front; iter_front != nums_count.end(); ++iter_front) {
        if (nums_count.count(-iter->first - iter_front->first)) {
          if (((-iter->first - iter_front->first) == iter_front->first &&
               iter_front->second > 1) ||
              ((-iter->first - iter_front->first) > iter_front->first)) {
            temp.clear();
            temp.push_back(iter->first);
            temp.push_back(iter_front->first);
            temp.push_back(-iter->first - iter_front->first);
            ret.push_back(temp);
          }
        }
      }
      

      if (iter->second >= 2) {
        if (nums_count.count(-2 * iter->first)) {
          temp.clear();
          temp.push_back(iter->first);
          temp.push_back(iter->first);
          temp.push_back(-2 * iter->first);
          ret.push_back(temp);
        }
      }
    }
  }

  return ret;
}

int main() {
    Solution sol;
    return 0;
}
