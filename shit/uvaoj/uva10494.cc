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

class BigInt {
 public:
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
    int item;
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

  BigInt(const std::vector<int>& rhs) {
    value_.clear();
    value_ = rhs;
  }

  // operator +
  BigInt operator+(const BigInt& rhs) const {
    size_t min_sz = std::min(value_.size(), rhs.value_.size());
    size_t max_sz = std::max(value_.size(), rhs.value_.size());
    BigInt _Ret;
    if (value_.size() > rhs.value_.size()) {
      _Ret.value_ = value_;
    } else {
      _Ret.value_ = rhs.value_;
    }
    _Ret.value_.resize(max_sz + 1, 0);
    int sum = 0, carry = 0;
    size_t i = 0;
    for (; i < min_sz; ++i) {
      sum = value_[i] + rhs.value_[i] + carry;
      _Ret.value_[i] = sum % kDiv;
      carry = sum / kDiv;
    }
    for (; i < max_sz + 1; ++i) {
      sum = _Ret.value_[i] + carry;
      _Ret.value_[i] = sum % kDiv;
      carry = sum / kDiv;
    }
    while (!_Ret.value_.empty() && !_Ret.value_.back()) _Ret.value_.erase(_Ret.value_.end() - 1);
    if (_Ret.value_.empty()) {
      _Ret = 0;
    }
    return _Ret;
  }

  // operator *
  BigInt operator*(const BigInt& rhs) const {
    BigInt _Ret = 0;
    std::vector<int> _Vec;
    for (size_t i = 0; i < value_.size(); ++i) {
      int product, carry = 0;
      _Vec.clear();
      for (size_t j = 0; j < rhs.value_.size(); ++j) {
        product = value_[i] * rhs.value_[j] + carry;
        _Vec.push_back(product % kDiv);
        carry = product / kDiv;
      }
      if (carry) _Vec.push_back(carry);
      for (size_t k = 0; k < i; ++k) {
        _Vec.insert(_Vec.begin(), 0);
      }
      BigInt _Temp(_Vec);
      _Ret = _Ret + _Temp;
    }
    return _Ret;
  }

  BigInt operator/(int divisor) const {
    std::vector<int> quot;
    LL dividend = 0;
    for (auto it = value_.rbegin(); it != value_.rend(); ++it) {
      dividend = dividend * kDiv + *it;
      if (dividend < divisor) {
        quot.push_back(0);
      } else {
        quot.push_back(dividend / divisor);
        dividend = dividend % divisor;
      }
    }
    std::reverse(quot.begin(), quot.end());
    while (quot.size() > 1 && quot.back() == 0) quot.pop_back();
    return BigInt(quot);
  }

  int operator%(int divisor) const {
    LL dividend = 0;
    for (auto it = value_.rbegin(); it != value_.rend(); ++it) {
      dividend = dividend * kDiv + *it;
      if (dividend >= divisor) {
        dividend = dividend % divisor;
      }
    }
    return dividend;
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
   static const int kDiv = 10000;

   std::vector<int> value_; 
};

int main() {
  string dividend, op;
  int divisor;
  while (cin >> dividend >> op >> divisor) {
    BigInt a = dividend;
    BigInt c;
    if (op == "/") {
      c = a / divisor;
      cout << c << endl;
    } else if (op == "%") {
      c = a % divisor;
      cout << c << endl;
    }
  }

  return 0;
}
