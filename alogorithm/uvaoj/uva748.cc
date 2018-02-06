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

  BigInt(const std::vector<_Myt>& rhs) {
    value_.clear();
    value_ = rhs;
  }

  // operator +
  BigInt operator+(const BigInt& rhs) {
    size_t min_sz = std::min(value_.size(), rhs.value_.size());
    size_t max_sz = std::max(value_.size(), rhs.value_.size());
    BigInt _Ret;
    if (value_.size() > rhs.value_.size()) {
      _Ret.value_ = value_;
    } else {
      _Ret.value_ = rhs.value_;
    }
    _Ret.value_.resize(max_sz + 1, 0);
    _Myt sum = 0, carry = 0;
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
  BigInt operator*(const BigInt& rhs) {
    BigInt _Ret = 0;
    std::vector<_Myt> _Vec;
    for (size_t i = 0; i < value_.size(); ++i) {
      _Myt product, carry = 0;
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
  string R;
  int n;
  while (cin >> R >> n) {
    size_t dot_pos = R.find(".");
    string int_R = R;
    size_t mov = 5 - dot_pos;
    mov *= n;
    int_R.erase(dot_pos, 1);
    BigInt temp_R = int_R;
    BigInt result = temp_R;
    for (int i = 0; i < n - 1; ++i) {
      result = result * temp_R;
    }
    ostringstream os;
    os << result;
    string temp = os.str();
    if (mov > temp.size()) {
      temp.insert(0, mov - temp.size(), '0');
      temp.insert(0, ".");
    } else {
      temp.insert(temp.size() - mov, ".");
    }
    while (temp[temp.size() - 1] == '0') {
      temp.erase(temp.size() - 1);
    }
    if (temp[temp.size() - 1] == '.') {
      temp.erase(temp.size() - 1);
    }
    cout << temp << endl;
  }

  return 0;
}
