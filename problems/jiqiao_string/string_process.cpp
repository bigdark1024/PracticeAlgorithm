#include <iostream>
#include <string>
#include <gtest/gtest.h>

/* 字符串插入 */
TEST(jiqiao_str, t1)
{
    std::string s = "ABC";
    s.insert(2, "77");
    std::cout << "insert：" << s << std::endl;
}

/* 字符串删除部分字符 */
TEST(jiqiao_str, t2)
{
    std::string s = "ABCDFG";
    s.erase(2, 2);
    std::cout << "erase：" << s << std::endl;
}

/* 字符串查找 */
TEST(jiqiao_str, t3)
{
    std::string s = "CDEFGAB";
    std::cout << "find：" << s.find("AB") << std::endl;  // find：5

    if (s.find("ZZ") == s.npos) {
        std::cout << "not found" << std::endl;  // not found
    }
}

/* 字符串替换 */
TEST(jiqiao_str, t4)
{
    std::string s = "ABCDE";
    // 将起始位置为1，数量为3个字符的位置，使用6677替换
    std::cout << "replace：" << s.replace(1, 3, "6677") << std::endl;
}

/* 字符串反转 */
TEST(jiqiao_str, t5)
{
    std::string s = "ABCDE";
    std::reverse(s.begin(), s.end());
    std::cout << "reverse：" << s << std::endl;
}

/* 字符串截取子串 */
TEST(jiqiao_str, t6)
{
    std::string s = "134567";
    std::string str1 = s.substr(0, 1);
    std::cout << str1 << std::endl;

    std::string str2 = s.substr(0, 2);
    std::cout << str2 << std::endl;

    std::string str3 = s.substr(0, s.length());
    std::cout << str3 << std::endl;

    int val3 = stoi(str3, nullptr, 10);
    std::cout << val3 << std::endl;

    int val3_2 = atoi(str3.c_str());
    std::cout << val3_2 << std::endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
