/**
 * Copyright 
*/
#include "headers.h"

/**
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 */
class Solution {
 public:
  int minSubArrayLen(int target, const vector<int> &nums) {
      int n = nums.size();
      if (n == 0) {
        return 0;
      }

      int ret = INT_MAX;
      int left = 0;
      int right = 0;
      vector<int> preSum(n +  1, 0);
      int sum = 0;
      while (right < n) {
          sum += nums[right];
          while (sum >= target) {
            ret = min(ret, right - left + 1);
            sum -= nums[left];
            left++;
          }
          right++;
      }
    return ret == INT_MAX ? 0 : ret;
  }
};

TEST(T209_Minimum_Size_Subarray_Sum, T209_Minimum_Size_Subarray_Sum
) {
Solution s;
vector<int> nums = {2, 3, 1, 2, 4, 3};
int target = 7;
int expectLen = 2;
int result = s.minSubArrayLen(target, nums);
EXPECT_EQ(result, expectLen
);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
