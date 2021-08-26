#include "headers.h"

/**
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * */
class Solution {
 public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int len = s.size();
        int left = 0;
        int right = 0;
        unordered_set<char> queue;
        while (right < len) {
            char curr = s[right];
            while (queue.find(s[right]) != queue.end()) {
                queue.erase(s[left]);
                left++;
            }
            queue.insert(curr);
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

TEST(T3_Longest_Substring_Without_Repeating_Characters, leetcode_testcases) {
      Solution s;
    string input = "abcabcbb";
    int result = s.lengthOfLongestSubstring(input);
    EXPECT_EQ(result, 3);

    string s2 = " ";
    int result2 = s.lengthOfLongestSubstring(s2);
    EXPECT_EQ(result2, 1);

    string s3= "ynyo";
    int result3 = s.lengthOfLongestSubstring(s3);
    EXPECT_EQ(result3, 3);

    string s4 = "pwwkew";
    int result4 = s.lengthOfLongestSubstring(s4);
    EXPECT_EQ(result4, 3);
}

TEST(T3_Longest_Substring_Without_Repeating_Characters, unordered_set_testcases) {
    unordered_set<char> queue;
    string str = "pwwkew";
    queue.insert('p');
    queue.insert('w');
    queue.insert('w');
    queue.insert('k');
    queue.insert('e');
    queue.insert('w');

    unordered_set<string> sampleSet = {"geeks1", "for", "geeks2"};
    // use of find() function
    if (sampleSet.find("geeks1") != sampleSet.end()) {
        cout << "element found." << endl;
    }
    else {
        cout << "element not found" << endl;
    }

    if (queue.find('k') == queue.end()) {
        cout << "not found." << endl;
    } else {
        cout << "=====>>>  ..found..  <<=======" << endl;
        queue.erase('k');
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
