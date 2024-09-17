#include <iostream>
#include <bitset>
#include <cstdio>
#include <gtest/gtest.h>

/* 字符串分割-string流方式 */
TEST(jiqiao_bit_convert, t1)
{
    int num = 10;
    printf("%d octal print: %05o\n", num, num);
    printf("%d decimal print: %03d\n", num, num);
    printf("%d hex print: %04x\n", num, num);

    std::cout <<" octal print: " << std::oct << num << std::endl;
    std::cout <<" decimal print: " << std::dec << num << std::endl;
    std::cout <<" hex print: " << std::hex << num << std::endl;
    std::cout <<" binary print: " << std::bitset<8>(num) << std::endl;
}

/* ASCII to integer */
TEST(jiqiao_bit_convert, t2)
{
//    对应于成功转换进制的内容是str的整数值
//    如果无法执行转换，则返回0
    printf("%i\n", atoi(" -123junk"));
    printf("%i\n", atoi(" +321dust"));
    printf("%i\n", atoi("0"));
    printf("%i\n", atoi("0042")); // treated as a decimal number with leading zeros
    printf("%i\n", atoi("0x2A")); // only leading zero is converted discarding "x2A"
    printf("%i\n", atoi("junk")); // no conversion can be performed
    printf("%i\n", atoi("2147483648")); // UB: out of range of int
    printf("\"123456\" convert to interger num：%d\n",atoi("123456"));
    printf("\"-123456\" convert to interger num：%d\n",atoi("-123456"));
}

/* strtol */
TEST(jiqiao_bit_convert, t3)
{
    char buffer[20]="20549stend#12";
    char *stop;
    int ans = strtol(buffer, &stop, 8);   //将八进制数1054转成十进制，后面均为非法字符
    printf("%d\n",ans); // 556
    printf("%s\n", stop); // 9stend#12
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
