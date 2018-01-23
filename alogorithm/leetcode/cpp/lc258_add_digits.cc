class Solution {
public:
  int addDigits(int num) {
    if (num == 0) return 0;
    int ret = num % 9;
    if (ret) return ret;
    return 9;
  }
};
