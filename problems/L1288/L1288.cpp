#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        std::sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        return res;
    }
};

TEST(L1288, L1288) {
    Solution s;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
