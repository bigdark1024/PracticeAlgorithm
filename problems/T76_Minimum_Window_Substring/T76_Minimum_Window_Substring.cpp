#include "headers.h"

/**
 * @brief 
 * 76. 最小覆盖子串
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * https://leetcode-cn.com/problems/minimum-window-substring/
 */
class Solution {
 public:
    string minWindow(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        int left = 0;
        int right = 0;
        int count = 0;
        string ans = "";

        while(right < sLen) 
        {
            char curr = s[right];
            for (int i = 0; i <= tLen; i++) {
                string miniStr = s.substr(left, right - left + 1);

            }
        }
        return ans;
    }
};

TEST(T76_Minimum_Window_Substring, T76_Minimum_Window_Substring) {
    Solution s;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
