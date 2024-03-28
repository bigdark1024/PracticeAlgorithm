#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res {0};
        int i = 0;
        int j = 0;
        while (i < firstList.size() && j < secondList.size())
        {
            int a1 = firstList[i][0]; // left
            int a2 = firstList[i][1]; // right
            int b1 = secondList[j][0]; // left
            int b2 = secondList[j][1]; // right

            if (b2 >= a1 && b1 <= a2) {
                res.push_back({max(a1, b1), min(a2, b2)});
            }
            // 下面两种是不重合情况
            if (b2 < a2) {
                j++; // secondList滑动到下一个区间
            } else {
                i++; // firstList滑动到下一个区间
            }
        }
        return res;
    }
};

TEST(L986, L986) {
    Solution s;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
