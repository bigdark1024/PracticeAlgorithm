#include "headers.h"

/**
 * @brief 
 * https://leetcode-cn.com/problems/longest-palindromic-substring/
 * 
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 */
class Solution {
 public:
     /**
      * @brief pan duan reverse str substring
      * 
      * @param words 
      * @return true 
      * @return false 
      */
     bool huiWen(string words) {
        if (words.size() == 0) {
            return false;
        }
        
        int len = words.size();
        int left = 0;
        int right = len - 1;
        bool ans = true;
        while (left < right)
        {
            if (words[left] != words[right]) {
                ans = false;
                break;
            }
            left++;
            right--;
        }
        return ans;
    }

    /**
     * @brief bao li pass some testcases.
     * 
     * @param s 
     * @return string 
     */
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int left = 0;
        int right = 0;
        string ans = "";
        int ansMaxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                string subStr = s.substr(i, j - i);
                int tmpLen = subStr.length();
                string revStr = subStr;
                std::reverse(revStr.begin(), revStr.end());
                // if (!huiWen(subStr)) {
                if (subStr != revStr) {
                    continue;
                }
                if (tmpLen >= ansMaxLen) {
                    ans = subStr;
                }
                ansMaxLen = max(ansMaxLen, tmpLen);
            }
        }
        
        return ans;
    }

 private:
    /**
     * @brief 
     * nothing
     */
};

TEST(T5_Longest_Palindromic_Substring, test_is_huiwen_true) {
    Solution s;
    string abcba = "abcba";
    EXPECT_EQ(s.huiWen(abcba), true);

    string a = "a";
    bool retA = s.huiWen(a);
    EXPECT_EQ(retA, true);
}

TEST(T5_Longest_Palindromic_Substring, test_is_huiwen_false) {
    Solution s;
    string abcbb = "abcbb";
    bool ret1 = s.huiWen(abcbb);
    EXPECT_EQ(ret1, false);

    string abdca = "abdca";
    bool ret2 = s.huiWen(abdca);
    EXPECT_EQ(ret2, false);
}

TEST(T5_Longest_Palindromic_Substring, test_longestPalindrome) {
    Solution s;
    string babad = "babad";
    string ret1 = s.longestPalindrome(babad);
    EXPECT_EQ(ret1, "aba");  // aba is also the right answer.
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
