#include "headers.h"

static const int INDEX0 = 0;
static const int INDEX1 = 1;
static const int INDEX2 = 2;
static const int INDEX3 = 3;

class Solution {
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        // ----------
        int x1 = rec1[INDEX0];
        int y1 = rec1[INDEX1];
        int x2 = rec1[INDEX2];
        int y2 = rec1[INDEX3];
        // -----------
        int x3 = rec2[INDEX0];
        int y3 = rec2[INDEX1];
        int x4 = rec2[INDEX2];
        int y4 = rec2[INDEX3];

        if (x2 <= x3 || x4 <= x1 || y1 >= y4 || y3 >= y2) {
            return false;
        }
        return true;
    }
};

TEST(isRectangleOverlap, testcase1) {
    Solution s;
    std::vector<int> rec1 = {0, 0, 2, 2};
    std::vector<int> rec2 = {1, 1, 3, 3};
    bool ret = s.isRectangleOverlap(rec1, rec2);
    EXPECT_EQ(ret, true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
