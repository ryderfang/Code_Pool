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
#include <utility>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

namespace {
using LL  = long long;
using uLL = unsigned long long;

#define EPS        1e-9
#define MAXL       20001
#define INF        1000000007
#define FEQ(a, b)  (a - b) < EPS

} // namespace

class BigInt {
 public:
  typedef int _Myt;

  // init
  BigInt() {}

  BigInt(int rhs) {
    assert(rhs >= 0);
    if (rhs == 0) {
      value_.push_back(0);
      return;
    }
    while (rhs > 0) {
      value_.push_back(rhs % kDiv);
      rhs /= kDiv;
    }
  }

  BigInt(const std::string& rhs)  {
    std::string temp = rhs;
    size_t i = temp.size();
    _Myt item;
    while (i >= 4) {
      i -= 4;
      sscanf(temp.substr(i, 4).c_str(), "%d", &item);
      value_.push_back(item);
    }
    if (i) {
      sscanf(temp.substr(0, i).c_str(), "%d", &item);
      value_.push_back(item);    
    }
  }

  BigInt(const BigInt& rhs) {
    value_.clear();
    value_ = rhs.value_;
  }

  // operator +
  BigInt operator+(const BigInt& rhs) {
    size_t min_sz = std::min(value_.size(), rhs.value_.size());
    size_t max_sz = std::max(value_.size(), rhs.value_.size());
    BigInt ret;
    if (value_.size() > rhs.value_.size()) {
      ret.value_ = value_;
    } else {
      ret.value_ = rhs.value_;
    }
    ret.value_.resize(max_sz + 1, 0);
    _Myt sum = 0, carry = 0;
    size_t i = 0;
    for (; i < min_sz; ++i) {
      sum = value_[i] + rhs.value_[i] + carry;
      ret.value_[i] = sum % kDiv;
      carry = sum / kDiv;
    }
    for (; i < max_sz + 1; ++i) {
      sum = ret.value_[i] + carry;
      ret.value_[i] = sum % kDiv;
      carry = sum / kDiv;
    }
    if (!ret.value_[max_sz]) ret.value_.pop_back();
    return ret;
  }

  friend std::ostream& operator<<(std::ostream& out, BigInt& obj) {
    for (auto it = obj.value_.rbegin(); it != obj.value_.rend(); ++it) {
      if (it == obj.value_.rbegin()) {
        out << *it;
      } else {
        out << setfill('0') << setw(4) << *it;
      }
    }
    return out;
  }

 private:
   static const _Myt kDiv = 10000;

   std::vector<_Myt> value_; 
};

int main() {
  string line;
  BigInt ret = 0;
  while (cin >> line) {
    if (line == "0") {
      cout << ret << endl;
      break;
    }
    BigInt addend = line;
    ret = ret + addend;
  }

  return 0;
}
