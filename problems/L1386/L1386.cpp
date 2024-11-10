#include <iostream>
#include <algorithm>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<vector<bool>> status;
        std::fill(status.begin(), status.end(), false);


        return 0;
    }
};

TEST(L1386, case1) {
    int n = 3;
    vector<vector<int>> reservedSeats;
    reservedSeats.push_back(vector<int> {1,2});
    reservedSeats.push_back(vector<int> {1,3});
    reservedSeats.push_back(vector<int> {1,8});
    reservedSeats.push_back(vector<int> {2,6});
    reservedSeats.push_back(vector<int> {3,1});
    reservedSeats.push_back(vector<int> {3,10});

    Solution solution;
    int ret = solution.maxNumberOfFamilies(n, reservedSeats);
    ASSERT_EQ(ret, 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
