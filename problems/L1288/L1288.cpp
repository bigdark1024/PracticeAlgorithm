#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) { // 起点相同，则按照重点降序排序
                return b[1] < a[1];
            }
            return a[0] < b[0]; // 按照起点升序排序
        });

        int res = 0;
        // interval merge
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); i++)
        {
            // 获取下一个区间数据
            vector<int> &vec = intervals[i];
            // 区间包含，覆盖场景
            if (vec[0] >= start && vec[1] <= end) {
                res++;
            }
            // 区间相交，合并区间
            if (end >= vec[0] && end <= vec[1]) {
                end = vec[1];
            }
            // 不相交
            if (end < vec[0]) {
                start = vec[0];
                end = vec[1];
            }
        }

        return intervals.size() - res;
    }
};

TEST(L1288, case1) {
    vector<vector<int>> intervals {};
    intervals.push_back(vector<int>{1, 4});
    intervals.push_back(vector<int>{3, 6});
    intervals.push_back(vector<int>{2, 8});
    Solution s;
    int ret = s.removeCoveredIntervals(intervals);
    ASSERT_EQ(2, ret);
}

TEST(L1288, case2) {
    vector<vector<int>> intervals {};
    intervals.push_back(vector<int>{1, 4});
    intervals.push_back(vector<int>{2, 3});
    Solution s;
    int ret = s.removeCoveredIntervals(intervals);
    ASSERT_EQ(1, ret);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
