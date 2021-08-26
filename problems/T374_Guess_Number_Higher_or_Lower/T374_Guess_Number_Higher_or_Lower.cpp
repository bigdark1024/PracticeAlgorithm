#include "headers.h"

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 * 
 * https://leetcode-cn.com/problems/guess-number-higher-or-lower/
 */
class Solution {
 public:
    int guessNumber(int n) {
        int left = 0;
        int right = n;
        // while (left < right) {
        //     int mid = (left + (right - left)/ 2) ;
        //     if (guess(mid) <= 0) {
        //         right = mid; // [left, mid]
        //         continue;
        //     } else if (guess(mid) == 1) {
        //         left = mid + 1; // [mid + 1, right]
        //         continue;
        //     }
        //     // break;  // 可加、可不加一位内在 while(left < right)限制了
        // }
        return left;
    }
};

TEST(T374_Guess_Number_Higher_or_Lower, T374_Guess_Number_Higher_or_Lower) {
    Solution s;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
