#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        std::sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) {
                return b[1] < a[1];
            }
            return a[0] < b[0];
        });

        // interval merge
        vector<vector<int>> merge {intervals[0]};
        for (size_t i = 0; i < intervals.size(); i++)
        {   
            vector<int> last_vec = merge.back();
            vector<int> vec = intervals[i];
        }
        return res;
    }
};

TEST(L1288, L1288) {
    vector<vector<int>> intervals {};
    intervals.push_back(vector<int>{1, 4});
    intervals.push_back(vector<int>{3, 6});
    intervals.push_back(vector<int>{2, 8});
    Solution s;
    s.removeCoveredIntervals(intervals);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
