#include <iostream>
#include <bitset>
#include <cstdio>
#include <string>
#include <gtest/gtest.h>

using namespace std;

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


TEST(jiqiao_bit_convert, t4)
{
    /* 16进制转2进制 */
    int val1 = stoi("c000", nullptr, 16);
    bitset<16> bit1(val1); // 1100000000000000
    cout << bit1.to_string() << endl;

    /* 10进制转2进制 */
    int a2 = 10;
    bitset<4> bit2(a2);  // 1010
    cout << bit2.to_string() << endl;

    /* 2进制转10进制：第一种方法 */
    bitset<6> bit3('010101');
    int a3 = bit3.to_ulong(); // 49
    cout << a3 << endl;

    /* 2进制转10进制：第二种方法 */
    string bit4_str = "0101";
    int a4 = stoi(bit4_str);  // 101
    cout << a4 << endl;

    /* 10进制转字符串 */
    int a5 = 10;
    string str5 = std::to_string(a5); // 10
    cout << str5 << endl;

    /* 字符串转10进制 */
    string str6 = "123456";
    int val6 = stoi(str6); // 123456
    cout << val6 << endl;

    /* 字符串转16进制 */
    string str7 = "1A";
    int val7 = stoi(str7, nullptr, 16);  // 26
    cout << val7 << endl;

    /* 10进制转16进制 */
    int val8 = 26;
    string str8;
    stringstream ss8;
    ss8 << std::hex << val8;
    ss8 >> str8;

    std::transform(str8.begin(), str8.end(), str8.begin(), ::toupper);  // 1A
    cout << str8 << endl;

    // 2进制转16进制，先要把2进制转为10进制
    string binary = "1010";
    string hex_out;
    stringstream ss9;
    ss9 << std::hex << stoi(binary, nullptr, 2);
    ss9 >> hex_out;

    transform(hex_out.begin(), hex_out.end(), hex_out.begin(), ::toupper); // A
    cout << hex_out << endl;

    // 16进制转2进制
    string binary16_to_2 = "1B"; // 27用16进制表示为1B
    // 16进制先转10进制， 再通过bitset转2进制
    bitset<8> bit(stoi(binary16_to_2, nullptr, 16));  // 00011011
    cout << bit << endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
