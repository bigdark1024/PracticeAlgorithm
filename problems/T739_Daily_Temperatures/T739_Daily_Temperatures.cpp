#include "headers.h"

class Solution {
 public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= temperatures[i]) {
                stk.pop();
            }

            ans[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }
        return ans;
    }
};

TEST(T739_Daily_Temperatures, T739_Daily_Temperatures) {
    Solution s;
    vector<int> temperaturesVec = {3, 74, 75, 71, 69, 72, 76, 73};
    s.dailyTemperatures(temperaturesVec);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
