#include <iostream>
#include <gtest/gtest.h>

#include <string.h>

TEST(note_string, test1) {
    char* ABC = "ABC";
    size_t len = sizeof("ABC");
    printf("sizeof(\"123\") = %u\n", sizeof("ABC"));
}

TEST(note_string, test2) {
    char test[4];   // 声明字符数组
    test[0] = 'A';
    test[1] = 'B';
    test[2] = 'C';
    test[3] = '\0';   // 字符串结束标识。
    printf("test : %s \n", test);
}

TEST(note_string, test3) {
    char test1[4] = {0};   // 声明字符数组
    printf("test1 : %s \n", test1);

    char test2[4] = {'A', 'B', 'C', '\0'};
    printf("test2 : %s \n", test2);

    char test3[4] = "ABC";
    printf("test3 : %s \n", test3);

    char test4[4] = {"ABC"};
    printf("test4 : %s \n", test4);
}

TEST(note_string, test4) {
    char null_str1[] = "";   // 声明空字符串
    char null_str2[] = "\0";
    char null_str3[] = {'\0'}; // 等价于 null_str3[0] = '\0';
    char null_str4[6] = ""; // 数组的 6 个元素均被初始化为空字符。

    printf("null_str1 size = %u  str length = %u \n", sizeof(null_str1), strlen(null_str1));
    printf("null_str2 size = %u  str length = %u \n", sizeof(null_str2), strlen(null_str2));
    printf("null_str3 size = %u  str length = %u \n", sizeof(null_str3), strlen(null_str3));
    printf("null_str4 size = %u  str length = %u \n", sizeof(null_str4), strlen(null_str4));
}

/* 不可以赋给数组初始值，字符串也一样 */
TEST(note_string, test5) {
    char test1[4] = {'A', 'B', 'C', '\0'};
    printf("test1 : %s \n", test1);
//    test1 = {'B'};
}

/* 字符串不一定要装满数组的所有元素，也就是说，数组的元素个数可以大于包括空字符在内的字符数。 */
TEST(note_string, test6) {
    char test1[6] = {'A', 'B', 'C', '\0'};
    printf("test1 : %s \n", test1);
}
/* 字符串数组 */
TEST(note_string, test7) {
    char str1[][6] = {"abcd", "ef", "ghijk"};
    for (int i = 0; i < 3; ++i) {
        printf("str[%d] = %s \n", i, str1[i]);
    }
    // 3  * 6 = 18
    printf("sizeof(str1) = %u\n", sizeof(str1));

    char* p[] = {"abcd", "ef", "ghijk"};
    for (int i = 0; i < 3; ++i) {
        printf("p[%d] = %s \n", i, p[i]);
    }
    // 24 + 5 + 3 + 6 = 38
    printf("sizeof size = %u\n", sizeof(p) + sizeof("abcd") + sizeof("ef") + sizeof("ghijk"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
