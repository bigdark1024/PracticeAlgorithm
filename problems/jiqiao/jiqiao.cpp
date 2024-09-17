#include <iostream>
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <sstream>

using namespace std;

TEST(jiqiao, t1)
{
    vector<int> nums {1, 2, 34, 44, 99};
    int k1 = lower_bound(nums.begin(), nums.end(), 56) - nums.begin();
    ASSERT_EQ(k1, 4);
    int k2 = lower_bound(nums.begin(), nums.end(), 56) - nums.begin();
    ASSERT_EQ(k2, 4);
}

// 字符串转整数
TEST(jiqiao, t2)
{
    int num = 100;
    string str = to_string(num);  // 整形转字符串
    int number = stoi(str);       // 字符串转为整型 stoll()是字符串转长整型
}

// 小根堆
TEST(jiqiao, t3)
{
    priority_queue<int> pq; // 默认大根堆
    priority_queue<int, vector<int>, greater<int>> pq2; // 小根堆
}

// 字符串分拆
TEST(jiqiao, t4)
{
    string a = "12:59:36";
    char str2[100];
    memcpy(str2, a.c_str(), strlen(a.c_str()));
    int u, v, w;
    sscanf(str2, "%d:%d:%d", &u, &v, &w);
    cout << u << " " << v << " " << w << endl;
}

// 生成相同字符的字符串
TEST(jiqiao, t5)
{
    string s(10, 'a');
    cout << s << endl;
}

// 结构体排序
//TEST(jiqiao, t6) {
//    struct node {
//        int a, b;
//        // 从小到大排序
//        bool operator <;
//    };
//}

TEST(jiqiao, t6)
{
    unsigned short a = 9;    // 补码 00001001
    int b = ~a;
    cout  << b << endl; // prints -10
}

TEST(jiqiao, t7)
{
    int8_t x = 0b00001011;
    x = x << 6;
    if (x < 0) {
        cout << "Negtive.";
    }
}

TEST(jiqiao, t8)
{
    unsigned int num = 44; // 二进制表示为 0010 1100
    int shiftAmount = 2;   // 要右移的位数

    unsigned int result = num >> shiftAmount;  //  result = 0000 1011

    std::cout << "原始数值（二进制）: " << std::bitset<8>(num) << std::endl;
    std::cout << "右移后的数值（二进制）: " << std::bitset<8>(result) << std::endl;
}

/* 字符串分割-string流方式 */
TEST(jiqiao, t9)
{
    std::string str("Hello World Let's Do Someting Fun");
    std::stringstream ss(str);
    std::string temp;
    const char cc = ' ';
    while (std::getline(ss, temp, cc)) {
        std::cout << " " << temp << std::endl;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
