#include "headers.h"

/**
 * https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
 */
class Solution {
 public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        int currCost = 0;
        vector<int> cost(len, 0);
        for (int i = 0; i < len; i++) {
            cost[i] = abs(s[i] - t[i]);
        }

        while (right < len)
        {
            int curr = cost[right];
            // 
            while (currCost + curr > maxCost)
            {
                currCost -= cost[left++];
            }
            currCost += curr;
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

TEST(T1208_Get_Equal_Substrings_Within_Budget, T1208_Get_Equal_Substrings_Within_Budget) {
    Solution st;
    string s  = "abcd";
    string t  = "bcdf";
    int maxCost = 3;
    int ret1 = st.equalSubstring(s, t, maxCost);
    EXPECT_EQ(ret1, maxCost);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
