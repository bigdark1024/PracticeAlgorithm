#include <iostream>
#include <cctype>
#include <string>
#include <gtest/gtest.h>

std::string getDigit(std::string &s, int &cur)
{
    std::string res = "";
    for (int i = 0; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            res += s[i];
        }
    }
    return res;
}

TEST(jiqiao_char, t1)
{
    std::string s1 = "123s567";
    std::string num_filter_str = "";
    int cur = 0;
    num_filter_str = getDigit(s1, cur);
    std::cout << num_filter_str << std::endl;

    char ch = 'c';
    int ret = isalpha(ch);
    if (ret){
        std::cout << "isalpha ret = " << ret << "  --> " << ch << std::endl;
    }

    ch = '\v';
    ret = isspace(ch);
    if (ret) {
        std::cout << "isspace ret = " << ret << "  --> " << ch << std::endl;
    }

    ch = 'A';
    if (isupper(ch)) {
        ch = tolower(ch);
    }
    std::cout << "tolower result = " << ch << std::endl;

    ch = 'a';
    if (islower(ch)) {
        ch = toupper(ch);
    }
    std::cout << "toupper result = " << ch << std::endl;
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
