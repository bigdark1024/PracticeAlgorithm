#include "headers.h"

/**
 * @brief 
 * https://leetcode-cn.com/problems/max-consecutive-ones-iii/
 */
class Solution {
 public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int zeroNum = 0;
        int n = nums.size();
        int ans = 0;
        while (right < n)
        {
            int digit = nums[right];
            if (digit == 0) {
                zeroNum++;
            }
            
            while (zeroNum > k)
            {
                if (nums[left] == 0) {
                    zeroNum--;
                }
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
 
        return ans;
    }
};

TEST(T1004_Max_Consecutive_Ones_III, testcase1) {
    int k = 2;
    Solution s;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int ret = s.longestOnes(nums, k);
    EXPECT_EQ(ret, 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
