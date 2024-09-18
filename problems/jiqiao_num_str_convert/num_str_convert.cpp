#include <iostream>
#include <gtest/gtest.h>
#include <cstdio>

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

/* 整数转字符串 */
TEST(jiqiao_num_str_convert, t2)
{
    int num1 = 123456;
    char buffer[512] = {0};
    size_t buffer_size = sizeof(buffer);
    int str_len = _snprintf_s(buffer, buffer_size, buffer_size - 1,
                              "%5o", num1);
    if (str_len < 0) {
        return;
    }
    buffer_size -= str_len;
    printf("num : %d comnvert to string: %s \n", num1, buffer);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
