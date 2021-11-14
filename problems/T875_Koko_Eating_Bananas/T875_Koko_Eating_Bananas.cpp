#include "headers.h"

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int left = 1;
//        int right = pow(10, 9);
//        for (int i = 0; i < piles[i]; ++i) {
//            right = max(right, piles[i]); // memory leak
//        }
        int tmp = 0;
        for_each(piles.begin(), piles.end(), [&](int x) {
            tmp = max(tmp, x);
        });

        int right = tmp;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tryEatHours(piles, mid) <= h) {
                right = mid;
            } else if (tryEatHours(piles, mid) > h) {
                left = mid + 1;
            }
        }
        return left;
    }

    int tryEatHours(vector<int> &piles, int speed) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += piles[i] / speed;
            if (piles[i] % speed > 0) {
                hours++;
            }
        }
        return hours;
    }
};

TEST(T875_Koko_Eating_Bananas, testcase1) {
    Solution s;
    vector<int> piles{3, 6, 7, 11};
    int h = 8;
    int speed = s.minEatingSpeed(piles, h);
    EXPECT_EQ(speed, 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
