#include "headers.h"

TEST(jiqiao, t1) {
    vector<int> nums {1, 2, 34, 44, 99};
    int k1 = lower_bound(nums.begin(), nums.end(), 56) - nums.begin();
    ASSERT_EQ(k1, 4);
    int k2 = lower_bound(nums.begin(), nums.end(), 56) - nums.begin();
    ASSERT_EQ(k2, 4);
}

// 字符串转整数
TEST(jiqiao, t2) {
    int num = 100;
    string str = to_string(num);  // 整形转字符串
    int number = stoi(str);       // 字符串转为整型 stoll()是字符串转长整型
}

// 小根堆
TEST(jiqiao, t3) {
    priority_queue<int> pq; // 默认大根堆
    priority_queue<int, vector<int>, greater<int>> pq2; // 小根堆
}

// 字符串分拆
TEST(jiqiao, t4) {
    string a = "12:59:36";
    char str2[100];
    memcpy(str2, a.c_str(), strlen(a.c_str()));
    int u, v, w;
    sscanf(str2, "%d:%d:%d", &u, &v, &w);
    cout << u << " " << v << " " << w << endl;
}

// 生成相同字符的字符串
TEST(jiqiao, t5) {
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
