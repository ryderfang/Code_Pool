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
using LL  = long long;
using uLL = unsigned long long;


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
  uLL op1, op2;
  string line;
  while (getline(cin, line)) {
    bool is_add = true;
    op1 = 0;
    op2 = 0;
    size_t pos1;
    pos1 = line.find_first_of(' ');
    if (line[pos1+1] == '*') {
      is_add = false;
    }
    string num1, num2;
    num1 = line.substr(0, pos1);
    num2 = line.substr(pos1 + 3);
    cout << line << endl;
    
    while (num1[0] == '0') num1.erase(0, 1);
    while (num2[0] == '0') num2.erase(0, 1);
    if (num1.empty()) num1 = "0";
    if (num2.empty()) num2 = "0";

    bool is_too_big = false;
    if (num1.size() > 10) {
      cout << "first number too big" << endl;
      is_too_big = true;
    } else {
      sscanf(num1.c_str(), "%llu", &op1);
      if (op1 > MAXINT) {
        cout << "first number too big" << endl;
        is_too_big = true;
      }
    }

    if (num2.size() > 10) {
      cout << "second number too big" << endl;
      is_too_big = true;
    } else {
      sscanf(num2.c_str(), "%llu", &op2);
      if (op2 > MAXINT) {
        cout << "second number too big" << endl;
        is_too_big = true;
      }
    }

    if (num1 == "0" || num2 == "0") {
      continue;
    }

    if (is_too_big) {
      cout << "result too big" << endl;
    } else {
      uLL result;
      if (is_add) {
        result = op1 + op2;
      } else {
        result = op1 * op2;
      }
      if (result > MAXINT) {
        cout << "result too big" << endl;
      }
    }
  }

  return 0;
}
