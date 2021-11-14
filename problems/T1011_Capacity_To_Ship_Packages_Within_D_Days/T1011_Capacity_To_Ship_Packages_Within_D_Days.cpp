#include "headers.h"

class Solution {
public:
    int shipWithinDays(vector<int> &weights, int days) {
        int maxWeight = 0;
        int sumWeight = 0;
        for_each(weights.begin(), weights.end(), [&](int x) {
            maxWeight = std::max(maxWeight, x);
            sumWeight += x;
        });

        int left = maxWeight;
        int right = sumWeight;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tryLoad(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool tryLoad(vector<int> &weights, int volume, int days) {
        int dayCount = 0;
        for (int i = 0; i < weights.size();) {
            int cap = volume;
            while (i < weights.size()) {
                if (cap < weights[i]) {
                    break;
                } else {
                    cap -= weights[i];
                    i++;
                }
            }
            dayCount++;
        }

        return dayCount <= days;
    }
};

TEST(T1011_Capacity_To_Ship_Packages_Within_D_Days, testcase1) {
    Solution s;
    vector<int> weights{1, 2, 3, 1, 1};
    int day = 4;
    int ret = s.shipWithinDays(weights, day);
    EXPECT_EQ(ret, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
