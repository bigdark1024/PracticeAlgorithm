#include <iostream>
#include <gtest/gtest.h>
#include <stdlib.h>

using namespace std;

/* 整数转字符串 */
TEST(jiqiao_num_str_convert, t1)
{
    int num1 = 123456;
    int num2 = 10;
    char str[16] = {0};
    itoa(num1, str, 8);
    printf("num : %d comnvert to string: %s \n", num1, str);
    itoa(num2, str,2);
    printf("num : %d comnvert to string: %s \n", num2, str);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
