class Solution {
 public:
  bool isHappy(int n) {
    map<int, bool> happy_map;
    happy_map.clear();
    int count = n;
    while (true) {
      int temp = 0;
      while (count > 0) {
        int digit = count % 10;
        temp += digit * digit;
        count /= 10;
      }
      count = temp;
      if (temp == 1) {
        return true;
      }
      if (happy_map.count(temp) == 0) {
        happy_map[temp] = true;
      }
      else {
        break;
      }
    }
    return false;
  }
};
