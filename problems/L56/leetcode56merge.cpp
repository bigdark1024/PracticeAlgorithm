#include "headers.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        // 排序：按照start升序
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });

        // 将第一个区间加入res
        res.push_back(intervals[0]);

        // 遍历所有区间，并与前一个区间的起始和终点进行比较
        for (int i = 1; i < intervals.size(); i++) {
            auto& curr = intervals[i];
            // res 中最后一个元素的引用
            auto& last = res.back();
            if (curr[0] <= last[1]) { // 后一个区间的start < 前区间的end, 说明两区间存在交集
                last[1] = max(last[1], curr[1]); // 新区间终点取二者最大值，起点是前一个区间的起点不变
            } else {
                // 如果没有交集，则处理下一个待合并区间
                res.push_back(curr);
            }
        }
        return res;
    }
};

TEST(leetcode56merge, merge) {
    Solution s;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
