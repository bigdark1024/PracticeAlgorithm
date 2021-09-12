#include "headers.h"

class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> arr(len1 + len2);
    for (int i = len1 - 1; i >= 0; i--) {
      int n1 = num1.at(i) - '0';
      for (int j = len2 - 1; j >= 0; j--) {
        int n2 = num2.at(j) - '0';
        int sum = arr[i + j + 1] + n1 * n2;
        arr[i + j + 1] = sum % 10;
        arr[i + j] = sum / 10;
      }
    }

    string res = "";
    for (int i = 0; i < arr.size(); ++i) {
      if (i == 0 && arr.at(i) == 0) {
        continue;
      }
      res += arr.at(i);
    }

    return res;
  }
};

TEST(T43_Multiply_Strings, testcase1) {
  Solution s;
  s.multiply("2", "3");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
